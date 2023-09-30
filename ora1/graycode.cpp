#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using u64 = unsigned long long int;

u64 readInput()
{
    u64 n;
    std::cin >> n;
    return n;
}

// pow2(n) = 2 ^ n
u64 pow2(u64 n)
{
    return (u64)1 << n;
}

// getDouble(n) = 2 * n
u64 getDouble(u64 i)
{
    return i << (u64)1;
}

/*
Create a list with 0, 1

mirror the list and push it to the original's end

0 1 1 0

insert 0 for the first part, 1 for the second

00
01
--
11
10

repeat till code is length n

000
001
011
010
--
110
111
101
100

*/

int main()
{
    u64 n = readInput();

    std::vector<std::string> codes;
    codes.push_back("0");
    codes.push_back("1");

    u64 limit = pow2(n);

    for (u64 i = (u64)2; i < limit; i = getDouble(i))
    {
        // mirror list and push it to the original's end
        for (u64 j = i - (u64)1; true; j--)
        {
            codes.push_back(codes[j]);
            if (j == 0)
            {
                break;
            }
        }
        // insert 0's for the first part
        for (u64 j = (u64)0; j < i; j++)
        {
            codes[j] = ('0' + codes[j]);
        }
        // insert 1's for the second part
        for (u64 j = i; j < (u64)2 * i; j++)
        {
            codes[j] = ('1' + codes[j]);
        }
    }

    for (const auto &code : codes)
    {
        if (code.size() == n)
        {
            std::cout << code << std::endl;
        }
    }

    return 0;
}