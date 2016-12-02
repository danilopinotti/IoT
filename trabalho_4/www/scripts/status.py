import sys
import mote
import time

if len(sys.argv) > 1:
  action = sys.argv[1]
  if (not int(action) in range (2,8)):
    print("Invalid mote id")
    sys.exit()

else:
  action = "all"

if (action.isdigit() and int(action) in range(2,8)):
  print (mote.getStatus(action))
  
else:
  while 1:
    for i in range (2, 8):
      print("lâmpada"+ str(i) +" ("+  ('desligada','ligada')[mote.getStatus(i)=="ON"] +")" )
    time.sleep(5)
    print ("-------")