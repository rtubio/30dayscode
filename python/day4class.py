import sys


class Person(object):
    """
    This class models a Person object, with a single variable named "age".
    """

    def __init__(self, initialAge):
        """Constructor"""
        if initialAge < 0:
            self.age = 0
            print("Age is not valid, setting age to 0.", end='\n', file=sys.stdout, flush=True)
        else:
            self.age = initialAge

    def yearPasses(self):
        self.age += 1

    def amIOld(self):
        if self.age < 13:
            print("You are young.", end='\n', file=sys.stdout, flush=True)
            return
        if ( self.age >= 13 ) and ( self.age < 18 ):
            print("You are a teenager.", end='\n', file=sys.stdout, flush=True)
            return
        if self.age >= 18:
            print("You are old.", end='\n', file=sys.stdout, flush=True)
            return


t = int(input())
for i in range(0, t):

    age = int(input())
    p = Person(age)
    p.amIOld()

    for j in range(0, 3):
        p.yearPasses()

    p.amIOld()
    print("")
