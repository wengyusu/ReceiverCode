import re
import requests
import json
import os
import subprocess
import time
from socketio_client import SocketIO , LoggingNamespace
socketIO = SocketIO('localhost', 8000, LoggingNamespace)
reg = "TS:(\d+).*Drop:.*RX:(\d+).*TX:(\d+).*RSSI:(-*\d+.\d+).*CRC	Data:.*light: (\d+) temp: (\d+.\d*) humidity: (\d+)"
cmd = "gstdbuf -o0 ./pip_sense.v2 l l | gstdbuf -o0 grep TX:03408"

p = subprocess.Popen(cmd,bufsize=1,stdout=subprocess.PIPE,shell=True)
for line in iter(p.stdout.readline, ""):
    line=line.decode("utf-8")
    print(line)
    payload=[]
    if line.startswith("TS"):
        data={}
        match = re.search(reg,line).groups()
        data["ts"] = match[0]
        data["rx"] = match[1]
        data["tx"] = match[2]
        data["rssi"] = match[3]
        data["light"] = match[4]
        data["temp"] = match[5]
        data["hum"] = match[6]
        socketIO.emit('update',json.dumps(data))

p.stdout.close()
p.wait()







