#!/usr/bin/env python

import sys

MAYAN_NUMBER_ZERO = '<=>'
MAYAN_NUMBER_FIVE = '---'


def decode(mayan_number: list[list[str]]) -> int:
    def mayan_symbol_to_integer(symbol: str) -> int:
        if symbol == MAYAN_NUMBER_ZERO:
            return 0
        if symbol == MAYAN_NUMBER_FIVE:
            return 5
        return len(symbol)  # Assume that symbol is full of ones "*", therefore its value is equal to the length of symbol

    def decode_level(level: list[str]) -> int:
        # Decode each symbol one by one
        return sum(mayan_symbol_to_integer(symbol) for symbol in level)

    # Decode each level from the bottom up
    return sum(
        decode_level(level) * (20 ** position)
        for position, level in enumerate(reversed(mayan_number))
    )


def main() -> None:
    level = []
    mayan_number = []
    for line in sys.stdin:
        if len(line.strip()) == 0:
            mayan_number.append(level)
            level = []
        else:
            level.append(line.strip())
    mayan_number.append(level)

    print(decode(mayan_number))

    
if __name__ == '__main__':
    main()
            