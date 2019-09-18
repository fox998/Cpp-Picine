
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
        ~Span();

        Span(Span const& other);
        Span(unsigned int n = 0);

        Span& operator=(Span const& other);


        void        addNumber(int val);

        int         shortestSpan() const;
        int         longestSpan() const;
};