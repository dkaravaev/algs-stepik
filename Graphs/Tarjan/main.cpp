#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
#include <map>


class Graph
{
public:
    enum
    {
        ROOT_VERTEX = 0
    };

    enum Color
    {
        None,
        Green,
        Blue
    };

    typedef std::pair<uint, uint> Edge;

public:
    Graph(uint V, const std::vector<Edge>& edges)
            : V(V)
            , E(0)
            , clock(0)
    {
        for (uint i = 0; i < V; ++i)
        {
            ConnLists.push_back(std::list<uint>());
        }

        for (std::vector<Edge>::const_iterator i = edges.begin();
             i != edges.end(); ++i)
        {
            insert_edge(*i);
        }
    }

    bool insert_edge(const Edge& e)
    {
        ++E;
        if ((e.first >= V) || (e.second >= V))
        {
            return false;
        }

        ConnLists[e.first].push_back(e.second);
        ConnLists[e.second].push_back(e.first);
        return true;
    }

    std::vector<std::set<int>> find_blocks()
    {
        std::vector<int> visited(V, false);
        std::stack<Edge> stack;
        parent = std::vector<int>(V);
        depth = std::vector<int>(V);
        low = std::vector<int>(V);

        for (int v = 0; v < V; ++v)
        {
            if (!visited[v])
            {
                explore(v, visited, stack);
            }
        }

        return blocks;
    }

private:
    void explore(uint v, std::vector<int>& visited, std::stack<Edge>& stack)
    {
        ++clock;
        depth[v] = clock;
        low[v] = depth[v];

        visited[v] = true;
        for (std::list<uint>::iterator i = ConnLists[v].begin();
             i != ConnLists[v].end(); ++i)
        {
            if (!visited[*i])
            {
                stack.emplace(v, *i);
                parent[*i] = v;

                explore(*i, visited, stack);
                if (low[*i] >= depth[v])
                {
                    save_block(v, *i, stack);
                }

                low[v] = std::min(low[v], low[*i]);
            }
            else if ((parent[v] != *i) && (depth[*i] < depth[v]))
            {
                stack.emplace(v, *i);
                low[v] = std::min(low[v], depth[*i]);
            }
        }
    }

    void save_block(int v, int i, std::stack<Edge>& stack)
    {
        blocks.emplace_back();
        Edge edge;
        do
        {
            edge = stack.top();
            blocks.back().insert(edge.first);
            blocks.back().insert(edge.second);
            stack.pop();
        } while (edge != Edge(v, i));
    }


private:
    typedef std::vector<std::list<uint>> ConnList;

private:
    ConnList           ConnLists;
    uint               E;
    uint               V;

    uint               clock;
    std::vector<int>   depth;
    std::vector<int>   low;
    std::vector<int>   parent;

    std::vector<std::set<int>> blocks;
};

int main()
{
    std::vector<Graph::Edge> edges;
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int b, e;
        std::cin >> b >> e;
        edges.emplace_back(b, e);
    }

    Graph G(n, edges);
    auto blocks = G.find_blocks();
    std::vector<int> minv(n);
    for (int i = 0; i < n; ++i)
    {
        minv[i] = i;
    }

    // std::cout << blocks.size() << std::endl;
    for (auto block = std::begin(blocks); block != std::end(blocks); ++block)
    {
        for (auto v: *block)
        {
            minv[v] = std::min(minv[v], *block->begin());
        }
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << minv[i] << std::endl;
    }

    return 0;
}