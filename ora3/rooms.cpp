#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

const char WALL = '#';
const char SPACE = '.';

std::string map;
int width, height;

void readInput(std::string &outMap, int &outWidth, int &outHeight)
{
    int height;
    int width;
    std::cin >> height;
    std::cin >> width;

    std::string map = "";
    for (int i = 0; i < height; i++)
    {
        std::string temp;
        std::cin >> temp;
        map += temp;
    }

    outMap = map;
    outWidth = width;
    outHeight = height;
}

int index(int x, int y)
{
    return x + y * width;
}

void pos(int index, int &x, int &y)
{
    x = index % width;
    y = index / width;
}

std::vector<int> neighbors(int i)
{
    std::vector<int> n;
    int x, y;
    pos(i, x, y);
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx == 0 && dy == 0)
            {
                continue;
            }
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= width || ny < 0 || ny >= height)
            {
                continue;
            }
            int ni = index(nx, ny);
            if (map[ni] == SPACE)
            {
                n.push_back(ni);
            }
        }
    }
    return n;
}

int **createAdjMatrix(const std::string &map)
{

    const int length = map.length();
    int **adjacencyMatrix = new int *[length];
    for (int i = 0; i < length; i++)
    {
        adjacencyMatrix[i] = new int[length];
        for (int j = 0; j < 0; j++)
        {
            adjacencyMatrix[i][j] = -1;
        }
    }

    for (int i = 0; i < map.length(); i++)
    {
        if (map[i] == SPACE)
        {
            if (adjacencyMatrix[i][i] == -1)
            {
                adjacencyMatrix[i][i] = 0;
            }
            for (const auto &ni : neighbors(i))
            {
                adjacencyMatrix[i][ni] = 1;
            }
        }
    }

    return adjacencyMatrix;
}

void cleanAdjacencyMatrix(int **adjMatrix, int length)
{
    for (int i = 0; i < length; i++)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

int bfs()
{
    int **adjMatrix = createAdjMatrix(map);

    std::set<int> open;
    std::set<int> closed;

    cleanAdjacencyMatrix(adjMatrix, map.length());
}

int main()
{
    readInput(map, width, height);
    std::cout << map << '\n';

    return 0;
}