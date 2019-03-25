Part 1: Orientation and Setup
    * Set up your Docker environment 
    * Build an image and run it as one container
    * Scale your app to run multiple containers
    * Distribute your app across a cluster
    * Stack services by adding a backend database
    * Deploy your app to production
    
    Docker Concepts
        Docker is a platform for developers and sysadmins to develop, deploy, 
        and run applications with containers. The use of Linux containers to 
        deploy applications is called containerization. Containers are not new, 
        but their use for easily deploying applications is.
        
        Containerization is increasingly popular because containers are:

            * Flexible: Even the most complex applications can be containerized.
            * Lightweight: Containers leverage and share the host kernel.
            * Interchangeable: You can deploy updates and upgrades on-the-fly.
            * Portable: You can build locally, deploy to the cloud, and run anywhere.
            * Scalable: You can increase and automatically distribute container replicas.
            * Stackable: You can stack services vertically and on-the-fly.
            
    Images and Containers
        A "container" is launched by running an image. An "image" is an executable 
        package that includes everything needed to run an application–the code, 
        a runtime, libraries, environment variables, and configuration files.
        
        A "container" is a runtime instance of an image–what the image becomes in 
        memory when executed (that is, an image with state, or a user process). 
        You can see a list of your running containers with the command, '$docker ps', 
        just as you would in Linux.
        
        A container runs natively on Linux and shares the kernel of the host machine 
        with other containers. It runs a discrete process, taking no more memory than 
        any other executable, making it lightweight.
        
        By contrast, a "virtual machine (VM)" runs a full-blown “guest” operating system 
        with virtual access to host resources through a hypervisor. In general, VMs 
        provide an environment with more resources than most applications need.
        
    Prepare Your Docker Container
        Install a maintained version of Docker Community Edition (CE) or Enterprise 
        Edition (EE) on a supported platform.
        
        Test Docker version
            1. Run `docker --version` and ensure that you have a supported version 
            of Dcoker:

                $docker --version

                Docker version 17.12.0-ce, build c97c6d6
            
            2. Run `docker info` or (`docker version` without `--`) to view 
            even more details about your docker installation:
                
                $docker info

                Containers: 0
                 Running: 0
                 Paused: 0
                 Stopped: 0
                Images: 0
                Server Version: 17.12.0-ce
                Storage Driver: overlay2
                ...
                
            3. List the images that was downloaded to your machine:
                `docker image ls`
               
            4. To list all the containers (even those that are still running) 
            use the following command:
                `docker container ls --all`
        
    Recap and Cheat Sheet
        
        ## List Docker CLI commands
        docker
        docker container --help

        ## Display Docker version and info
        docker --version
        docker version
        docker info

        ## Execute Docker image
        docker run image

        ## List Docker images
        docker image ls

        ## List Docker containers (running, all, all in quiet mode)
        docker container ls
        docker container ls --all
        docker container ls -aq
        
    Conclusion of Part One
        Containerization makes Continuous Integration/Continuous Development 
        (CI/CD) seamless. For example:
            * applications have no system dependencies
            * updates can be pushed to any part of a distributed application
            * resource density can be optimized.
       
       With Docker, scaling your application is a matter of spinning up new executables, 
       not running heavy VM hosts.
       
     
Part 2: Containers
    Introduction
        It’s time to begin building an app the Docker way. We start at the bottom of 
        the hierarchy of such an app, which is a container, which we cover in this part. 
        Above this level is a service, which defines how containers behave in production, 
        covered in Part 3. Finally, at the top level is the stack, defining the interactions 
        of all the services, covered in Part 5.

            * Stack
            * Services
            * Container (you are here)
    
    Your New Development Enviornment
        In the past, if you were to start writing a Python app, your first order of business 
        was to install a Python runtime onto your machine. But, that creates a situation where 
        the environment on your machine needs to be perfect for your app to run as expected, 
        and also needs to match your production environment.

        With Docker, you can just grab a portable Python runtime as an image, no installation 
        necessary. Then, your build can include the base Python image right alongside your app 
        code, ensuring that your app, its dependencies, and the runtime, all travel together.

        These portable images are defined by something called a "Dockerfile".   

    Define a Container With Dockerfile
        Dockerfile defines what goes on in the environment inside your container. Access to 
        resources like networking interfaces and disk drives is virtualized inside this environment, 
        which is isolated from the rest of your system, so you need to map ports to the outside world, 
        and be specific about what files you want to “copy in” to that environment. However, after doing 
        that, you can expect that the build of your app defined in this Dockerfile behaves exactly the 
        same wherever it runs.

    Dockerfile
        Create an empty directory. Change directories (cd) into the new directory, create a file called 
        Dockerfile, copy-and-paste the following content into that file, and save it. Take note of the 
        comments that explain each statement in your new Dockerfile.
        
            # Use an official Python runtime as a parent image
            FROM python:2.7-slim

            # Set the working directory to /app
            WORKDIR /app

            # Copy the current directory contents into the container at /app
            ADD . /app

            # Install any needed packages specified in requirements.txt
            RUN pip install --trusted-host pypi.python.org -r requirements.txt

            # Make port 80 available to the world outside this container
            EXPOSE 80

            # Define environment variable
            ENV NAME World

            # Run app.py when the container launches
            CMD ["python", "app.py"]      
            
        - Are you behind a proxy server?
            Proxy servers can block connections to your web app once it’s up and running. If you are 
            behind a proxy server, add the following lines to your Dockerfile, using the `ENV` command 
            to specify the host and port for your proxy servers:
            
                # Set proxy server, replace host:port with values for your servers
                ENV http_proxy host:port
                ENV https_proxy host:port

            Add these lines before the call to `pip` so that installation succeeds.
            
        This Dockerfile refers to a couple of files we haven’t created yet, namely app.py and requirements.txt. 
        Let’s create those next.
    
    The App Itself
        Create two more files, requirements.txt and app.py, and put them in the same folder with the Dockerfile. 
        This completes our app, which as you can see is quite simple. When the above Dockerfile is built into 
        an image, app.py and requirements.txt is present because of that Dockerfile’s `ADD` command, and the 
        output from app.py is accessible over HTTP thanks to the `EXPOSE` command.
        
            requirements.txt
                
                Flask
                Redis
                
            app.py
                '''python2
                from flask import Flask
                from redis import Redis, RedisError
                import os
                import socket

                # Connect to Redis
                redis = Redis(host="redis", db=0, socket_connect_timeout=2, socket_timeout=2)

                app = Flask(__name__)

                @app.route("/")
                def hello():
                    try:
                        visits = redis.incr("counter")
                    except RedisError:
                        visits = "<i>cannot connect to Redis, counter disabled</i>"

                    html = "<h3>Hello {name}!</h3>" \
                           "<b>Hostname:</b> {hostname}<br/>" \
                           "<b>Visits:</b> {visits}"
                    return html.format(name=os.getenv("NAME", "world"), hostname=socket.gethostname(), visits=visits)

                if __name__ == "__main__":
                    app.run(host='0.0.0.0', port=80)
                '''

        
