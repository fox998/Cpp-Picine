
#ifndef     SPAN_HPP
# define    SPAN_HPP

class       Span
{
    private:
        int                 *_arr;
        unsigned int        _size;
        int                 _shortestSpan;
        int                 _longestSpan;

        Span();
    public:
        ~Span();
        Span(unsigned int n);

        void        addNumber(int val);

        int         shortestSpan();
        int         longestSpan();
};

#endif
