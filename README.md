# Gesture_Detection_v0.2
Improvement &amp; generalization of the Sign language detection project
## Coding Environment
It is definately suggested that we use VSCode for the production of this project.
The [PlatformIO](https://platformio.org/install/ide?install=vscode). extension to VSCode is a life saver, it greatly reduces dependency management and is a lot faster. Also other tools like Co-Pilot integrates well enought to help up with the projects.
## Data Transmission
There are majorly two program files involved here:
<rename>.cpp for uploading to the ESP Module. Acts as the I/O betweeen the sensors. POSTs data into the required IP & port (server).
<rename.py for GET-ing the data by hosting a server to receive the POSTed values
just upload the .cpp file to the ESP used in the glove. Make sure you set the required SSID, password, IP, port in the code before uploading. The SSID/password/IP is of the hotspot providing system. Again the IP/port[serverURL] should be matching in both the .cpp and the .py file.
When the .py file is run, the obtained data is stored as a text file in the samee document. The .py file incorporates Flask which is a web framework that can handle HTTP requests and route URL's to specific funtions.
