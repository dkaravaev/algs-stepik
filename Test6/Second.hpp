//
// Created by chronomancer on 12/6/15.
//

#ifndef ALGSSTEPIC_SECOND_HPP
#define ALGSSTEPIC_SECOND_HPP

#include <cstdint>
#include <vector>
#include <algorithm>

#include <cstdint>
#include <vector>
#include <algorithm>

class SumDecomp
{
public:
    static uint64_t count(uint64_t w, std::vector<uint64_t>& v, std::vector<uint64_t>& sumds)
    {
        std::sort(v.begin(), v.end(), [](uint64_t x, uint64_t y)
        {
            return x > y;
        });

        uint64_t k = 0;
        for (uint32_t i = 0; i < v.size(); )
        {
            if (w == 0)
            {
                break;
            }

            if (w == w % v[i])
            {
                ++i;
                continue;
            }

            uint64_t c = w / v[i];
            k += c;
            for (uint64_t j = 0; j < c; ++j)
            {
                sumds.push_back(v[i]);
            }
            w %= v[i];
        }

        return k;
    }
};
#endif //ALGSSTEPIC_SECOND_HPP
