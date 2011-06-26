__author__ = 'bols-blue@lnc.jp'

# Imports the monkeyrunner modules used by this program
from com.android.monkeyrunner import MonkeyRunner
import  com.android.monkeyrunner.MonkeyDevice

# Connects to the current device, returning a MonkeyDevice object
device = MonkeyRunner.waitForConnection()

# Installs the Android package. Notice that this method returns a boolean, so you can test
# to see if the installation worked.
device.installPackage('/opt/android-sdk-linux_86/platforms/android-4/samples/ApiDemos/bin/MonkeyTools.apk')

# sets a variable with the package's internal name
package = 'com.example.android.apis'

## sets a variable with the name of an Activity in the package
#activity = '.app.DialogActivity'
#
## sets the name of the component to start
#runComponent = package + '/' + activity
#
## Runs the component
#device.startActivity(component=runComponent)
#
## Presses the Menu button
#device.press('KEYCODE_MENU','DOWN_AND_UP')
#
## Takes a screenshot
#result = device.takeSnapshot()
#
## Writes the screenshot to a file
#result.writeToFile('myproject/shot1.png','png')

# sets a variable with the name of an Activity in the package
activity = '.ApiDemos'

# sets the name of the component to start
runComponent = package + '/' + activity

# Runs the component
device.startActivity(component=runComponent)

# Presses the Menu button
device.press('KEYCODE_MENU','DOWN_AND_UP')

# Takes a screenshot
result = device.takeSnapshot()

# Writes the screenshot to a file
result.writeToFile('myproject/shot2.png','png')