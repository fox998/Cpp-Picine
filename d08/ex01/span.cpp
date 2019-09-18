#include "span.hpp"
#include <assert.h>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <functional>


Span::~Span(){}


Span::Span(Span const& other)
    : m_Arr(other.m_Arr)
    , m_MaxSize(other.m_MaxSize)
{}

Span& Span::operator=(Span const& other)
{
    m_Arr = other.m_Arr;
    m_MaxSize = other.m_MaxSize;

    return *this;
}


struct SpanWithPreviouse
{
    int previouse;

    int operator() (int next)
    {
        int const span = std::abs(this->previouse - next);
        this->previouse = next;
        return span;
    }
};



void throw_if(bool exp, std::string const& what = "")
{
    if (exp){
        throw what;
    }
}


Span::Span(unsigned int n):
    m_MaxSize(n)
{
    m_Arr.reserve(m_MaxSize);
}

void Span::addNumber(int val)
{
    throw_if(m_Arr.size() > m_MaxSize);
    m_Arr.push_back(val);
}

int Span::shortestSpan() const
{
    throw_if(m_Arr.size() < 2);
    
    Span::AttT tempArr = m_Arr;
    Span::AttT spans;
    spans.reserve(tempArr.size());

    std::sort(tempArr.begin(), tempArr.end());

    SpanWithPreviouse span_with_previouse;
    span_with_previouse.previouse = tempArr.front();

    std::transform(tempArr.begin() + 1, tempArr.end(), spans.begin(),
        span_with_previouse
    );

    std::sort(spans.begin(), spans.end());
    return spans.front();
}

int Span::longestSpan() const
{
    throw_if(m_Arr.size() < 2);

    std::vector<int> temp_arr (m_Arr.begin(), m_Arr.end());
    std::sort(temp_arr.begin(), temp_arr.end());

    return temp_arr.back() - temp_arr.front();
}


