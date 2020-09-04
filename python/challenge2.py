import sys

# Code challenge #2
#
# This code challenge represents the typical problem of change return, in terms of coins and bills.
#
# The following limitations have been found in the specification:
# >>> LIMITATION #1: in case more than 1 unit of each coin/bill to be returned, no requirements have been specified
#                       about how to print out the number of coins/bills.
#                   In order to deal with this issue, if no number is specified if only 1 has to be returned; whilst
#                   if more than 1 coin/bill have to be returned, the format NUMBERxNAME has been proposed.
#
# @date: 2020.09.04
# @author: rtpardavila[at]gmail[dot]com

COINS = {
    'PENNY': .01,
    'NICKEL': .05,
    'DIME': .10,
    'QUARTER': .25,
    'HALF DOLLAR': .50,
    'ONE': 1.00,
    'TWO': 2.00,
    'FIVE': 5.00,
    'TEN': 10.00,
    'TWENTY': 20.00,
    'FIFTY': 50.00,
    'ONE HUNDRED': 100.00
}
VALUE_2_COIN = {v:k for k,v in COINS.items()}
COIN_VALUES = sorted(list(COINS.values()), reverse=True)


def compute_coins(reminder):
    """
    This function calculates the coins, in terms of value, to be returned.
    In order to caluculate the coins that sum up the reminder, we will start in descending
    order assigning as many as possible coins for the higest values.

    @param reminder -- float with the total amount of cash to return
    """
    change_str = []

    for coin_value in COIN_VALUES:

        no_coins = int(reminder / coin_value)
        if no_coins < 1:
            continue

        coin_name = VALUE_2_COIN[coin_value]

        if no_coins == 1:
            change_str.append(coin_name)
        else:
            change_str.append(f"{no_coins}x{coin_name}")

        reminder -= (no_coins * coin_value)
        # Necessary to avoid issues with decimals precision during the substraction, ex.: .42222223
        reminder = float(f"{reminder:.2f}")

    return change_str

def read_numbers(line):
    """
    This function reads the pp (purchase price) and ch (cash) float numbers from the input line.
    @param line -- Input line with the numbers
    @return -- (pp, ch) tuple with the read float numbers
    """
    args = line.split(';')
    pp = float(args[0])
    ch = float(args[1])

    if (pp < 0.0) or (ch < 0.0) or (ch < pp):
        raise Exception("ERROR")

    if (pp == ch):
        raise Exception("ZERO")

    return pp, ch


# ### Main execution loop

for line in sys.stdin:

    try:

        pp, ch = read_numbers(line)
        # Necessary to avoid issues with decimals precision during the substraction, ex.: .42222223
        reminder = float(f"{(ch - pp):.2f}")
        coins_change = compute_coins(reminder)

        change = ",".join(coins_change)
        print(f"{change}")

    except Exception as ex:
        print(ex)
