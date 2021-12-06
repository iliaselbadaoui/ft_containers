namespace ft
{
	# include <memory>
	# include "iterator_traits.hpp"
	# define X64_MAX 184467440737095.51616e5
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
        size_type       _size;
        allocator_type	alloc;

		void destroySelf()
		{
			for (size_type i = 0; i < this->_size; i++)
					this->alloc.destroy(this->array + i);
				this->alloc.deallocate(this->array, this->capacity);
		}
	public:

		// CONSTRUCTORS
		explicit vector(const allocator_type& alloc = allocator_type())
		{
            this->array = NULL;
            this->capacity = 0;
            this->_size = 0;
			this->alloc = alloc;
		}
		explicit vector(size_type n, const value_type& val = value_type(),
                	const allocator_type& alloc = allocator_type())
		{
			this->alloc = alloc;
            this->array = this->alloc.allocate(n);
            this->capacity = n;
            this->_size = n;
			for (size_type i = 0; i < n; i++)
				this->alloc.construct(this->array + i, val);
		}
		vector (const vector& x)
		{
			this->alloc = x.alloc;
			this->capacity = x.capacity;
			this->_size = this->_size;
			this->array = this->alloc.allocate(this->capacity);
			for (size_type i = 0; i < this->_size; i++)
				this->alloc.construct(this->array + i, x.array[i]);
		}
		// CONSTRUCTORS END

		// OPERATORS
		vector& operator= (const vector& x)
		{
			if (this->array)
				destroySelf();
			this->alloc = x.alloc;
			this->capacity = x.capacity;
			this->_size = this->_size;
			this->array = this->alloc.allocate(this->capacity);
			for (size_type i = 0; i < this->_size; i++)
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

		// CAPACITY METHODS
		
		// SIZE
		size_type size() const
		{
			return this->_size;
		}
		// SIZE END

		// MAX_SIZE
		size_type max_size() const
		{
			int type_size = sizeof(value_type);
			if (type_size == 1)
				type_size++;
			return X64_MAX/type_size - 1;
		}
		// MAX_SIZE END

		// RESIZE
		void resize (size_type n, value_type val = value_type())
		{

		}
		// RESIZE END

		// CAPACITY METHODS END

		// DESTRUCTOR
		~vector()
		{
			destroySelf();
		}
		// DESTRUCTOR END
	};
	
}
