//
// Created by chronomancer on 12/9/15.
//

#ifndef ALGSSTEPIC_CALCULATOR_HPP
#define ALGSSTEPIC_CALCULATOR_HPP

#include <vector>
#include <limits>

class Calculator
{
public:
    enum Operation
    {
        SUB_1,
        MULT_2,
        MULT_3
    };

public:
    static int min(int a, int b, int c)
    {
        return std::min(std::min(a, b), c);
    }

    static int div3(int n, const std::vector<int>& d)
    {
        return (n % 3 == 0) ? d[n / 3] : std::numeric_limits<int>::max();
    }

    static int div2(int n, const std::vector<int>& d)
    {
        return (n % 2 == 0) ? d[n / 2] : std::numeric_limits<int>::max();
    }

    static std::vector<int> recalc(int n)
    {
        std::vector<int> d(n + 1);
        std::vector<Operation> h(n + 1);
        d[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            int d3 = div3(i, d);
            int d2 = div2(i, d);
            int minval = min(d3, d2, d[i - 1]);
            d[i] = 1 + minval;

            if (minval == d3)
            {
                h[i] = MULT_3;
            }
            else if (minval == d2)
            {
                h[i] = MULT_2;
            }
            else
            {
                h[i] = SUB_1;
            }
        }

        std::vector<int> numbers;
        while (n != 0)
        {
            numbers.push_back(n);
            switch (h[n])
            {
                case MULT_3 :
                    n /= 3;
                    break;
                case MULT_2 :
                    n /= 2;
                    break;
                default :
                    --n;
                    break;
            }
        }

        return numbers;
    }
};
#endif //ALGSSTEPIC_CALCULATOR_HPP
