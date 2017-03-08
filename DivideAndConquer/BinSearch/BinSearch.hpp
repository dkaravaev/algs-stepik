//
// Created by home on 19.11.15.
//

#ifndef AUTOMATA_BINSEARCH_HPP
#define AUTOMATA_BINSEARCH_HPP

#include <vector>
#include <cstdint>

template <typename T>
class BinSearch
{
public:
    static int search(const std::vector<T>& v, int begin, int end, uint64_t key)
    {
        if (begin == end)
        {
            return (v[begin] == key) ? begin : -1;
        }

        int mid = (begin + end) / 2;
        if (v[mid] == key)
        {
            return mid;
        }
        else if (v[mid] < key)
        {
            return search(v, mid + 1, end, key);
        }
        else
        {
            return search(v, begin, mid, key);
        }
    }
};

#endif //AUTOMATA_BINSEARCH_HPP
