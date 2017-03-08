//
// Created by chronomancer on 12/6/15.
//

#ifndef ALGSSTEPIC_FORTH_HPP
#define ALGSSTEPIC_FORTH_HPP

#include <set>
#include <vector>
#include <cstdint>
#include <algorithm>

class MinMaxSubtraction
{
public:
    static double result(std::multiset<double, std::greater<double>>& maxs, std::multiset<double>& mins, int n)
    {
        for (int i = 1; i <= n - 1; ++i)
        {
            double min = *mins.begin();
            double max = *maxs.begin();

            double num = (min + max) / 2;
            mins.erase(mins.begin());
            maxs.erase(maxs.begin());
            mins.erase(max);
            maxs.erase(min);

            mins.insert(num);
            maxs.insert(num);
        }

        return *maxs.begin();
    }
};
#endif //ALGSSTEPIC_FORTH_HPP
