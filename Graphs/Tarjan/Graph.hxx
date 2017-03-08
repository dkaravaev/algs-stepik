//
// Created by dmitry on 10.03.16.
//

#ifndef TARJAN_GRAPH_HXX_HXX
#define TARJAN_GRAPH_HXX_HXX

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

    void find_cut_points(std::set<int>& points)
    {
        k = std::vector<int>(V);
        l = std::vector<int>(V);
        parent = std::vector<int>(V);
        std::vector<int> visited(V);
        int croot = 0;

        explore(ROOT_VERTEX, visited, points, croot);

        if (croot >= 2)
        {
            points.insert(ROOT_VERTEX);
        }

        for (uint v = 1; v < V; ++v)
        {
            for (std::list<uint>::iterator i = ConnLists[v].begin();
                 i != ConnLists[v].end(); ++i)
            {
                if (l[*i] >= k[v] && parent[*i] == v)
                {
                    points.insert(v);
                }
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
    void explore(uint v, std::vector<int>& visited, std::set<int>& points, int& croot)
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
                if (v == ROOT_VERTEX)
                {
                    ++croot;
                    explore(*i, visited, points, croot);
                }
                else
                {
                    parent[*i] = v;
                    explore(*i, visited, points, croot);
                    l[v] = std::min(l[v], l[*i]);
                }
            }
            else
            {
                l[v] = std::min(l[v], k[*i]);
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

#endif //TARJAN_GRAPH_HXX_HXX
