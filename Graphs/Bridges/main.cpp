#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>

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

    void delete_edge(const Edge& e)
    {
        ConnLists[e.first].remove(e.second);
        ConnLists[e.second].remove(e.first);
    }

    void find_dcc(std::vector<std::vector<int>>& cc)
    {
        k = std::vector<int>(V);
        l = std::vector<int>(V);
        parent = std::vector<int>(V);
        std::vector<int> visited(V);
        int croot = 0;

        std::set<Edge> bridges;
        explore(ROOT_VERTEX, visited, bridges, croot);

        for (auto& bridge: bridges)
        {
            delete_edge(bridge);
        }

        visited.assign(V, false);
        for (int v = 0; v < V; ++v)
        {
            if (!visited[v])
            {
                cc.emplace_back();
                find_cc(v, visited, cc);
            }
        }
    }

    uint vert() const
    {
        return V;
    }

    uint edges() const
    {
        return E;
    }

private:
    void explore(uint v, std::vector<int>& visited, std::set<Edge>& bridges, int& croot)
    {
        visited[v] = true;
        ++clock;
        k[v] = clock;
        l[v] = clock;

        for (std::list<uint>::iterator i = ConnLists[v].begin();
             i != ConnLists[v].end(); ++i)
        {
            if (!visited[*i])
            {
                parent[*i] = v;
                explore(*i, visited, bridges, croot);
                l[v] = std::min(l[v], l[*i]);

                if (l[*i] > k[v])
                {
                    bridges.emplace(v, *i);
                }
            }
            else if (*i != parent[v])
            {
                l[v] = std::min(l[v], k[*i]);
            }
        }
    }

    void find_cc(uint v, std::vector<int>& visited, std::vector<std::vector<int>>& cc)
    {
        visited[v] = true;
        cc.back().push_back(v);
        for (std::list<uint>::iterator i = ConnLists[v].begin();
             i != ConnLists[v].end(); ++i)
        {
            if (!visited[*i])
            {
                find_cc(*i, visited, cc);
            }
        }
    }

private:
    typedef std::vector< std::list<uint> > ConnList;

private:
    ConnList           ConnLists;
    std::vector<int>   k;
    std::vector<int>   l;
    std::vector<int>   parent;
    uint               E;
    uint               V;
    uint               clock;
};

int main()
{
    std::vector<Graph::Edge> edges;
    int b, e;
    int V = 0;
    while (std::cin >> b >> e)
    {
        V = std::max(std::max(b, e), V);
        edges.push_back(Graph::Edge(b, e));
    }

    Graph G(V + 1, edges);
    std::vector<std::vector<int>> cc;
    G.find_dcc(cc);

    for (auto& c : cc)
    {
        for (auto i = std::begin(c); i != std::end(c); ++i)
        {
            std::cout << *i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}