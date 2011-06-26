__author__ = 'bols-blue@lnc.jp'

# Imports the monkeyrunner modules used by this program
from com.android.monkeyrunner import MonkeyRunner
import  com.android.monkeyrunner.MonkeyDevice
import time

# Connects to the current device, returning a MonkeyDevice object
device = MonkeyRunner.waitForConnection()

# Installs the Android package. Notice that this method returns a boolean, so you can test
# to see if the installation worked.
device.installPackage('/opt/android-sdk-linux_86/platforms/android-4/samples/ApiDemos/bin/MonkeyTools.apk')

# sets a variable with the package's internal name
package = 'com.example.android.apis'

# sets a variable with the name of an Activity in the package
activity = '.ApiDemos'

# sets the name of the component to start
runComponent = package + '/' + activity

# Runs the component
device.startActivity(component=runComponent)

MonkeyRunner.sleep(4)
press_data ={'name':'MENU','type':'downAndUp',}
device.press(press_data["name"],press_data["type"])
MonkeyRunner.sleep(0.5)
result = device.takeSnapshot()
result.writeToFile('output/shot1.png','png')
type_data ={'message':'abcdef',}
device.type(type_data['message'])
MonkeyRunner.sleep(0.5)
result = device.takeSnapshot()
result.writeToFile('output/shot2.png','png')
wait_data ={'seconds':5.0,}
MonkeyRunner.sleep(wait_data["seconds"])
MonkeyRunner.sleep(0.5)
result = device.takeSnapshot()
result.writeToFile('output/shot3.png','png')
drag_data ={'start':(192,640),'end':(192,128),'duration':0.1,'steps':10,}
device.drag(drag_data['start'],drag_data['end'],drag_data['duration'],drag_data['steps'])
MonkeyRunner.sleep(0.5)
result = device.takeSnapshot()
result.writeToFile('output/shot4.png','png')
touch_data ={'x':265,'y':343,'type':'downAndUp',}
device.touch(touch_data['x'],touch_data['y'],touch_data['type'])
MonkeyRunner.sleep(0.5)
result = device.takeSnapshot()
result.writeToFile('output/shot5.png','png')
touch_data ={'x':175,'y':555,'type':'downAndUp',}
device.touch(touch_data['x'],touch_data['y'],touch_data['type'])
MonkeyRunner.sleep(0.5)
result = device.takeSnapshot()
result.writeToFile('output/shot6.png','png')

device.removePackage(package) 
