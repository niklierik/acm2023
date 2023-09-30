#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <ios>
#include <limits>

void readInput()
{
    int numberOfAccounts;
    std::cin >> numberOfAccounts;
    std::vector<std::string> accounts;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < numberOfAccounts; i++)
    {
        std::string account;
        std::getline(std::cin, account);
        accounts.push_back(account);
    }

    std::sort(accounts.begin(), accounts.end());

    std::string &now = accounts[0];
    unsigned number = 1;

    for (int i = 1; i < numberOfAccounts; i++)
    {
        if (now == accounts[i])
        {
            number++;
            continue;
        }
        std::cout << now << " " << number << std::endl;
        now = accounts[i];
        number = 1;
    }
    std::cout << now << " " << number << std::endl
              << std::endl;
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        readInput();
    }
    return 0;
}