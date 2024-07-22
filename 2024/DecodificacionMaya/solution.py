from enum import Enum


class Mayan1Decimal(str, Enum):
    zero = '<=>'
    one = '*'
    five = '---'


def decode(mayan_number: list[list[str]]) -> int:
    # Helper function to decode a single level
    def decode_level(level: list[str]) -> int:
        value = 0
        for symbol in level:
            if symbol == Mayan1Decimal.zero:
                continue
            elif symbol == Mayan1Decimal.five:
                value += 5
            else:
                # symbol is one
                value += len(symbol)
        return value

    # Decode each level from the bottom up
    total_value = 0
    for position, level in enumerate(reversed(mayan_number)):
        level_value = decode_level(level)
        total_value += level_value * (20 ** position)

    return total_value


def solve(tty_in):
    digit = []
    mayan_number = []
    for line in tty_in:
        if len(line.strip()) == 0:
            mayan_number.append(digit)
            digit = []
        else:
            digit.append(line.strip())
    mayan_number.append(digit)
    decimal = decode(mayan_number)

    return decimal

    
if __name__ == '__main__':
    import sys
    print(solve(sys.stdin))
            