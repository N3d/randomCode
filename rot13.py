#!/usr/bin/python

"""
* python program to encrypt string using the Cesar13 crypting algorithm
* 
* usage:
    python rot13.py STRING
"""
import sys

def main(argv=None):
    if argv is None:
        argv = sys.argv
        if len(argv) <= 1:
            print("rot13: require the string to encode\n")
            sys.exit()
    original = argv[1];
    encode = original.encode("rot13")
    print("Original: {0} \nCrypted: {1} \n".format(original,encode))

if __name__ == "__main__":
    sys.exit(main())


