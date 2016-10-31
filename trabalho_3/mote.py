import socket
import sys

def getStatus(s_id):
  s_id = str(s_id)
  address = "cafe::212:740"+s_id+":"+s_id+":"+s_id+"0"+s_id 
  port = 5000
  message = str.encode('STATUS')
  sock = socket.socket(socket.AF_INET6,socket.SOCK_DGRAM)
  sock2 = socket.socket(socket.AF_INET6,socket.SOCK_DGRAM)
  sock2.bind(("cafe::1", 5000))
  sock.sendto(message, (address, port))
  (data, addr) = sock2.recvfrom(1024)
  return data.decode()

def toggle(s_id):
  s_id = str(s_id)
  address = "cafe::212:740"+s_id+":"+s_id+":"+s_id+"0"+s_id
  port = 5000
  message = str.encode('TOGGLE')
  sock = socket.socket(socket.AF_INET6,socket.SOCK_DGRAM)
  sock.sendto(message, (address, port))
