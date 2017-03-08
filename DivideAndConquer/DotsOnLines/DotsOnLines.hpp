//
// Created by chronomancer on 11/25/15.
//

#ifndef ALGSSTEPIC_DOTSONLINES_HPP
#define ALGSSTEPIC_DOTSONLINES_HPP

#include <vector>
#include <cstdint>
#include <algorithm>

class DotsOnLines
{
public:
    using Point = int64_t;

    struct Line
    {
    public:
        Line(Point begin = 0, Point end = 0)
                : begin(begin), end(end)
        {

        }

        bool contains(Point point) const
        {
            return point >= begin && point <= end;
        }

    public:
        Point begin;
        Point end;
    };

public:
    static std::vector<Line> sort(std::vector<Line>& blines)
    {
        std::sort(blines.begin(), blines.end(), [](const Line& lhs, const Line& rhs) {
            return lhs.begin < rhs.begin;
        });

        std::vector<Line> elines(blines);

        std::sort(elines.begin(), elines.end(), [](const Line& lhs, const Line& rhs) {
            return lhs.end < rhs.end;
        });

        return elines;
    }

    static int32_t count(const std::vector<Line>& blines, const std::vector<Line>& elines, Point point)
    {
        auto i = begin_search(blines, 0, blines.size() - 1, point);
        auto j = end_search(elines, 0, elines.size() - 1, point);
        if (i == -1)
        {
            return 0;
        }

        if (j == -1)
        {
            return i + 1;
        }

        return i - j;
    }

    static int32_t count_naive(const std::vector<Line>& lines, Point point)
    {
        int i = 0;
        for (auto l : lines)
        {
            if (point >= l.begin && point <= l.end)
            {
                ++i;
            }
        }

        return i;
    }

private:
    static int32_t begin_search(const std::vector<Line>& lines, uint32_t begin, uint32_t end, Point point)
    {
        if (begin == end)
        {
            if (point >= lines[begin].begin)
            {
                return begin;
            }
            else
            {
                return -1;
            }
        }

        uint32_t mid = (uint32_t)(begin + end) / 2;
        if (point >= lines[mid].begin)
        {
            if (mid == lines.size() - 1)
            {
                return mid;
            }

            if (point < lines[mid + 1].begin)
            {
                return mid;
            }

            return begin_search(lines, mid + 1, end, point);
        }
        else
        {
            return begin_search(lines, begin, mid, point);
        }
    }

    static int32_t end_search(const std::vector<Line>& lines, uint32_t begin, uint32_t end, Point point)
    {
        if (end == begin)
        {
            if (point > lines[begin].end)
            {
                return end;
            }
            else
            {
                return -1;
            }
        }

        uint32_t mid = (uint32_t)(begin + end) / 2;
        if (point > lines[mid].end)
        {
            if (mid == lines.size() - 1)
            {
                return mid;
            }

            if (point <= lines[mid + 1].end)
            {
                return mid;
            }

            return end_search(lines, mid + 1, end, point);
        }
        else
        {
            return end_search(lines, begin, mid, point);
        }
    }
};
#endif //ALGSSTEPIC_DOTSONLINES_HPP
