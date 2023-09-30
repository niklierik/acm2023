#include <iostream>
#include <inttypes.h>

using u8 = std::uint8_t;
using u64 = std::uint64_t;

void readInput(u64 &rows, u64 &columns, u64 &tickets)
{
    std::cin >> rows;
    std::cin >> columns;
    std::cin >> tickets;
}

int main()
{
    while (!std::cin.eof())
    {
        u64 rows, columns, tickets;
        readInput(rows, columns, tickets);

        u8 *seats = new u8[rows * columns];

        // have no idea

        delete[] seats;
    }
    return 0;
}