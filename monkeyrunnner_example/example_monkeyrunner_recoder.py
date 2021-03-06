__author__ = 'bols-blue@lnc.jp'

# Imports the monkeyrunner modules used by this program
from com.android.monkeyrunner import MonkeyRunner
import  com.android.monkeyrunner.MonkeyDevice
import time
from com.android.monkeyrunner.recorder import MonkeyRecorder 
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
device = MonkeyRunner.waitForConnection(10.0)

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

MonkeyRecorder.start(device)
