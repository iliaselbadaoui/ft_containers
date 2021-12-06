namespace ft
{
	# include <memory>
	# include "iterator_traits.hpp"

	template< class T,  class Allocator=std::allocator<T> >
	class vector
	{
		typedef 		 T									value_type;
        typedef 		 Allocator                          allocator_type;
		typedef	typename allocator_type::pointer			pointer;
		typedef	typename allocator_type::const_pointer		const_pointer;
		typedef	typename allocator_type::reference			reference;
		typedef	typename allocator_type::const_reference	const_reference;
		typedef 		 size_t								size_type;
		// typedef			 std::ptrdiff_t						difference_type
        
        pointer     	array;
        size_type       capacity;
        size_type       size;
        allocator_type	alloc;
	public:

		// CONSTRUCTORS
		explicit vector(const allocator_type& alloc = allocator_type())
		{
            this->array = NULL;
            this->capacity = 0;
            this->size = 0;
			this->alloc = alloc;
		}
		explicit vector(size_type n, const value_type& val = value_type(),
                	const allocator_type& alloc = allocator_type())
		{
			this->alloc = alloc;
            this->array = this->alloc.allocate(n);
            this->capacity = n;
            this->size = n;
			for (size_type i = 0; i < n; i++)
				this->alloc.construct(this->array + i, val);
		}
		vector (const vector& x)
		{
			this->alloc = x.alloc;
			this->capacity = x.capacity;
			this->size = this->size;
			this->array = this->alloc.allocate(this->capacity);
			for (size_type i = 0; i < this->size; i++)
				this->alloc.construct(this->array + i, x.array[i]);
		}
		// CONSTRUCTORS END

		// OPERATORS
		vector& operator= (const vector& x)
		{
			if (this->array)
			{
				for (size_type i = 0; i < this->size; i++)
					this->alloc.destroy(this->array + i);
				this->alloc.deallocate(this->array, this->capacity);
			}
			this->alloc = x.alloc;
			this->capacity = x.capacity;
			this->size = this->size;
			this->array = this->alloc.allocate(this->capacity);
			for (size_type i = 0; i < this->size; i++)
				this->alloc.construct(this->array + i, x.array[i]);
			return *this;
		}

		reference operator[] (size_type n)
		{
			return this->array[n];
		}
		const_reference operator[] (size_type n) const
		{
			return this->array[n];
		}
		// OPERATORS END

		// DESTRUCTOR
		~vector()
		{
			for (size_type i = 0; i < this->size; i++)
				this->alloc.destroy(this->array);
			this->alloc.deallocate(this->array, this->capacity);
		}
		// DESTRUCTOR END
	};
	
}
