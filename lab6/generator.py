# -*- coding: utf-8 -*-
import sys
import random
import string
import copy
from random import choice

if __name__ == "__main__":
    count_of_tests = 15
    step = 1000
    actions = [ "Rectangle", "Square", "Trapezoid"]
    for enum in range( count_of_tests ):
        test_file_name = "tests/{:02d}".format( enum + 1 )
        with open( "{0}.t".format( test_file_name ), 'w' ) as output_file:
            for _ in range( step ):
                action = random.choice( actions )
                if action == "Rectangle":
                    key = 3
                    sideA = random.randint( 1, 1000 )
                    sideB = random.randint( 1, 1000 )
                    output_file.write("{0} {1} {2}\n".format(key, sideA, sideB ))
                elif action == "Square":
                    key = 2
                    sideA = random.randint( 1, 1000 )
                    output_file.write( "{0} {1}\n".format(key, sideA ) )
                elif action == "Rectangle":
                    key = 1
                    sideA = random.randint( 1, 1000 )
                    sideB = random.randint( 1, 1000 )
                    sideH = random.randint( 1, 1000 )
                    output_file.write( "{0} {1} {2} {3}\n".format(key, sideA, sizeB, sideH ) )
                
