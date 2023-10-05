#include <iostream>
#include <vector>
#include <map>
#include <queue>
// #include <limits>
#include <set>

using u64 = unsigned long long int;

// from _UI64_MAX macro, it was not defined in the runner
#define U64_MAX_VALUE 0xffffffffffffffff

struct Edge
{
    u64 from;
    u64 to;
    u64 cost;
};

struct PQ_Node
{
    u64 key;

    const std::map<u64, u64> *dist;

    PQ_Node() {}

    PQ_Node(u64 key, const std::map<u64, u64> *dist) : key(key), dist(dist) {}

    u64 prio() const
    {
        const auto &it = dist->find(key);
        if (it == dist->end())
        {
            return U64_MAX_VALUE;
        }
        return it->second;
    }

    bool
    operator==(const PQ_Node &other) const
    {
        return prio() == other.prio();
    }

    bool operator<(const PQ_Node &other) const
    {
        return prio() < other.prio();
    }

    bool operator>(const PQ_Node &other) const
    {
        return prio() > other.prio();
    }
};

void readInput(u64 &noCities, u64 &noEdges, std::vector<Edge> &edges)
{
    std::cin >> noCities;
    std::cin >> noEdges;

    for (u64 i = 0; i < noEdges; i++)
    {
        u64 from, to, cost;

        std::cin >> from;
        std::cin >> to;
        std::cin >> cost;

        Edge e{from, to, cost};
        edges.push_back(e);
    }
}

void dijkstra(const std::vector<Edge> &edges, u64 cities, u64 from)
{
    std::map<u64, u64> dist;
    // std::map<u64, u64> prev;

    std::priority_queue<PQ_Node, std::vector<PQ_Node>, std::less<PQ_Node>> q;

    for (u64 i = 1; i <= cities; i++)
    {
        dist[i] = U64_MAX_VALUE;
        // prev[i] = -1;
        q.emplace(PQ_Node(i, &dist));
    }

    dist[from] = 0;

    while (!q.empty())
    {
        const auto &u = q.top();

        q.pop();

        for (const auto &edge : edges)
        {
            u64 v = 0;
            if (edge.from == u.key)
            {
                v = edge.to;
            }
            // edge does not belong to u
            if (v == 0)
            {
                continue;
            }
            auto alt = dist[u.key] + edge.cost;
            if (alt < dist[v])
            {
                dist[v] = alt;
                // prev[v] = u;
            }
        }
    }

    for (u64 i = 1; i <= cities; i++)
    {
        std::cout << dist[i] << " ";
    }
}

int main()
{
    u64 noCities, noEdges;
    std::vector<Edge> edges;

    readInput(noCities, noEdges, edges);

    dijkstra(edges, noCities, 1);

    return 0;
}