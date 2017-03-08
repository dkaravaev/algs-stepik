//
// Created by chronomancer on 11/14/15.
//

#ifndef ALGSSTEPIC_BAG_HPP
#define ALGSSTEPIC_BAG_HPP

#include <vector>
#include <algorithm>

using ull = unsigned long long;

class Bag
{
public:
    struct Product
    {
    public:
        Product(ull c, ull w)
            : c(c), w(w)
            , cpw(static_cast<double>(c / w))
        {

        }

    public:
        ull c;
        ull w;
        double cpw;
    };

public:
    Bag(ull W)
        : W(W)
    {

    }

    double packBag(const std::vector<Product>& products)
    {
        double sum = 0;
        std::sort(products.begin(), products.end(), [] (const Product& lhs, const Product& rhs) {
            return lhs.cpw <= rhs.cpw;
        });

        int i = 0;
        while (i < products.size() && W > 0)
        {
            if (products[i].w >= W)
            {
                sum += products[i].cpw * W;
            }
            else
            {
                sum += products[i].c;
            }

            W -= products[i].w;
            ++i;
        }

        return sum;
    }

private:
    ull W;
};

#endif //ALGSSTEPIC_BAG_HPP
