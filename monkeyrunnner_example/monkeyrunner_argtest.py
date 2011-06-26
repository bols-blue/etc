__author__ = 'bols-blue@lnc.jp'

# Imports the monkeyrunner modules used by this program
from com.android.monkeyrunner import MonkeyRunner
import  com.android.monkeyrunner.MonkeyDevice
import time
import sys 
 
argvs = sys.argv  
argc = len(argvs) 
print argvs
print argc
print
if (argc != 2):
	print 'Usage: # python %s filename' % argvs[0]
	sys.exit()

# Connects to the current device, returning a MonkeyDevice object
device = MonkeyRunner.waitForConnection(10.0,argvs[1])

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

# Presses the Menu button
device.press('KEYCODE_MENU','DOWN_AND_UP')

MonkeyRunner.sleep(4)
# void	drag (tuple start, tuple end, float duration, integer steps)
#Simulates a drag gesture (touch, hold, and move) on this device's screen.
start = (50,200)
end = (50,0)
device.drag(start,end,1.0)
# void type (string message)
#touch (integer x, integer y, integer type)
MonkeyRunner.sleep(0.5)
start = (50,200)
end = (50,100)
device.drag(start,end,10.0)
#input (string message, string initialValue, string title, string okTitle, string cancelTitle)
MonkeyRunner.input("hello would","sample","hello")
# Takes a screenshot
result = device.takeSnapshot()

# Writes the screenshot to a file
result.writeToFile('myproject/shot1.png','png')
