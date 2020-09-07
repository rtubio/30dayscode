import math
import sys

MIN_ENTRIES = 1
MAX_ENTRIES = math.pow(10, 5)
MIN_QUERIES = 1
MAX_QUERIES = math.pow(10, 5)


class Agenda(object):
    """
    This class implements the agenda. Instead of extending a Dictionary, this class implements its own internal
    dictionary and incorporates the methods to input / output the entries from the agenda.
    """

    def __init__(self, no_entries):
        """Constructor
        This is the default constructor that allows creating an Agenda object with the given number of entries.
        @param entries -- number of initial entries of the agenda
        """
        if no_entries < MIN_ENTRIES or no_entries > MAX_ENTRIES:
            raise ValueError(f"Number of entries has to be in the range [{MIN_ENTRIES}, {MAX_ENTRIES}]")

        self.no_entries = no_entries
        self.agenda = {}

    def addEntry(self, name, phone):
        """
        This method adds a new entry to the agenda.
        @param name -- Name of the person
        @param phone -- Phone of the person
        """
        self.agenda[name] = phone

    def printEntry(self, name):
        """
        This method prints out the entry for the given name.
        @param name -- Name of the person as given in the query
        """
        if name in self.agenda:
            print(f"{name}={self.agenda[name]}")
        else:
            print(f"Not found")

    def query(self):
        """
        Read the queries and execute them over the existing agenda.
        """
        query_i = 1
        for line in sys.stdin:
            # Need to truncate the line specifically like this for hackerrank
            if line[-1] == '\n':
                line = line[:-1]
            self.printEntry(line)
            if query_i == MAX_QUERIES:
                sys.exit(0)


def create_agenda():
    """Factory
    This method permits instantiating an agenda object by reading the number of entries from the standard input.
    """

    entries = int(input())
    agenda = Agenda(entries)

    for entry_i in range(entries):

        line = input()
        entry_items = line.split(' ')
        name = entry_items[0]
        phone = entry_items[1]
        # Need to truncate the line specifically like this for hackerrank
        if phone[-1] == '\n':
            phone = phone[:-1]

        agenda.addEntry(name, int(phone))

    return agenda


# Main execution loop

agenda = create_agenda()
agenda.query()
