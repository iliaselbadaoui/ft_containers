namespace ft
{
	# include <memory>
	# include "iterator_traits.hpp"

	template< class T, Allocator=std::allocator<T>>
	class vector
	{
	private:
		typedef typename T												value_type;
		typedef	typename std::allocator<value_type>::pointer			pointer;
		typedef	typename std::allocator<value_type>::const_pointer		const_pointer;
		typedef	typename std::allocator<value_type>::reference			reference;
		typedef	typename std::allocator<value_type>::const_reference	const_reference;
	public:
		vector()
		{

		};
		~vector()
		{

		};
	};
	
}