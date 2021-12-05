namespace ft
{
	# include <iostream>
	
	template<class T>
	struct iterator_traits<T*>
	{
		typedef	std::ptrdiff_t		difference_type;
		typedef	T					value_type;
		typedef T*					pointer;
		typedef T&					reference;
	}
}