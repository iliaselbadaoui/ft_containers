namespace ft
{
	# include <memory>
	# include "iterator_traits.hpp"

	template< class T, Allocator=std::allocator<T>>
	class vector
	{
	private:
		typedef	std::allocator<T>::pointer		pointer;
	public:
		vector()
		{

		};
		~vector()
		{

		};
	};
	
}