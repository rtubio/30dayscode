import math
import sys

# This program reads the representation of two numbers in binary strings.
# Once the numbers are read, the numbers are added up and its binary representation is printed out as a string.
#
# The following constraints for resolving the problem are assumed:
#   > 1 : clarifications are required about what to do if input does not conform with the given requirements
#
# author: rtpardavila[at]gmail[dot]com


def binstr2int(binary_string):
    """
    UNNECESSARY, see int(string, base)
    This function converts a binary string into an integer number.
    @param binary_string - string that contains number in its binary representation
    """
    number = 0

    digits = [
        int(d) for d in binary_string if d == '0' or d == '1'
    ]

    for index in range(0, len(digits)):
        d = digits[index]
        power = d*math.pow(2, len(digits)-index-1)
        number += power

    return int(number)

for line in sys.stdin:

    numbers = [
        int(s, 2) for s in line.split(',')
    ]

    print(f"{(numbers[0]+numbers[1]):b}")
