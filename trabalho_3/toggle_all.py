import sys
import mote
import time

if len(sys.argv) > 1:
  action = sys.argv[1]
else:
  action = "toggle"

if action == "off":
  for i in range(2,8):
    if mote.getStatus(i) == "ON":
      mote.toggle(i)
    time.sleep(0.1)

elif action == "on":
  for i in range(2,8):
    if mote.getStatus(i) == "OFF":
      mote.toggle(i)
    time.sleep(0.1)

elif action == "toggle":
  for i in range(2,8):
    mote.toggle(i)
    time.sleep(0.1)
