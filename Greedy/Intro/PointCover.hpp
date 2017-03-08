//
// Created by chronomancer on 11/14/15.
//

#ifndef ALGSSTEPIC_POINTCOVER_HPP
#define ALGSSTEPIC_POINTCOVER_HPP

#include <vector>
#include <algorithm>

using ull = unsigned long long;

class PointCover
{
public:
    using Point = ull;

public:
    struct Segment
    {
    public:
        Segment(ull begin, ull end)
                : begin(begin)
                , end(end)
        {

        }

    public:
        Point begin;
        Point end;
    };

public:
    static std::vector<Point> coverSegments(std::vector<Segment>& segments)
    {
        std::sort(segments.begin(), segments.end(), [] (const Segment& lhs, const Segment& rhs) {
            return lhs.end <= rhs.end;
        });

        std::vector<Point> points;
        for (int i = 0; i < segments.size(); )
        {
            points.push_back(segments[i].end);
            do
            {
                ++i;
            } while (i < segments.size() &&
                     (points.back() >= segments[i].begin && points.back() <= segments[i].end));
        }

        return points;
    }
};

#endif //ALGSSTEPIC_POINTCOVER_HPP
