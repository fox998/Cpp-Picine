
#ifndef     ARRAY_TEMPLATE_HPP
# define    ARRAY_TEMPLATE_HPP

#include    <exception>
#include	<iostream>
template<typename T>
class       Array
{
	T               *_arr;
	unsigned int    _size;

	public:
		Array<T>(): _arr(NULL), _size(0){}
		~Array<T>(){
			if (this->_arr)
			{
				delete [] this->_arr;
				_size = 0;
			}
		}
		Array<T>(unsigned int n): _arr(new T[n]), _size(n){}
		Array<T>(Array<T> const & a){
			*this = a;
		}


		Array<T> &  operator=(Array<T> const & a){
			delete [] this->_arr;
			this->_arr = NULL;

			if ((this->_size = a._size))
			{
				this->_arr = new T[this->_size];
			    for (unsigned int i = 0; i < _size; i++)
		        	_arr[i] = a._arr[i];
			}

			return *this;
		}

		T &  operator[](unsigned int i){
			if (i < this->_size)
				return this->_arr[i];
			else
				throw std::exception();
		}

		unsigned int    size() const{return this->_size; }
};

#endif