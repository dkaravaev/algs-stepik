//
// Created by chronomancer on 12/8/15.
//

#ifndef ALGSSTEPIC_LDS_HPP
#define ALGSSTEPIC_LDS_HPP

#include <map>
#include <cstdint>
#include <algorithm>

class LDS
{
public:
    static int find(const std::vector<uint64_t>& numbers)
    {
        std::vector<int> d(numbers.size(), 1);
        for (int i = 0; i < numbers.size(); ++i)
        {
            for (int j = 0; j <= i - 1; ++j)
            {
                if ((numbers[i] % numbers[j] == 0) && ((d[j] + 1) > d[i]))
                {
                    d[i] = d[j] + 1;
                }
            }
        }

        return *std::max_element(d.begin(), d.end());
    }
};
#endif //ALGSSTEPIC_LDS_HPP
