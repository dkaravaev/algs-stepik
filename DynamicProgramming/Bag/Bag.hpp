//
// Created by chronomancer on 12/9/15.
//

#ifndef ALGSSTEPIC_BAG_HPP
#define ALGSSTEPIC_BAG_HPP

#include <vector>

class Bag
{
public:
    static int fill(int W, const std::vector<int>& w)
    {
        std::vector<std::vector<int>> d(W + 1, std::vector<int>(w.size() + 1, 0));
        for (int i = 1; i <= w.size(); ++i)
        {
            for (int j = 1; j <= W; ++j)
            {
                d[j][i] = d[j][i - 1];
                if (w[i - 1] <= j)
                {
                    d[j][i] = std::max(d[j][i], d[j - w[i - 1]][i - 1] + w[i - 1]);
                }
            }
        }

        return d.back().back();
    }
};
#endif //ALGSSTEPIC_BAG_HPP
