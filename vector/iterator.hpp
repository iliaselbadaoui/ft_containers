# pragma once

namespace ft
{
    # include "../utilities/iterator.hpp"
    # include "../utilities/iterator_traits.hpp"
    # include <iostream>

    template <class T>
    class _iterator: public ft::iterator<std::random_access_iterator_tag, T>
    {
        public:
            typedef typename ft::iterator_traits<T>::value_type          value_type;
            typedef typename ft::iterator_traits<T>::difference_type     difference_type;
            typedef typename ft::iterator_traits<T>::pointer             pointer;
            typedef typename ft::iterator_traits<T>::reference           reference;
            typedef typename ft::iterator_traits<T>::iterator_category   iterator_category;

            // CONSTRUCTORS
            _iterator()
            {
                this->_pointer = NULL;
            }
            _iterator(_iterator iter)
            {
                this->_pointer = iter._pointer;
            }
            // CONSTRUCTORS END

            // OPERATORS
            _iterator   operator= (const _iterator rhs){this->_pointer = src._pointer; return *this; }
            _iterator&  operator++() { ++_ptr; return *this; }
            _iterator   operator++(int) { _iterator aux = *this; ++(*this); return aux; }
            _iterator&  operator--() { --_ptr; return *this; }
            _iterator   operator--(int) { _iterator aux = *this; --(*this); return aux; }
            _iterator   operator+=(int rhs) {return (*this = *this + rhs);};
            _iterator   operator-=(int rhs) {return (*this = *this - rhs);};
            _iterator   operator-(int rhs) {return _iterator(_ptr - rhs);}
            _iterator   operator+(int rhs) {return _iterator(_ptr + rhs);}


            size_t  operator-(vector_iterator rhs) {return (_ptr - rhs._ptr);}


            bool    operator!=(const vector_iterator & it) { return (_ptr != it._ptr); }
            bool    operator==(const vector_iterator & it) { return (_ptr == it._ptr); }
            bool    operator<(const vector_iterator & it) { return (_ptr < it._ptr); }
            bool    operator>(const vector_iterator & it) { return (_ptr > it._ptr); }
            bool    operator<=(const vector_iterator & it) { return (_ptr <= it._ptr); }
            bool    operator>=(const vector_iterator & it) { return (_ptr >= it._ptr); }

            operator _iterator<const value_type> () const { return _iterator<const value_type>(_ptr) ; }

            reference   operator*() { return *_ptr; };
            reference   operator[](int n) { return _ptr[n]; };
            // OPERATORS END
        private:
            pointer _pointer;
    };
}