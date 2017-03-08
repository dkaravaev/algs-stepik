//
// Created by chronomancer on 12/20/15.
//

#ifndef ALGSSTEPIC_NUMSUM_HPP
#define ALGSSTEPIC_NUMSUM_HPP

#include <vector>
#include <cstdint>
#include <numeric>
#include <limits>

class NumSum
{
public:
    static const uint64_t limit = 1000000007;

public:
    static uint64_t count(int n)
    {
        std::vector<std::vector<uint64_t>> d(n + 1, std::vector<uint64_t>(n + 1, std::numeric_limits<uint64_t>::max()));
        return process(d, n, n);
    }

    static uint64_t process(std::vector<std::vector<uint64_t>>& d, int i, int j)
    {
        if (i < 0)
        {
            return 0;
        }

        if (d[i][j] != std::numeric_limits<uint64_t>::max())
        {
            return d[i][j];
        }

        if (i <= 1 || j == 1)
        {
            return 1;
        }

        d[i][j] = process(d, i, j - 1) % limit + process(d, i - j, j) % limit;
        return d[i][j];
    }
};
#endif //ALGSSTEPIC_NUMSUM_HPP
