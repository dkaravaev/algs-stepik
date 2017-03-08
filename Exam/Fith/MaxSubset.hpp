//
// Created by chronomancer on 12/20/15.
//

#ifndef ALGSSTEPIC_MAXSUBSET_HPP
#define ALGSSTEPIC_MAXSUBSET_HPP

#include <vector>
#include <cstdint>
#include <algorithm>

class MaxSubset
{
public:
    static int count(std::vector<int64_t>& a, int64_t x)
    {
        std::sort(a.begin(), a.end());
        int max = 0;
        for (auto it = a.begin(); it != a.end(); ++it)
        {
            auto up_it = std::upper_bound(it, a.end(), x - *it);
            if (up_it != a.end())
            {
                int val;
                if (up_it == it)
                {
                    val =  a.end() - up_it;
                }
                else
                {
                    val = a.end() - up_it + 1;
                }

                max = std::max(max, val);
            }
        }

        return max;
    }
};

#endif //ALGSSTEPIC_MAXSUBSET_HPP
