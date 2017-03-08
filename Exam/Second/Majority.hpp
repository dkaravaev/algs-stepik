//
// Created by chronomancer on 12/20/15.
//

#ifndef ALGSSTEPIC_MAJORITY_HPP
#define ALGSSTEPIC_MAJORITY_HPP

#include <vector>
#include <cstdint>
#include <map>

class Majority
{
public:
    static bool check(const std::vector<int64_t>& a)
    {
        std::map<int64_t, int> freq;
        for (int i = 0; i < a.size(); ++i)
        {
            if (freq.count(a[i]))
            {
                freq[a[i]]++;
            }
            else
            {
                freq[a[i]] = 1;
            }
        }

        int half = a.size() / 2;
        for (auto i = freq.begin(); i != freq.end(); ++i)
        {
            if (i->second > half)
            {
                return true;
            }
        }

        return false;
    }
};
#endif //ALGSSTEPIC_MAJORITY_HPP
