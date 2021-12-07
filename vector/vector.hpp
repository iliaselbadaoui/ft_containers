# pragma once
namespace ft
{
	# include <memory>
	# include <exception>
    # include <iostream>
	# include "../utilities/iterator.hpp"
	
	# define X64_MAX 184467440737095.51616e5

	struct length_error : public std::exception
	{
		const char * what () const throw ()
		{
			return "length error exception";
		}
	};
	struct out_of_range : public std::exception
	{
		const char * what () const throw ()
		{
			return "out of range exception";
		}
	};
	
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
        
        pointer     	_array;
        size_type       _capacity;
        size_type       _size;
        allocator_type	_alloc;

		void destroySelf(size_type start, size_type end)
		{
			for (size_type i = start; i < end; i++)
					this->_alloc.destroy(this->_array + i);
			if (end - start == this->_capacity)
				this->_alloc.deallocate(this->_array, this->_capacity);
		}
	public:

		// CONSTRUCTORS
		explicit vector(const allocator_type& alloc = allocator_type())
		{
            this->_array = NULL;
            this->_capacity = 0;
            this->_size = 0;
			this->_alloc = alloc;
		}
		explicit vector(size_type n, const value_type& val = value_type(),
                	const allocator_type& alloc = allocator_type())
		{
			this->_alloc = alloc;
            this->_array = this->_alloc.allocate(n);
            this->_capacity = n;
            this->_size = n;
			for (size_type i = 0; i < n; i++)
				this->_alloc.construct(this->_array + i, val);
		}
		vector (const vector& x)
		{
			this->_alloc = x.alloc;
			this->_capacity = x._capacity;
			this->_size = this->_size;
			this->_array = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(this->_array + i, x._array[i]);
		}
		// CONSTRUCTORS END

		// OPERATORS
		vector& operator= (const vector& x)
		{
			if (this->_array)
				destroySelf(0, this->_capacity);
			this->_alloc = x.alloc;
			this->_capacity = x._capacity;
			this->_size = this->_size;
			this->_array = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(this->_array + i, x._array[i]);
			return *this;
		}

		reference operator[] (size_type n)
		{
			return this->_array[n];
		}
		const_reference operator[] (size_type n) const
		{
			return this->_array[n];
		}
		// OPERATORS END

		// _CAPACITY METHODS
		
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
			if (n < this->_size)
			{
				destroySelf(n, this->_size - 1);
			}
			else
			{
				pointer		tmp;
				tmp = this->_alloc.allocate(n);
				for (size_type i = 0; i < this->_size; i++)
					tmp[i] = this->_array[i];
				for (size_type i = this->_size; i < n; i++)
					tmp[i] = val;
				destroySelf(0, this->_capacity);
				this->_array = tmp;
			}
			this->_size = n;
			this->_capacity = n;
		}
		// RESIZE END

		// CAPACITY
		size_type capacity() const
		{
			return this->_capacity;
		}
		// CAPACITY END

		// EMPTY
		bool empty() const
		{
			if (this->_size == 0)
				return true;
			return false;
		}
		// EMPTY END

		// RESERVE
		void reserve (size_type n)
		{
			if (n > max_size())
				throw length_error();
			if (n > this->_capacity)
			{
				pointer		tmp;
				tmp = this->_alloc.allocate(n);
				for (size_type i = 0; i < this->_size; i++)
					tmp[i] = this->_array[i];
				destroySelf(0, this->_capacity);
				this->_array = tmp;
			}
			this->_capacity = n;
		}
		// RESERVE END
		// CAPACITY METHODS END

		// ELEMENT ACCESS METHODS

		// AT METHOD
		reference at (size_type n)
		{
			if (n >= this->_size)
				throw out_of_range();
			return this->_array[n];
		}
		const_reference at (size_type n) const
		{
			if (n >= this->_size)
				throw out_of_range();
			return this->_array[n];
		}
		// AT METHOD END

		// FRONT METHOD
		reference front()
		{
			return this->_array[0];
		}
		const_reference front() const
		{
			return this->_array[0];
		}
		// FRONT METHOD END

		// BACK METHOD
		reference back()
		{
			return this->_array[this->_size - 1];
		}
		const_reference back() const
		{
			return this->_array[this->_size - 1];
		}
		// BACK METHOD END

		// ELEMENT ACCESS METHODS END

		// MODIFIERS METHODS

		// ASSIGN METHOD
			// template <class InputIterator>
			// void assign (InputIterator first, InputIterator last)
			// {
			// }
		void assign (size_type n, const value_type& val)
		{
            for (size_type i = 0; i < n; i++)
                this->_alloc.destroy(this->_array + i);
            if (n > this->_capacity)
            {
                this->_alloc.deallocate(this->_array, _capacity);
                this->_alloc.allocate(this->_array, n);
                this->_capacity = n;
            }
            for (size_type i = 0; i < n; i++)
                this->_alloc.construct(this->_array + i, val);
            this->_size = n;
		}
		// ASSIGN METHOD END

        // PUSH_BACK METHOD
        void push_back (const value_type& val)
        {
		    if (this->_size < this->_capacity)
		    {
                this->_array[this->_size] = val;
                ++this->_size;
		    }
		    else
            {
		        this->_capacity == 0 ? this->_capacity = 1 : this->_capacity *= 2;
		        pointer tmp = this->_alloc.allocate(this->_capacity);
		        for (size_type i = 0 ; i < this->_size; i++)
		            this->_alloc.construct(tmp + i, this->_array[i]);
		        tmp[this->_size] = val;
		        ++this->_size;
		        destroySelf(0, capacity() / 2);
		        this->_array = tmp;
            }
        }
        // PUSH_BACK METHOD END

        // POP_BACK METHOD
        void pop_back()
        {
		    if (this->_size)
            {
                this->_alloc.destroy(this->_array + (this->_size - 1));
                --this->_size;
            }
		};
        // POP_BACK METHOD END

        // INSERT METHOD
//            iterator insert (iterator position, const value_type& val);
//            void insert (iterator position, size_type n, const value_type& val);
//            template <class InputIterator>
//            void insert (iterator position, InputIterator first, InputIterator last);
        // INSERT METHOD END

        // ERASE METHOD
//            iterator erase (iterator position);
//            iterator erase (iterator first, iterator last);
        // ERASE METHOD END

        // SWAP METHOD
        void swap (vector& x)
        {
            size_type   helper;
            pointer     aux;

            aux = this->_array;
            this->_array = x._array;
            x._array = aux;
            helper = this->_size;
            this->_size = x._size;
            x._size = helper;
            helper = this->_capacity;
            this->_capacity = x._capacity;
            x._capacity = helper;
        }
        // SWAP METHOD END

        // CLEAR METHOD
        void clear()
        {
            for (size_type i = 0; i < this->_size; i++)
                this->_alloc.destroy(this->_array + i);
            this->_size = 0;
        }
        // CLEAR METHOD END

		// MODIFIERS METHODS END

        // ALLOCATOR METHODS

        // GET_ALLOCATOR METHOD
        allocator_type get_allocator() const
        {
            return this->_alloc;
        }
        // GET_ALLOCATOR METHOD END

        // ALLOCATOR METHODS END

		// DESTRUCTOR
		~vector()
		{
			destroySelf(0, this->_capacity);
		}
		// DESTRUCTOR END
	};

    // RELATIONAL OPERATORS
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    // RELATIONAL OPERATORS END
}
