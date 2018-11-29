# ReceiverCode
## Step1 
Compile cpp files

 `$ g++ -g -std=gnu++0x -o pip_sense.v2 pip_sense_layer.v2.cpp -lusb`
 
 How to run it:
 
 `$ sudo stdbuf -o0 ./pip_sense.v2 l l | stdbuf -o0 grep TX:03408`
 
 ## Step2
 Activate HTTP Server
 
 `$ sh ./flask_debug_sh`
 
 ## Step3
 Run fetch script
 
 `$ python3 fetch.py`
 
 ## Step4
 Go to `http://localhost:8000/hello`
