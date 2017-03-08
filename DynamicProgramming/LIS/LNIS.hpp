//
// Created by chronomancer on 12/8/15.
//

#ifndef ALGSSTEPIC_LIS_HPP
#define ALGSSTEPIC_LIS_HPP

#include <vector>
#include <cstdint>
#include <algorithm>
#include <numeric>

class LNIS
{
public:
    static std::vector<int> find(const std::vector<int64_t>& numbers)
    {
        std::vector<int64_t> d(numbers.size() + 1, std::numeric_limits<int64_t>::max());
        std::vector<int> elems(d.size());
        std::vector<int> prev(numbers.size());

        d[0] = std::numeric_limits<int64_t>::min();
        for (int i = 0; i < numbers.size(); ++i)
        {
            int j = int(std::upper_bound(d.begin(), d.end(), numbers[i]) - d.begin());
            if (d[j - 1] <= numbers[i] && numbers[i] <= d[j])
            {
                prev[i] = elems[j - 1];
                d[j] = numbers[i];
                elems[j] = i;
            }
        }

        int k = 0;
        for (int i = d.size() - 1; i >= 0; --i)
        {
            if (d[i] != std::numeric_limits<int64_t>::max())
            {
                k = i;
                break;
            }
        }

        std::vector<int> ans(k);
        int j = elems[k];
        for (int i = k - 1; i >= 0; --i)
        {
            ans[i] = j;
            j = prev[j];
        }

        return ans;
    }
};

#endif //ALGSSTEPIC_LIS_HPP
