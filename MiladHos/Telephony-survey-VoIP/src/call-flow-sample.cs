using CallFlow.CFD;
using CallFlow;
using MimeKit;
using System.Collections.Generic;
using System.IO;
using System.Threading.Tasks.Dataflow;
using System.Threading.Tasks;
using System.Threading;
using System;
using TCX.Configuration;

namespace DatabaseAccessDemo
{
    public class Main : ScriptBase<Main>, ICallflow, ICallflowProcessor
    {
        private bool executionStarted;
        private bool executionFinished;

        private BufferBlock<AbsEvent> eventBuffer;

        private int currentComponentIndex;
        private List<AbsComponent> mainFlowComponentList;
        private List<AbsComponent> disconnectFlowComponentList;
        private List<AbsComponent> errorFlowComponentList;
        private List<AbsComponent> currentFlowComponentList;

        private LogFormatter logFormatter;
        private TimerManager timerManager;
        private Dictionary<string, Variable> variableMap;
        private TempWavFileManager tempWavFileManager;
        private PromptQueue promptQueue;

        private void DisconnectCallAndExitCallflow()
        {
            logFormatter.Trace("Callflow finished, disconnecting call...");
            MyCall.Terminate();
        }

        private async Task ExecuteErrorFlow()
        {
            if (currentFlowComponentList == errorFlowComponentList)
            {
                logFormatter.Trace("Error during error handler flow, exiting callflow...");
                DisconnectCallAndExitCallflow();
            }
            else
            {
                currentFlowComponentList = errorFlowComponentList;
                currentComponentIndex = 0;
                if (errorFlowComponentList.Count > 0)
                {
                    logFormatter.Trace("Start executing error handler flow...");
                    await ProcessStart();
                }
                else
                {
                    logFormatter.Trace("Error handler flow is empty...");
                    DisconnectCallAndExitCallflow();
                }
            }
        }

        private EventResults CheckEventResult(EventResults eventResult)
        {
            if (eventResult == EventResults.MoveToNextComponent && ++currentComponentIndex == currentFlowComponentList.Count)
            {
                DisconnectCallAndExitCallflow();
                return EventResults.Exit;
            }
            else if (eventResult == EventResults.Exit)
                DisconnectCallAndExitCallflow();

            return eventResult;
        }

        private void InitializeVariables(string callID)
        {
            // Call variables
            variableMap["session.ani"] = new Variable(MyCall.Caller.CallerID);
            variableMap["session.callid"] = new Variable(callID);
            variableMap["session.dnis"] = new Variable(MyCall.DN.Number);
            variableMap["session.did"] = new Variable(MyCall.Caller.CalledNumber);
            variableMap["session.audioFolder"] = new Variable(Path.Combine(RecordingManager.Instance.AudioFolder, promptQueue.ProjectAudioFolder));
            variableMap["session.transferingExtension"] = new Variable(MyCall["onbehlfof"] ?? string.Empty);

            // Standard variables
            variableMap["RecordResult.NothingRecorded"] = new Variable(RecordComponent.RecordResults.NothingRecorded);
            variableMap["RecordResult.StopDigit"] = new Variable(RecordComponent.RecordResults.StopDigit);
            variableMap["RecordResult.Completed"] = new Variable(RecordComponent.RecordResults.Completed);
            variableMap["MenuResult.Timeout"] = new Variable(MenuComponent.MenuResults.Timeout);
            variableMap["MenuResult.InvalidOption"] = new Variable(MenuComponent.MenuResults.InvalidOption);
            variableMap["MenuResult.ValidOption"] = new Variable(MenuComponent.MenuResults.ValidOption);
            variableMap["UserInputResult.Timeout"] = new Variable(UserInputComponent.UserInputResults.Timeout);
            variableMap["UserInputResult.InvalidDigits"] = new Variable(UserInputComponent.UserInputResults.InvalidDigits);
            variableMap["UserInputResult.ValidDigits"] = new Variable(UserInputComponent.UserInputResults.ValidDigits);

            // User variables
            variableMap["RecordResult.NothingRecorded"] = new Variable(RecordComponent.RecordResults.NothingRecorded);
            variableMap["RecordResult.StopDigit"] = new Variable(RecordComponent.RecordResults.StopDigit);
            variableMap["RecordResult.Completed"] = new Variable(RecordComponent.RecordResults.Completed);
            variableMap["MenuResult.Timeout"] = new Variable(MenuComponent.MenuResults.Timeout);
            variableMap["MenuResult.InvalidOption"] = new Variable(MenuComponent.MenuResults.InvalidOption);
            variableMap["MenuResult.ValidOption"] = new Variable(MenuComponent.MenuResults.ValidOption);
            variableMap["UserInputResult.Timeout"] = new Variable(UserInputComponent.UserInputResults.Timeout);
            variableMap["UserInputResult.InvalidDigits"] = new Variable(UserInputComponent.UserInputResults.InvalidDigits);
            variableMap["UserInputResult.ValidDigits"] = new Variable(UserInputComponent.UserInputResults.ValidDigits);
            
        }

        private void InitializeComponents(ICallflow callflow, ICall myCall, string logHeader)
        {
            {
            PromptPlaybackComponent PromptPlayback1 = new PromptPlaybackComponent("PromptPlayback1", callflow, myCall, logHeader);
            PromptPlayback1.AllowDtmfInput = true;
            PromptPlayback1.Prompts.Add(new AudioFilePrompt(() => { return "1-Greeting.wav"; }));
            mainFlowComponentList.Add(PromptPlayback1);
            UserInputComponent requestNID = new UserInputComponent("requestNID", callflow, myCall, logHeader);
            requestNID.AllowDtmfInput = false;
            requestNID.MaxRetryCount = 3;
            requestNID.FirstDigitTimeout = 5000;
            requestNID.InterDigitTimeout = 5000;
            requestNID.FinalDigitTimeout = 5000;
            requestNID.MinDigits = 10;
            requestNID.MaxDigits = 10;
            requestNID.ValidDigitList.AddRange(new char[] { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' });
            requestNID.StopDigitList.AddRange(new char[] { '#' });
            requestNID.InitialPrompts.Add(new AudioFilePrompt(() => { return "2-GetIDCode.wav"; }));
            requestNID.TimeoutPrompts.Add(new AudioFilePrompt(() => { return "3-InputTimeout.wav"; }));
            mainFlowComponentList.Add(requestNID);
            ConditionalComponent requestNID_Conditional = new ConditionalComponent("requestNID_Conditional", callflow, myCall, logHeader);
            mainFlowComponentList.Add(requestNID_Conditional);
            requestNID_Conditional.ConditionList.Add(() => { return requestNID.Result == UserInputComponent.UserInputResults.ValidDigits; });
            requestNID_Conditional.ContainerList.Add(new SequenceContainerComponent("requestNID_Conditional_ValidInput", callflow, myCall, logHeader));
            MySqlDatabaseAccessComponent ValidateNID = new MySqlDatabaseAccessComponent("ValidateNID", callflow, myCall, logHeader);
            ValidateNID.ServerHandler = () => { return Convert.ToString("195.201.24.216"); };
            ValidateNID.PortHandler = () => { return Convert.ToInt32(3306); };
            ValidateNID.DatabaseHandler = () => { return Convert.ToString("patients"); };
            ValidateNID.UserNameHandler = () => { return Convert.ToString("voip-test"); };
            ValidateNID.PasswordHandler = () => { return Convert.ToString("2022Voip!((^"); };
            ValidateNID.Parameters.Add(new CallFlow.CFD.Parameter("nid", () => { return requestNID.Buffer; }));
            ValidateNID.UseConnectionString = false;
            ValidateNID.SqlStatement = @"SELECT count(*) FROM patients WHERE patient_id={0}";
            ValidateNID.StatementType = DatabaseAccessComponent.StatementTypes.Scalar;
            ValidateNID.Timeout = 30000;
            requestNID_Conditional.ContainerList[0].ComponentList.Add(ValidateNID);
            ConditionalComponent ValidateDatabaseResult = new ConditionalComponent("ValidateDatabaseResult", callflow, myCall, logHeader);
            requestNID_Conditional.ContainerList[0].ComponentList.Add(ValidateDatabaseResult);
            ValidateDatabaseResult.ConditionList.Add(() => { return Convert.ToBoolean(CFDFunctions.EQUAL(ValidateNID.ScalarResult,1)); });
            ValidateDatabaseResult.ContainerList.Add(new SequenceContainerComponent("ValidateDatabaseResult_0", callflow, myCall, logHeader));
            PromptPlaybackComponent PlaySuccess = new PromptPlaybackComponent("PlaySuccess", callflow, myCall, logHeader);
            PlaySuccess.AllowDtmfInput = true;
            PlaySuccess.Prompts.Add(new AudioFilePrompt(() => { return "4-DBValidAnnouncement.wav"; }));
            ValidateDatabaseResult.ContainerList[0].ComponentList.Add(PlaySuccess);
            ValidateDatabaseResult.ConditionList.Add(() => { return Convert.ToBoolean(true); });
            ValidateDatabaseResult.ContainerList.Add(new SequenceContainerComponent("ValidateDatabaseResult_1", callflow, myCall, logHeader));
            PromptPlaybackComponent PlayInvalidID = new PromptPlaybackComponent("PlayInvalidID", callflow, myCall, logHeader);
            PlayInvalidID.AllowDtmfInput = true;
            PlayInvalidID.Prompts.Add(new AudioFilePrompt(() => { return "4-DBCheckInvalid.wav"; }));
            ValidateDatabaseResult.ContainerList[1].ComponentList.Add(PlayInvalidID);
            requestNID_Conditional.ConditionList.Add(() => { return requestNID.Result == UserInputComponent.UserInputResults.InvalidDigits || requestNID.Result == UserInputComponent.UserInputResults.Timeout; });
            requestNID_Conditional.ContainerList.Add(new SequenceContainerComponent("requestNID_Conditional_InvalidInput", callflow, myCall, logHeader));
            PromptPlaybackComponent PromptPlayback2 = new PromptPlaybackComponent("PromptPlayback2", callflow, myCall, logHeader);
            PromptPlayback2.AllowDtmfInput = true;
            PromptPlayback2.Prompts.Add(new AudioFilePrompt(() => { return "3-InvalidInput.wav"; }));
            requestNID_Conditional.ContainerList[1].ComponentList.Add(PromptPlayback2);
            }
            {
            }
            {
            }
            

            // Add a final DisconnectCall component to the main and error handler flows, in order to complete pending prompt playbacks...
            DisconnectCallComponent mainAutoAddedFinalDisconnectCall = new DisconnectCallComponent("mainAutoAddedFinalDisconnectCall", callflow, myCall, logHeader);
            DisconnectCallComponent errorHandlerAutoAddedFinalDisconnectCall = new DisconnectCallComponent("errorHandlerAutoAddedFinalDisconnectCall", callflow, myCall, logHeader);
            mainFlowComponentList.Add(mainAutoAddedFinalDisconnectCall);
            errorFlowComponentList.Add(errorHandlerAutoAddedFinalDisconnectCall);
        }

        private bool IsServerOfficeHourActive(ICall myCall)
        {
            DateTime nowDt = DateTime.Now;
            Tenant tenant = myCall.PS.GetTenant();
            if (tenant == null || tenant.IsHoliday(new DateTimeOffset(nowDt)))
                return false;

            Schedule officeHours = tenant.Hours;
            Nullable<bool> result = officeHours.IsActiveTime(nowDt);
            return result.GetValueOrDefault(false);
        }

        public Main()
        {
            this.executionStarted = false;
            this.executionFinished = false;

            this.eventBuffer = new BufferBlock<AbsEvent>();

            this.currentComponentIndex = 0;
            this.mainFlowComponentList = new List<AbsComponent>();
            this.disconnectFlowComponentList = new List<AbsComponent>();
            this.errorFlowComponentList = new List<AbsComponent>();
            this.currentFlowComponentList = mainFlowComponentList;

            this.timerManager = new TimerManager();
            this.timerManager.OnTimeout += (state) => eventBuffer.Post(new TimeoutEvent(state));
            this.variableMap = new Dictionary<string, Variable>();
        }

        public override void Start()
        {
            string callID = MyCall?.Caller["chid"] ?? "Unknown";
            string logHeader = $"DatabaseAccessDemo - CallID {callID}";
            this.logFormatter = new LogFormatter(MyCall, logHeader, "Callflow");
            this.promptQueue = new PromptQueue(this, MyCall, "DatabaseAccessDemo", logHeader);
            this.tempWavFileManager = new TempWavFileManager(logFormatter);

            InitializeComponents(this, MyCall, logHeader);
            InitializeVariables(callID);
            
            MyCall.SetBackgroundAudio(false, new string[] { });
            MyCall.OnTerminated += () => eventBuffer.Post(new CallTerminatedEvent());
            MyCall.OnDTMFInput += x => eventBuffer.Post(new DTMFReceivedEvent(x));

            logFormatter.Trace("Start executing main flow...");
            eventBuffer.Post(new StartEvent());
            Task.Run(() => EventProcessingLoop());

            
        }
        
        public void PostStartEvent()
        {
            eventBuffer.Post(new StartEvent());
        }

        public void PostDTMFReceivedEvent(char digit)
        {
            eventBuffer.Post(new DTMFReceivedEvent(digit));
        }

        public void PostPromptPlayedEvent()
        {
            eventBuffer.Post(new PromptPlayedEvent());
        }

        public void PostTransferFailedEvent()
        {
            eventBuffer.Post(new TransferFailedEvent());
        }

        public void PostMakeCallResultEvent(bool result)
        {
            eventBuffer.Post(new MakeCallResultEvent(result));
        }

        public void PostCallTerminatedEvent()
        {
            eventBuffer.Post(new CallTerminatedEvent());
        }

        public void PostTimeoutEvent(object state)
        {
            eventBuffer.Post(new TimeoutEvent(state));
        }

        private async Task EventProcessingLoop()
        {
            executionStarted = true;
            while (!executionFinished)
            {
                AbsEvent evt = await eventBuffer.ReceiveAsync();
                await evt?.ProcessEvent(this);
            }
        }
        
        public async Task ProcessStart()
        {
            try
            {
                EventResults eventResult;
                do
                {
                    AbsComponent currentComponent = currentFlowComponentList[currentComponentIndex];
                    logFormatter.Trace("Start executing component '" + currentComponent.Name + "'");
                    eventResult = await currentComponent.Start(timerManager, variableMap, tempWavFileManager, promptQueue);
                }
                while (CheckEventResult(eventResult) == EventResults.MoveToNextComponent);
            }
            catch (Exception exc)
            {
                logFormatter.Error("Error executing last component: " + exc.ToString());
                await ExecuteErrorFlow();
            }
        }

        public async Task ProcessDTMFReceived(char digit)
        {
            try
            {
                AbsComponent currentComponent = currentFlowComponentList[currentComponentIndex];
                logFormatter.Trace("OnDTMFReceived for component '" + currentComponent.Name + "' - Digit: '" + digit + "'");
                EventResults eventResult = await currentComponent.OnDTMFReceived(timerManager, variableMap, tempWavFileManager, promptQueue, digit);
                if (CheckEventResult(eventResult) == EventResults.MoveToNextComponent)
                    await ProcessStart();
            }
            catch (Exception exc)
            {
                logFormatter.Error("Error executing last component: " + exc.ToString());
                await ExecuteErrorFlow();
            }
        }

        public async Task ProcessPromptPlayed()
        {
            try
            {
                promptQueue.NotifyPlayFinished();
                AbsComponent currentComponent = currentFlowComponentList[currentComponentIndex];
                logFormatter.Trace("OnPromptPlayed for component '" + currentComponent.Name + "'");
                EventResults eventResult = await currentComponent.OnPromptPlayed(timerManager, variableMap, tempWavFileManager, promptQueue);
                if (CheckEventResult(eventResult) == EventResults.MoveToNextComponent)
                    await ProcessStart();
            }
            catch (Exception exc)
            {
                logFormatter.Error("Error executing last component: " + exc.ToString());
                await ExecuteErrorFlow();
            }
        }

        public async Task ProcessTransferFailed()
        {
            try
            {
                AbsComponent currentComponent = currentFlowComponentList[currentComponentIndex];
                logFormatter.Trace("OnTransferFailed for component '" + currentComponent.Name + "'");
                EventResults eventResult = await currentComponent.OnTransferFailed(timerManager, variableMap, tempWavFileManager, promptQueue);
                if (CheckEventResult(eventResult) == EventResults.MoveToNextComponent)
                    await ProcessStart();
            }
            catch (Exception exc)
            {
                logFormatter.Error("Error executing last component: " + exc.ToString());
                await ExecuteErrorFlow();
            }
        }

        public async Task ProcessMakeCallResult(bool result)
        {
            try
            {
                AbsComponent currentComponent = currentFlowComponentList[currentComponentIndex];
                logFormatter.Trace("OnMakeCallResult for component '" + currentComponent.Name + "' - Result: '" + result + "'");
                EventResults eventResult = await currentComponent.OnMakeCallResult(timerManager, variableMap, tempWavFileManager, promptQueue, result);
                if (CheckEventResult(eventResult) == EventResults.MoveToNextComponent)
                    await ProcessStart();
            }
            catch (Exception exc)
            {
                logFormatter.Error("Error executing last component: " + exc.ToString());
                await ExecuteErrorFlow();
            }
        }

        public async Task ProcessCallTerminated()
        {
            try
            {
                if (executionStarted)
                {
                    // First notify the current component
                    AbsComponent currentComponent = currentFlowComponentList[currentComponentIndex];
                    logFormatter.Trace("OnCallTerminated for component '" + currentComponent.Name + "'");
                    await currentComponent.OnCallTerminated(timerManager, variableMap, tempWavFileManager, promptQueue);

                    // Next, execute disconnect flow
                    currentFlowComponentList = disconnectFlowComponentList;
                    logFormatter.Trace("Start executing disconnect handler flow...");
                    foreach (AbsComponent component in disconnectFlowComponentList)
                    {
                        logFormatter.Trace("Start executing component '" + component.Name + "'");
                        await component.Start(timerManager, variableMap, tempWavFileManager, promptQueue);
                    }
                }
            }
            catch (Exception exc)
            {
                logFormatter.Error("Error executing last component: " + exc.ToString());
                await ExecuteErrorFlow();
            }
            finally
            {
                // Finally, delete temporary files
                tempWavFileManager.DeleteFilesAndFolders();
                executionFinished = true;
            }
        }

        public async Task ProcessTimeout(object state)
        {
            try
            {
                AbsComponent currentComponent = currentFlowComponentList[currentComponentIndex];
                logFormatter.Trace("OnTimeout for component '" + currentComponent.Name + "'");
                EventResults eventResult = await currentComponent.OnTimeout(timerManager, variableMap, tempWavFileManager, promptQueue, state);
                if (CheckEventResult(eventResult) == EventResults.MoveToNextComponent)
                    await ProcessStart();
            }
            catch (Exception exc)
            {
                logFormatter.Error("Error executing last component: " + exc.ToString());
                await ExecuteErrorFlow();
            }
        }


        public class TcxSetExtensionStatusTempComponent : AbsComponent
        {
            private StringExpressionHandler extensionHandler = null;
            private StringExpressionHandler profileNameHandler = null;

            public TcxSetExtensionStatusTempComponent(string name, ICallflow callflow, ICall myCall, string logHeader) : base(name, callflow, myCall, logHeader)
            {
            }

            public string Extension { get; set; } = string.Empty;
            public string ProfileName { get; set; } = string.Empty;

            public StringExpressionHandler ExtensionHandler
            {
                set { extensionHandler = value; }
            }

            public StringExpressionHandler ProfileNameHandler
            {
                set { profileNameHandler = value; }
            }

            private EventResults ExecuteStart()
            {
                if (extensionHandler != null) Extension = extensionHandler();
                if (profileNameHandler != null) ProfileName = profileNameHandler();

                using (DN dn = myCall.PS.GetDNByNumber(Extension))
                {
                    if (!(dn is Extension ext)) throw new Exception("Extension '" + Extension + "' could not be found.");

                    logFormatter.Trace("Setting status for Extension='" + Extension + "' to '" + ProfileName + "'");

                    // Activate the selected profile
                    bool profileFound = false;
                    foreach (FwdProfile profile in ext.FwdProfiles)
                    {
                        if (profile.Name == ProfileName)
                        {
                            ext.CurrentProfile = profile;
                            profileFound = true;
                            break;
                        }
                    }

                    if (profileFound)
                    {
                        // And disable override if active
                        if (ext.IsOverrideActiveNow) ext.OverrideExpiresAt = DateTime.UtcNow;
                        logFormatter.Trace("Status for Extension='" + Extension + "' updated.");
                        ext.Save();
                    }
                    else
                        logFormatter.Trace("Status for Extension='" + Extension + "' could not be updated, profile name not found.");
                }
                return EventResults.MoveToNextComponent;
            }

            public override Task<EventResults> Start(Dictionary<string, Variable> variableMap)
            {
                return Task.FromResult(ExecuteStart());
            }

            public override Task<EventResults> Start(TimerManager timerManager, Dictionary<string, Variable> variableMap, TempWavFileManager tempWavFileManager, PromptQueue promptQueue)
            {
                return Task.FromResult(ExecuteStart());
            }

            public override Task<EventResults> OnDTMFReceived(TimerManager timerManager, Dictionary<string, Variable> variableMap, TempWavFileManager tempWavFileManager, PromptQueue promptQueue, char digit)
            {
                return IgnoreDTMFReceivedEventWithResult(digit, EventResults.MoveToNextComponent);
            }

            public override Task<EventResults> OnPromptPlayed(TimerManager timerManager, Dictionary<string, Variable> variableMap, TempWavFileManager tempWavFileManager, PromptQueue promptQueue)
            {
                return IgnoreEventWithResult("OnPromptPlayed", EventResults.MoveToNextComponent);
            }

            public override Task<EventResults> OnTransferFailed(TimerManager timerManager, Dictionary<string, Variable> variableMap, TempWavFileManager tempWavFileManager, PromptQueue promptQueue)
            {
                return IgnoreEventWithResult("OnTransferFailed", EventResults.MoveToNextComponent);
            }

            public override Task<EventResults> OnMakeCallResult(TimerManager timerManager, Dictionary<string, Variable> variableMap, TempWavFileManager tempWavFileManager, PromptQueue promptQueue, bool result)
            {
                return IgnoreMakeCallResult(result, EventResults.MoveToNextComponent);
            }

            public override Task<EventResults> OnCallTerminated(TimerManager timerManager, Dictionary<string, Variable> variableMap, TempWavFileManager tempWavFileManager, PromptQueue promptQueue)
            {
                return ProcessEventWithResult("OnCallTerminated", EventResults.MoveToNextComponent);
            }

            public override Task<EventResults> OnTimeout(TimerManager timerManager, Dictionary<string, Variable> variableMap, TempWavFileManager tempWavFileManager, PromptQueue promptQueue, object state)
            {
                return IgnoreEventWithResult("OnTimeout", EventResults.MoveToNextComponent);
            }
        }


        
    }
}
