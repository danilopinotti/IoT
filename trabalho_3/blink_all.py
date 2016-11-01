import sys
import mote
import time

while (1):
  for i in range(2,8):
    mote.toggle(i)
  time.sleep(1)

