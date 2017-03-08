//
// Created by chronomancer on 11/10/15.
//

#ifndef ALGSSTEPIC_FIBONACCI_HPP
#define ALGSSTEPIC_FIBONACCI_HPP

using ull = unsigned long long;

class Fibonacci
{
public:
    static ull fib(ull n)
    {
        ull fib0 = 0;
        ull fib1 = 1;
        ull fibn;
        if (n <= 1)
        {
            return n == 1 ? fib1 : fib0;
        }

        for (ull i = 2; i <= n; ++i)
        {
            fibn = fib0 + fib1;
            ull temp = fib1;
            fib1 = fibn;
            fib0 = temp;
        }

        return fibn;
    }

    static ull fib(ull n, ull m)
    {
        ull fib0 = 0;
        ull fib1 = 1;
        ull fibn;
        if (n <= 1)
        {
            return n == 1 ? fib1 : fib0;
        }

        for (ull i = 2; i <= n; ++i)
        {
            fibn = (fib0 + fib1) % m;
            ull temp = fib1;
            fib1 = fibn;
            fib0 = temp;
        }

        return fibn;
    }

    static ull fib_pizano(ull n, ull m)
    {
        ull fib0 = 0;
        ull fib1 = 1;
        ull fibn;
        if (n <= 1)
        {
            return n == 1 ? fib1 : fib0;
        }

        ull period = 0;
        do
        {
            fibn = (fib0 + fib1) % m;
            fib0 = fib1;
            fib1 = fibn;
            ++period;
        } while (fib0 != 0 || fib1 != 1);

        for (ull i = 2; i <= n % period; ++i)
        {
            fibn = (fib0 + fib1) % m;
            ull temp = fib1;
            fib1 = fibn;
            fib0 = temp;
        }

        return fibn;
    }
};


#endif //ALGSSTEPIC_FIBONACCI_HPP
