#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using u64 = unsigned long long int;

u64 factorial(u64 n)
{
    if (n < 2)
    {
        return 1;
    }
    u64 prod = 1;
    for (u64 i = 2; i <= n; i++)
    {
        prod *= i;
    }
    return prod;
}

std::string readInput()
{
    std::string text;
    std::cin >> text;
    return text;
}

void collectLetters(const std::string &input, std::map<char, u64> &letters)
{
    for (const auto &ch : input)
    {
        if (letters.find(ch) == letters.end())
        {
            letters[ch] = (u64)1;
            continue;
        }

        letters[ch]++;
    }
}

// returns the number of words starting with c
u64 numberOfWordsStartingWith(char c, u64 combinations, const std::map<char, u64> &letters, const std::string &input)
{
    const auto &it = letters.find(c);
    if (it == letters.end())
    {
        return (u64)0;
    }

    const auto num = it->second;
    return ((double)num / (double)input.size()) * combinations;
}

void generateStrings(std::set<std::string> &set, const std::map<char, u64> &letters, u64 length, const std::string &base)
{
    if (length == 0)
    {
        set.insert(base);
    }

    for (const auto &pair : letters)
    {
        if (pair.second > 0)
        {
            auto cpy(letters);
            cpy[pair.first]--;
            generateStrings(set, cpy, length - 1, base + std::string(1, pair.first));
        }
    }
}

int main()
{
    std::string input = readInput();
    std::map<char, u64> letters;

    collectLetters(input, letters);

    u64 sum = 0;

    for (const auto &pair : letters)
    {
        sum += pair.second;
    }

    // combinations = fact(sumOfLetters) / fact(numberOfAs) / fact(numberOfBs) / fact(numberOfCs) / ...
    u64 combinations = factorial(sum);

    for (const auto &pair : letters)
    {
        combinations /= factorial(pair.second);
    }

    std::cout << combinations << std::endl;

    std::set<std::string> words;

    generateStrings(words, letters, (u64)input.size(), "");

    for (const auto &word : words)
    {
        std::cout << word << std::endl;
    }

    return 0;
}