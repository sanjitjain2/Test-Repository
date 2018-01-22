import json,os
json_data = open("data.json").read()

data = json.loads(json_data)
keys = data["Dependencies"].keys()
values = data["Dependencies"].values()
error_code = ""

for i in range(0,len(keys)):
    command = str("sudo pip install " + keys[i] + "==" + values[i])
    x = os.system(command)
    if(x != 0):
    	error_code = error_code + str(keys[i] + "==" + values[i] + " could not be installed \n")

if error_code == "":
	print "success"
else:
	print error_code    	