//
// Created by chronomancer on 12/9/15.
//

#ifndef ALGSSTEPIC_EDITINGDISTANCE_HPP
#define ALGSSTEPIC_EDITINGDISTANCE_HPP

#include <string>
#include <vector>
#include <limits>

class EditingDistance
{
public:
    static int diff(char a, char b)
    {
        return a != b;
    }

    static int min(int a, int b, int c)
    {
        return std::min(std::min(a, b), c);
    }

    static int count(const std::string& a, const std::string& b)
    {
        std::vector<std::vector<int>> d(a.size() + 1, std::vector<int>(b.size() + 1));
        for (int i = 0; i <= a.size(); ++i)
        {
            d[i][0] = i;
        }

        for (int j = 0; j <= b.size(); ++j)
        {
            d[0][j] = j;
        }

        for (int i = 1; i <= a.size(); ++i)
        {
            for (int j = 1; j <= b.size(); ++j)
            {
                d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + diff(a[i - 1], b[j - 1]));
            }
        }

        return d.back().back();
    }
};
#endif //ALGSSTEPIC_EDITINGDISTANCE_HPP
