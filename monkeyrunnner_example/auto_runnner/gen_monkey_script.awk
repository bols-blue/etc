BEGIN{
	FS = "|"
	OFS = "\t"
}
{
	if($1 =="PRESS"){
		print "press_data ="$2
		print "device.press(press_data[\"name\"],press_data[\"type\"])"
	}else if($1 =="WAIT"){
		print "wait_data ="$2
		print "MonkeyRunner.sleep(wait_data[\"seconds\"])"
	}else if($1 =="DRAG"){
		print "drag_data ="$2
		print "device.drag(drag_data['start'],drag_data['end'],drag_data['duration'],drag_data['steps'])"
	}else if($1 =="TOUCH"){
		print "touch_data ="$2
		print "device.touch(touch_data['x'],touch_data['y'],touch_data['type'])"
	}else if($1 =="TYPE"){
		print "type_data ="$2
		print "device.type(type_data['message'])"
	}else{
		print $1 $2
	}
	print "MonkeyRunner.sleep(0.5)"
	print "result = device.takeSnapshot()"
	print "result.writeToFile('output/shot"NR".png','png')"
		
}

