
#pragma once
#include <vector>

class       Span
{
    private:

        typedef  std::vector<int> AttT;
        AttT m_Arr;
        std::size_t m_MaxSize;

        std::vector<int> GetSpans() const;

    public:
        Span() {};
        ~Span() {};
        Span(unsigned int n);


        void        addNumber(int val);

        int         shortestSpan() const;
        int         longestSpan() const;
};