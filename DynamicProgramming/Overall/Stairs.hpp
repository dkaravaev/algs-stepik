//
// Created by chronomancer on 12/9/15.
//

#ifndef ALGSSTEPIC_STAIRS_HPP
#define ALGSSTEPIC_STAIRS_HPP

#include <cstdint>
#include <vector>
#include <limits>

class Stairs
{
public:
    static int64_t minimize(const std::vector<int64_t>& stairs)
    {
        std::vector<int64_t> d(stairs.size() + 1, std::numeric_limits<int64_t>::max());
        d[0] = 0;
        d[1] = stairs[0];

        for (int i = 2; i < d.size(); ++i)
        {
            d[i] = stairs[i - 1] + std::max(d[i - 1], d[i - 2]);
        }

        return d.back();
    }
};

#endif //ALGSSTEPIC_STAIRS_HPP
