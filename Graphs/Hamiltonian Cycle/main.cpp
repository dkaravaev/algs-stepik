#include <iostream>
#include <vector>

class Graph
{
public:
    using Edge = std::pair<int, int>;

public:
    Graph(int V)
        : V(V)
        , adj_m(V, std::vector<int>(V, false))
    {

    }

    void insert_edge(const Edge& edge)
    {
        adj_m[edge.first][edge.second] = true;
        adj_m[edge.second][edge.first] = true;
    }

    int hamiltonian_path(std::vector<int>& path)
    {
        for (int i = 0; i < V; ++i)
        {
            path = std::vector<int>(V, -1);
            path[0] = i;
            std::vector<int> added(V, false);
            added[i] = true;

            if (hamiltonian_path_rec(path, added, 1))
            {
                return true;
            }
        }

        return false;
    }

    int hamiltonian_path_rec(std::vector<int>& path, std::vector<int>& added, int len)
    {
        if (len == V)
        {
            return true;
        }

        for (int u = 0; u < V; ++u)
        {
            if (adj_m[path[len - 1]][u] && !added[u])
            {
                path[len] = u;
                added[u] = true;

                if (hamiltonian_path_rec(path, added, len + 1))
                {
                    return true;
                }

                added[u] = false;
                path[len] = -1;
            }
        }

        return false;
    }

private:
    int V;
    std::vector<std::vector<int>> adj_m;
};


int main()
{
    int V = 0;
    std::vector<Graph::Edge> edges;

    int b, e;
    while (std::cin >> b >> e)
    {
        V = std::max(std::max(b, e), V);
        edges.emplace_back(b, e);
    }

    ++V;
    Graph g(V);
    for (auto& edge: edges)
    {
        g.insert_edge(edge);
    }

    std::vector<int> path;
    if (g.hamiltonian_path(path))
    {
        for (int i = 0; i < path.size(); ++i)
        {
            std::cout << path[i] << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "-1" << std::endl;
    }

    for (auto& edge: edges)
    {
        std::cout << edge.first << " " << edge.second << std::endl;
    }

    return 0;
}