#include <iostream>
#include <algorithm>
#include <vector>

using u64 = unsigned long long int;

void readInput(u64 &peoples, u64 &maxWeight, std::vector<u64> &weights)
{
    std::cin >> peoples;
    std::cin >> maxWeight;

    for (u64 i = 0; i < peoples; i++)
    {
        u64 weight;
        std::cin >> weight;
        weights.push_back(weight);
    }
}

int main()
{
    u64 peoples;
    u64 maxWeight;
    std::vector<u64> weights;

    readInput(peoples, maxWeight, weights);

    std::sort(weights.begin(), weights.end());

    u64 rounds = 0;

    while (weights.size() > 0)
    {
        if (weights.size() == 1)
        {
            rounds++;
            weights.clear();
            break;
        }
        auto first = weights[0];
        auto last = weights[weights.size() - 1];

        weights.erase(weights.end() - 1);
        rounds++;
        if (first + last > maxWeight)
        {
            continue;
        }

        auto currentWeight = first + last;
        weights.erase(weights.begin() + 0);

        while (currentWeight + weights[0] > maxWeight)
        {
            currentWeight += weights[0];
            weights.erase(weights.begin() + 0);
            if (weights.empty())
            {
                break;
            }
        }
    }

    std::cout << rounds << std::endl;

    return 0;
}