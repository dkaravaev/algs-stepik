//
// Created by chronomancer on 11/18/15.
//

#ifndef ALGSSTEPIC_PRIORITYQUEUE_HPP
#define ALGSSTEPIC_PRIORITYQUEUE_HPP

#include <vector>
#include <iterator>
#include <algorithm>


typedef unsigned long ulong;
typedef long long ull;

template<typename T>
class Heap
{
public:
    static ulong parent(ulong index)
    {
        return index / 2;
    }

    static ulong left(ulong index)
    {
        if (index == 0)
        {
            return 1;
        }

        return 2 * index;
    }

    static ulong right(ulong index)
    {
        if (index == 0)
        {
            return 2;
        }

        return 2 * index + 1;
    }

public:
    Heap<T>()
    {

    }

    Heap<T>(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end)
    {
        for (auto i = begin; i != end; ++i)
        {
            array.push_back(*i);
        }
    }

    std::vector<T> sort()
    {
        build_max_heap();
        for (ulong i = array.size() - 1; i > 0; --i)
        {
            std::swap(array[0], array[i]);
            --heap_size;
            max_heapify(0);
        }

        return array;
    }

    T extract_max()
    {
        if (heap_size == 0)
        {
            return T();
        }

        T max = array[0];
        array[0] = array[heap_size - 1];
        --heap_size;
        array.pop_back();
        max_heapify(0);
        return max;
    }

    void insert(T key)
    {
        array.push_back(std::numeric_limits<T>::min());
        ++heap_size;
        increase_key(heap_size - 1, key);
    }

private:
    void max_heapify(ulong index)
    {
        ulong l = left(index);
        ulong r = right(index);
        ulong max = index;

        if ((l < heap_size) && (array[l] > array[max]))
        {
            max = l;
        }

        if ((r < heap_size) && (array[r] > array[max]))
        {
            max = r;
        }

        if (max != index)
        {
            std::swap(array[index], array[max]);
            max_heapify(max);
        }
    }

    void increase_key(ulong index, T key)
    {
        if (array[index] > key)
        {
            return;
        }

        array[index] = key;
        while (index > 0 && array[parent(index)] < array[index])
        {
            std::swap(array[parent(index)], array[index]);
            index = parent(index);
        }
    }

    void build_max_heap()
    {
        heap_size = array.size();
        for (ulong i = heap_size / 2; i >= 0; --i)
        {
            max_heapify(i);
        }
    }

private:
    std::vector<T> array;
    ulong heap_size = 0;
};

using PriorityQueue = Heap<ull>;

#endif //ALGSSTEPIC_PRIORITYQUEUE_HPP
