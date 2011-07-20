__author__ = 'bols-blue@lnc.jp'

# Imports the monkeyrunner modules used by this program
from com.android.monkeyrunner import MonkeyRunner
import  com.android.monkeyrunner.MonkeyDevice
import time

# Connects to the current device, returning a MonkeyDevice object
device = MonkeyRunner.waitForConnection()

# Installs the Android package. Notice that this method returns a boolean, so you can test
# to see if the installation worked.
device.installPackage('MonkeyTools.apk')

# sets a variable with the package's internal name
package = 'com.example.android.apis'

# sets a variable with the name of an Activity in the package
activity = '.ApiDemos'

# sets the name of the component to start
runComponent = package + '/' + activity

# Runs the component
device.startActivity(component=runComponent)

MonkeyRunner.sleep(4)
touch_data ={'x':85,'y':216,'type':'downAndUp',}
device.touch(touch_data['x'],touch_data['y'],touch_data['type'])
MonkeyRunner.sleep(0.5)
result = device.takeSnapshot()
result.writeToFile('output/shot1.png','png')
touch_data ={'x':336,'y':190,'type':'downAndUp',}
device.touch(touch_data['x'],touch_data['y'],touch_data['type'])
MonkeyRunner.sleep(0.5)
result = device.takeSnapshot()
result.writeToFile('output/shot2.png','png')
touch_data ={'x':358,'y':165,'type':'downAndUp',}
device.touch(touch_data['x'],touch_data['y'],touch_data['type'])
MonkeyRunner.sleep(0.5)
result = device.takeSnapshot()
result.writeToFile('output/shot3.png','png')

device.removePackage(package) 
