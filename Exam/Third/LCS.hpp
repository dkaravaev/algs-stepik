//
// Created by chronomancer on 12/20/15.
//

#ifndef ALGSSTEPIC_LCS_HPP
#define ALGSSTEPIC_LCS_HPP


#include <vector>

class LCS
{
public:
    static int count(const std::vector<int>& a, const std::vector<int>& b)
    {
        std::vector<std::vector<int>> d(a.size() + 1, std::vector<int>(b.size() + 1, 0));
        for (int i = 1; i <= a.size(); ++i)
        {
            for (int j = 1; j <= b.size(); ++j)
            {
                if (a[i - 1] == b[j - 1])
                {
                    d[i][j] = d[i - 1][j - 1] + 1;
                }
                else if (d[i - 1][j] >= d[i][j - 1])
                {
                    d[i][j] = d[i - 1][j];
                }
                else
                {
                    d[i][j] = d[i][j - 1];
                }
            }
        }

        return d[a.size()][b.size()];
    }
};
#endif //ALGSSTEPIC_LCS_HPP
