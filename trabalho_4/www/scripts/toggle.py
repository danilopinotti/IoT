import sys
import mote
import time

if len(sys.argv) > 1:
  action = sys.argv[1]
  if ((action != "toggle") and (action != "off") and (action != "on")):
    print("Invalid action")
    sys.exit()
else:
	action = "toggle"

if len(sys.argv) > 2:
  mote_id = sys.argv[2]
  if not int(mote_id) in range (2,8):
  	print("Invalid mote ID")
  	sys.exit()  

if not len(sys.argv) > 2:
  if (action == "off"):
    print("Turn off all")
    for i in range(2,8):
      mote.turnOff(i)

  elif action == "on":
    print("Turn on all")
    for i in range(2,8):
      mote.turnOn(i)

  elif action == "toggle":
    print("Toggle all")
    for i in range(2,8):
      mote.toggle(i)
else:
	if (action == "off"):
		print("Turn off mote "+mote_id)
		mote.turnOff(mote_id)
	elif action == "on":
		print("Turn on mote "+mote_id)		
		mote.turnOn(mote_id)		
	elif action == "toggle":
		print("Toggle mote "+mote_id)
		mote.toggle(mote_id)
