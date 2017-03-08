//
// Created by chronomancer on 11/17/15.
//

#ifndef ALGSSTEPIC_HUFFMANTREE_HPP
#define ALGSSTEPIC_HUFFMANTREE_HPP

#include <string>
#include <map>
#include <queue>

class HuffmanTree
{
public:
    static std::map<std::string, char> reversecodes(const std::map<char, std::string>& codes)
    {
        std::map<std::string, char> rcodes;
        for (auto it = codes.cbegin(); it != codes.cend(); ++it)
        {
            rcodes[it->second] = it->first;
        }

        return rcodes;
    }

    static std::map<char, unsigned> fdistribution(const std::string& str)
    {
        std::map<char, unsigned> chars;
        for (unsigned i = 0; i < str.size(); ++i)
        {
            if (!chars.count(str[i]))
            {
                chars[str[i]] = 1;
            }
            else
            {
                ++chars[str[i]];
            }
        }

        return chars;
    }

    static std::map<char, std::string> build(const std::map<char, unsigned >& chars)
    {
        std::map<char, std::string> codes;
        if (chars.size() == 1)
        {
            codes[chars.begin()->first] = "0";
            return codes;
        }
        HuffmanNode* root = nullptr;
        std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, HuffmanNode::PointerComparator> queue;

        std::vector<HuffmanNode*> leafs;
        for (auto it = chars.cbegin(); it != chars.cend(); ++it)
        {
            leafs.push_back(new HuffmanNode(*it));
            queue.push(leafs.back());
        }

        while (queue.size() != 1)
        {
            auto min1 = queue.top();
            queue.pop();
            auto min2 = queue.top();
            queue.pop();

            min1->addbit('0');
            min2->addbit('1');

            unsigned freq = min1->data.second + min2->data.second;
            queue.push(new HuffmanNode(SymbolFreq('\0', freq), "", min1, min2));
        }

        root = queue.top();
        queue.pop();
        for (auto it = leafs.begin(); it != leafs.end(); ++it)
        {
            codes[(*it)->data.first] = (*it)->code;
        }

        delete root;
        return codes;
    }

    static std::string encode(const std::string& str, const std::map<char, std::string>& codes)
    {
        std::string encoded = "";
        for (int i = 0; i < str.size(); ++i)
        {
            encoded += codes.at(str[i]);
        }

        return encoded;
    }

    static std::string decode(const std::string& str, const std::map<std::string, char>& codes)
    {
        std::string decoded = "";
        for (int i = 0; i < str.size(); )
        {
            std::string code = "";
            do
            {
                code += str[i];
                ++i;
            }
            while (!codes.count(code));
            decoded += codes.at(code);
        }

        return decoded;
    }

private:
    using SymbolFreq = std::pair<char, unsigned>;

    struct HuffmanNode
    {
    public:
        HuffmanNode(SymbolFreq data, std::string code = "",
                    HuffmanNode* left = nullptr, HuffmanNode* right = nullptr)
                : data(data), code(code)
                , left(left), right(right)
        {

        }

        bool operator>(const HuffmanNode& rhs) const
        {
            return data.second > rhs.data.second;
        }

        void addbit(char c)
        {
            code = c + code;
            if (left != nullptr)
            {
                left->addbit(c);
            }

            if (right != nullptr)
            {
                right->addbit(c);
            }
        }

        ~HuffmanNode()
        {
            delete left;
            delete right;
        }

    public:
        struct PointerComparator
        {
            bool operator() (HuffmanNode* lhs, HuffmanNode* rhs)
            {
                return *lhs > *rhs;
            }
        };

    public:
        SymbolFreq data;
        std::string code;
        HuffmanNode* left;
        HuffmanNode* right;
    };
};


#endif //ALGSSTEPIC_HUFFMANTREE_HPP
