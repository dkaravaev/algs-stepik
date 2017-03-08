//
// Created by chronomancer on 11/25/15.
//

#ifndef ALGSSTEPIC_INVERTIONS_HPP
#define ALGSSTEPIC_INVERTIONS_HPP

#include <cstdint>
#include <vector>
#include <limits>
#include <iostream>

template <typename T>
class Invertions
{
public:
    static uint64_t count(std::vector<T>& array, uint64_t begin, uint64_t end)
    {
        uint64_t cin = 0;
        if (begin < end)
        {
            uint64_t mid = (uint64_t)(begin + end) / 2;
            cin = count(array, begin, mid) + count(array, mid + 1, end)
                  + merge(array, begin, mid, end);
        }

        return cin;
    }

private:
    static uint64_t merge(std::vector<T>& array, uint64_t begin, uint64_t mid, uint64_t end)
    {
        uint64_t cin = 0;
        std::vector<T> left;
        std::vector<T> right;

        for (uint64_t i = begin; i <= mid; ++i)
        {
            left.push_back(array[i]);
        }
        left.push_back(std::numeric_limits<T>::max());

        for (uint64_t i = mid + 1; i <= end; ++i)
        {
            right.push_back(array[i]);
        }
        right.push_back(std::numeric_limits<T>::max());

        uint32_t i = 0;
        uint32_t j = 0;
        bool counted = false;
        for (uint64_t k = begin; k <= end; ++k)
        {
            if (!counted && left[i] > right[j])
            {
                cin += (left.size() - 1) - i;
                counted = true;
            }

            if (left[i] <= right[j])
            {
                array[k] = left[i];
                ++i;
            }
            else
            {
                array[k] = right[j];
                counted = false;
                ++j;
            }
        }

        return cin;
    }
};


#endif //ALGSSTEPIC_INVERTIONS_HPP
