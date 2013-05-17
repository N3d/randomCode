#!/usr/bin/python
import binascii
import sys
cont = []

def readContent():
    f = open("binaryCode.txt")
    for line in f:
        cont.append(line)

    #print("Line 1:{0}, {1}, {2}".format(cont[0],cont[1],cont[2]))

readContent()

key = binascii.unhexlify(cont[0].rstrip())
frs = binascii.unhexlify(cont[1].rstrip())
key = [ord(x) for x in key]
frs = [ord(x) for x in frs] 
for k,f in zip(key,frs):
    sys.stdout.write("{0}".format(chr(k^f)))
    
print("\n")

key = binascii.unhexlify(cont[2].rstrip())                                      
frs = binascii.unhexlify(cont[3].rstrip())                                      
key = [ord(x) for x in key]                                                     
frs = [ord(x) for x in frs]                                                     
for k,f in zip(key,frs):
    sys.stdout.write("{0}".format(chr(k^f)))                                    
    
print("\n") 

