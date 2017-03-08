#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using Matrix = std::vector<std::vector<double>>;

class Graph {
public:
    Graph(int V, const Matrix &cost)
            : V(V), cost(cost)
    {

    }

    double ford_fulkerson(int s, int t)
    {
        Matrix rcost(V, std::vector<double>(V, 0));
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                rcost[i][j]  = cost[i][j];
            }
        }

        std::vector<int> path(V);

        double res = 0;
        while (BFS(s, t, path, rcost))
        {
            double flow = std::numeric_limits<double>::max();
            for (int v = t; v != s; v = path[v])
            {
                int u = path[v];
                flow = std::min(flow, rcost[u][v]);
            }

            for (int v = t; v != s; v = path[v])
            {
                int u = path[v];
                rcost[u][v] -= flow;
                rcost[v][u] += flow;
            }

            res += flow;
        }

        return res;
    }

private:
    bool BFS(int s, int t, std::vector<int>& path, Matrix rcost)
    {
        path[s] = -1;

        std::vector<int> visited(V, 0);
        visited[s] = true;

        std::queue <int> queue;
        queue.push(s);

        while (!queue.empty())
        {
            int u = queue.front();
            queue.pop();

            for (int v = 0; v < V; v++)
            {
                if (visited[v] == false && rcost[u][v] > 0)
                {
                    queue.push(v);
                    path[v] = u;
                    visited[v] = true;
                }
            }
        }

        return (visited[t] == true);
    }


private:
    int V;
    Matrix cost;
};


int main()
{
    int V, E;
    std::cin >> V >> E;
    Matrix costs(V, std::vector<double>(V, 0));

    for (int i = 0; i < E; ++i)
    {
        int b, e;
        std::cin >> b >> e;
        std::cin >> costs[b][e];
    }

    Graph G(V, costs);
    std::cout << G.ford_fulkerson(0, V - 1) << std::endl;
    return 0;
}