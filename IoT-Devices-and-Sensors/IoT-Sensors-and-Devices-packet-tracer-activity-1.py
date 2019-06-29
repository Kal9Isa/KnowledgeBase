from gpio import *	                        # Imports all modules in the GPIO library
from time import *	                        # Imports all modules in the time library

switchValue = 0					            # Initialize sensor values to 0
togglePushButtonValue = 0
potentiometerValue = 0
flexSensorValue = 0

def readFromSensors():
    global switchValue 				        # Declare values as global
    global togglePushButtonValue
    global potentiometerValue
    global flexSensorValue

    switchValue = digitalRead(0)            # Read sensor values from corresponding pins
    togglePushButtonValue = digitalRead(1)
    potentiometerValue = analogRead(A0)
    flexSensorValue = analogRead(A1)

def writeToActuators():
    if (switchValue == HIGH):               # Evaluates to True if the sensor value is HIGH
        customWrite(2,1)                    # Turn on the light on pin D2
    else:
        customWrite(2,0)

    if (togglePushButtonValue == HIGH):
        digitalWrite(3,HIGH)                # Turn on the LED on pin D3
    else:
        digitalWrite(3,LOW)

    if (potentiometerValue > 512):          # Evaluates to True if the potentiometer is at least halfway turned
        customWrite(4, HIGH)                # Turn on the siren
    else:
        customWrite(4,LOW)

    if (flexSensorValue > 0):               # Evaluates to True if the Flex sensor is bent
        analogWrite(5, flexSensorValue)     # Turn on Motor with speed equal to the Flex sensor value
    else:
        analogWrite(5,0)

def main():                                 # Main function
    pinMode(0, IN)                          # Sets digital slot 0 to input, Switch
    pinMode(1, IN)                          # Sets digital slot 1 to input, Toggle Push Button
    pinMode(2, OUT)                         # Sets digital slot 2 to output, Light
    pinMode(3, OUT)                         # Sets digital slot 3 to output, LED
    pinMode(4, OUT)                         # Sets digital slot 4 to output, Siren
    pinMode(5,OUT)                          # Sets digital slot 5 to output, Motor

    while True:                             # Loop indifinitely
            readFromSensors()
            writeToActuators()
            delay(1000)                     # Delay for 1s

if __name__ == "__main__":                  # Evaluates to True if this module is the script being executed, otherwise False if it's being imported.
    main()
