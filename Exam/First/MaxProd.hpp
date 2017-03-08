//
// Created by chronomancer on 12/20/15.
//

#ifndef ALGSSTEPIC_FIRST_HPP
#define ALGSSTEPIC_FIRST_HPP

#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

class MaxProd
{
public:
    static uint64_t count(std::vector<uint64_t>& a)
    {
        int max1 = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[max1] < a[i])
            {
                max1 = i;
            }
        }

        int max2 = (max1 == 0) ? 1 : 0;
        for (int i = 0; i < a.size(); ++i)
        {
            if (i == max1)
            {
                continue;
            }

            if (a[max2] < a[i])
            {
                max2 = i;
            }
        }

        return a[max1] * a[max2];
    }
};
#endif //ALGSSTEPIC_FIRST_HPP
