
#include    <iostream>

template<typename T>
void                    iter(T 	arr[], int size, T (&f)(T & l))
{
	for (int i = 0; i < size; i++)
		f(++arr[i]);
}

template<typename T>
T                   prin(T & a)
{
	std::cout << a << " ";
	return (0);
}

int                     main()
{
	int          arr1[] = {1, 2, 3, 4 ,5};
	float        arr2[] = {1.42f, 2.42f, 3.42f, 4.42f ,5.42f};

	iter(arr1, 5, prin);
	std::cout << std::endl;
	std::cout << arr1[0] << std::endl;
	iter(arr2, 5, prin);
	std::cout << std::endl;
}
