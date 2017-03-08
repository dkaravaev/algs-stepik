//
// Created by chronomancer on 11/25/15.
//

#ifndef ALGSSTEPIC_COUNTSORT_HPP
#define ALGSSTEPIC_COUNTSORT_HPP

#include <vector>
#include <stdint.h>

template <typename T>
class CountSort
{
public:
    static std::vector<T> sort(const std::vector<T>& array, T bound)
    {
        std::vector<T> b(array.size());
        std::vector<T> c(bound + 1, 0);
        for (uint32_t i = 0; i < array.size(); ++i)
        {
            ++c[array[i]];
        }

        for (uint32_t i = 1; i <= bound; ++i)
        {
            c[i] += c[i - 1];
        }

        for (int64_t i = array.size() - 1; i >= 0; --i)
        {
            b[c[array[i]] - 1] = array[i];
            --c[array[i]];
        }

        return b;
    }
};
#endif //ALGSSTEPIC_COUNTSORT_HPP
