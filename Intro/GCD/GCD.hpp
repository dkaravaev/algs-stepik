//
// Created by chronomancer on 12/8/15.
//

#ifndef ALGSSTEPIC_GCD_HPP
#define ALGSSTEPIC_GCD_HPP

template <typename T>
class GCD
{
public:
    static T count(T a, T b)
    {
        if (b == 0)
            return a;
        else return count(b, a % b);
    }
};
#endif //ALGSSTEPIC_GCD_HPP
