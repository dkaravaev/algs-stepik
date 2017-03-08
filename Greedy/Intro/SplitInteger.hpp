//
// Created by chronomancer on 11/14/15.
//

#ifndef ALGSSTEPIC_SPLITINTEGER_HPP
#define ALGSSTEPIC_SPLITINTEGER_HPP

#include <vector>

using ull = unsigned long long;

class SplitInteger
{
public:
    static void split(std::vector<ull>& integers, ull n)
    {
        ull sum = 0;
        for (ull i = 1; i <= n; ++i)
        {
            if (sum == n)
            {
                break;
            }

            sum += i;
            if (sum > n)
            {
                integers.back() = i;
                sum -= (i - 1);
            }
            else
            {
                integers.push_back(i);
            }
        }
    }
};

#endif //ALGSSTEPIC_SPLITINTEGER_HPP
