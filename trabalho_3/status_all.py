import sys
import mote
import time

while 1:
  for i in range (2, 8):
    print("lâmpada"+ str(i) +" ("+  ('desligada','ligada')[mote.getStatus(i)=="ON"] +")" )
  time.sleep(5)
  print ("-------")
