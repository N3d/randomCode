#!/usr/bin/python

"""
* python program to obfuscate a string using XOR fuction
* Obfuscation key is 0x13
* 
* usage:
    python obfuscation.py STRING
"""
import sys

def main(argv=None):
    if argv is None:
        argv = sys.argv
        if len(argv) <= 1:
            print("obfuscation: require the string to encode\n")
            sys.exit()
    original = argv[1];
    key = 0x13
    origByte = [ elem.encode("hex") for elem in original ]
    print("Hex: {0}".format(origByte))
    obfuscated = []
    for byte in origByte:
        obfuscated.append(str(int(key) ^ int(byte,16)))
    print obfuscated
    origByte = [ hex(int(elem)) for elem in obfuscated ]
    encode = ''.join(origByte).replace('0x','\\x')
    print("Original: {0} \nCrypted: {1} \n".format(original,encode))

if __name__ == "__main__":
    sys.exit(main())


