//
// Created by chronomancer on 12/6/15.
//

#ifndef ALGSSTEPIC_THIRD_HPP
#define ALGSSTEPIC_THIRD_HPP

#include <string>
#include <cstdint>

class BitStringInvertions
{
public:
    static uint64_t count(const std::string& str)
    {
        uint64_t k = 0;
        for (int i = 0; i < str.size(); )
        {
            bool zero_prefix = false;
            while (str[i]  == '0' && i < str.size())
            {
                zero_prefix = true;
                ++i;
            }

            if (i == str.size())
            {
                break;
            }

            while (str[i] == '1' && i < str.size())
            {
                ++i;
            }

            if (zero_prefix)
            {
                k += 2;
            }
            else
            {
                ++k;
            }
        }

        return k;
    }
};

#endif //ALGSSTEPIC_THIRD_HPP
