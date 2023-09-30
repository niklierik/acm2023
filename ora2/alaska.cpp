#include <iostream>
#include <vector>
#include <algorithm>

const int DISTANCE = 1422;
const int RANGE = 200;

void readStations(int chargingStations)
{
    std::vector<int> stations;
    for (int i = 0; i < chargingStations; i++)
    {
        int input;
        std::cin >> input;
        stations.push_back(input);
    }
    std::sort(stations.begin(), stations.end());

    if ((DISTANCE - stations[stations.size() - 1]) * 2 > RANGE)
    {
        std::cout << "IMPOSSIBLE" << std::endl;
        return;
    }

    for (unsigned i = 0; i < stations.size() - 1; i++)
    {
        const int &now = stations[i];
        const int &next = stations[i + 1];
        if (next - now > RANGE)
        {
            std::cout << "IMPOSSIBLE" << std::endl;
            return;
        }
    }

    std::cout << "POSSIBLE" << std::endl;
}

int main()
{
    while (true)
    {
        int chargingStations;
        std::cin >> chargingStations;

        if (chargingStations == 0)
        {
            return 0;
        }

        readStations(chargingStations);
    }
}