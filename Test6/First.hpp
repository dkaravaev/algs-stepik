//
// Created by chronomancer on 12/6/15.
//

#ifndef ALGSSTEPIC_FIRST_HPP
#define ALGSSTEPIC_FIRST_HPP

#include <cstdint>

class LCM
{
public:
    static uint64_t gcd(uint64_t a, uint64_t b)
    {
        if (b == 0)
            return a;
        else return gcd(b, a % b);
    }

    static uint64_t count(uint64_t a, uint64_t b)
    {
        return a / gcd(a, b) * b;
    }
};


#endif //ALGSSTEPIC_FIRST_HPP
