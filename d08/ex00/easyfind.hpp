
#ifndef     EASYFIND_HPP
# define    EASYFIND_HPP

template<typename T>
typename T::const_iterator                    easyfind(T const & arr, int num)
{
    typename T::const_iterator  it = arr.begin();
    typename T::const_iterator  end = arr.end();
    while (it != end)
    {
        if (*it == num)
            break ;
        it++;
    }
    return (it);
}

#endif