#include <iostream>
#include <algorithm>
#include <queue>

class BiGraph
{
public:
    using Edge = std::pair<int, int>;

    enum
    {
        UNMATHCED = -1
    };

public:
    BiGraph(int v1, int v2, int e, const std::vector<Edge>& edges)
        : v1(v1), v2(v2), e(e)
        , G(v1 + v2, std::vector<int>())
        , match(v1 + v2, UNMATHCED)
        , marked(v1 + v2, false)
        , edge_to(v1 + v2, -1)
    {
        for (auto& edge: edges)
        {
            G[edge.first].push_back(edge.second);
            G[edge.second].push_back(edge.first);
        }
    }

    std::vector<int> min_vertex_cover()
    {
        int alpha = 0;
        while (has_augment_path())
        {
            int t = -1;
            for (int v = 0; v < v1 + v2; ++v)
            {
                if ((match[v] == UNMATHCED) && edge_to[v] != -1)
                {
                    t = v;
                    break;
                }
            }

            for (int v = t; v != -1; v = edge_to[edge_to[v]])
            {
                int w = edge_to[v];
                match[v] = w;
                match[w] = v;
            }

            ++alpha;
        }

        std::vector<int> mvc;
        for (int v = 0; v < v1; ++v)
        {
            if (!marked[v])
            {
                mvc.push_back(v);
            }
        }

        for (int v = v1; v < v1 + v2; ++v)
        {
            if (marked[v])
            {
                mvc.push_back(v);
            }
        }

        return mvc;
    }

private:
    bool has_augment_path()
    {
        for (int v = 0; v < (v1 + v2); ++v)
        {
            marked[v] = false;
            edge_to[v] = -1;
        }

        std::queue<int> queue;
        for (int v = 0; v < v1; ++v)
        {
            if (match[v] == UNMATHCED)
            {
                queue.push(v);
                marked[v] = true;
            }
        }

        while (!queue.empty())
        {
            int v = queue.front();
            queue.pop();
            for (int w : G[v])
            {
                if (is_residual(v, w))
                {
                    if (!marked[w])
                    {
                        edge_to[w] = v;
                        marked[w] = true;
                        if (match[w] == UNMATHCED)
                        {
                            return true;
                        }
                        queue.push(w);
                    }
                }
            }
        }

        return false;
    }

    bool is_residual(int v, int w)
    {
        if ((match[v] != w) &&  v < v1)
        {
            return true;
        }
        return (match[v] == w) && (v >= v1) && (v <= v1 + v2);
    }

private:
    int v1, v2, e;
    std::vector<std::vector<int>> G;
    std::vector<int> match;
    std::vector<int> marked;
    std::vector<int> edge_to;
};

int main()
{
    int v1, v2, e;
    std::vector<BiGraph::Edge> edges;
    std::cin >> v1 >> v2 >> e;
    for (int i = 0; i < e; ++i)
    {
        int v, u;
        std::cin >> v >> u;
        edges.emplace_back(v, u);
    }

    BiGraph G(v1, v2, e, edges);

    std::cout << v1 << " " << v2 << " " << e << std::endl;
    for (auto& edge: edges)
    {
        std::cout << edge.first << " " << edge.second << std::endl;
    }

    for (int v: G.min_vertex_cover())
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}