import sys
import mote

if len(sys.argv) > 1:
  action = sys.argv[1]
else:
  action = "toggle"

if action == "off":
  for i in range(2,8):
    mote.turnOff(i)

elif action == "on":
  for i in range(2,8):
    mote.turnOn(i)

elif action == "toggle":
  for i in range(2,8):
    mote.toggle(i)
