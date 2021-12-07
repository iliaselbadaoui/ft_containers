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
            _iterator   operator= (const _iterator rvalue){this->_pointer = rvalue._pointer; return *this; }
            _iterator&  operator++() { ++_pointer; return *this; }
            _iterator   operator++(int) { _iterator aux = *this; ++(*this); return aux; }
            _iterator&  operator--() { --_pointer; return *this; }
            _iterator   operator--(int) { _iterator aux = *this; --(*this); return aux; }
            _iterator   operator+=(int rvalue) {return (*this = *this + rvalue); }
            _iterator   operator-=(int rvalue) {return (*this = *this - rvalue); }
            _iterator   operator-(int rvalue) {return _iterator(_pointer - rvalue); }
            _iterator   operator+(int rvalue) {return _iterator(_pointer + rvalue); }


            size_t      operator-(_iterator rvalue) {return (_pointer - rvalue._pointer); }


            bool        operator!=(const _iterator & it) { return (_pointer != it._pointer); }
            bool        operator==(const _iterator & it) { return (_pointer == it._pointer); }
            bool        operator<(const _iterator & it) { return (_pointer < it._pointer); }
            bool        operator>(const _iterator & it) { return (_pointer > it._pointer); }
            bool        operator<=(const _iterator & it) { return (_pointer <= it._pointer); }
            bool        operator>=(const _iterator & it) { return (_pointer >= it._pointer); }

            operator    _iterator<const value_type> () const { return _iterator<const value_type>(_pointer) ; }

            reference   operator*() { return *_pointer; };
            reference   operator[](int n) { return _pointer[n]; };
            // OPERATORS END
        private:
            pointer _pointer;
    };

    template <class T>
    class _reverse_iterator: public ft::iterator<std::random_access_iterator_tag, T>
    {
    public:
        typedef typename ft::iterator_traits<T>::value_type          value_type;
        typedef typename ft::iterator_traits<T>::difference_type     difference_type;
        typedef typename ft::iterator_traits<T>::pointer             pointer;
        typedef typename ft::iterator_traits<T>::reference           reference;
        typedef typename ft::iterator_traits<T>::iterator_category   iterator_category;

        // CONSTRUCTORS
        _reverse_iterator()
        {
            this->_pointer = NULL;
        }
        explicit _reverse_iterator(_reverse_iterator it)
        {
            this->_pointer = it._pointer;
        }
        template <class Iter>
        _reverse_iterator (const _reverse_iterator<Iter>& rev_it)
        {
            this->_pointer = rev_it._pointer;
        }
        // CONSTRUCTORS END

        // OPERATORS
        _reverse_iterator   operator= (const _reverse_iterator rvalue){this->_pointer = rvalue._pointer; return *this; }
        _reverse_iterator&  operator++() { ++_pointer; return *this; }
        _reverse_iterator   operator++(int) { _reverse_iterator aux = *this; ++(*this); return aux; }
        _reverse_iterator&  operator--() { --_pointer; return *this; }
        _reverse_iterator   operator--(int) { _reverse_iterator aux = *this; --(*this); return aux; }
        _reverse_iterator   operator+=(int rvalue) {return (*this = *this + rvalue); }
        _reverse_iterator   operator-=(int rvalue) {return (*this = *this - rvalue); }
        _reverse_iterator   operator-(int rvalue) {return _reverse_iterator(_pointer - rvalue); }
        _reverse_iterator   operator+(int rvalue) {return _reverse_iterator(_pointer + rvalue); }


        size_t      operator-(_reverse_iterator rvalue) {return (_pointer - rvalue._pointer); }


        bool        operator!=(const _reverse_iterator & it) { return (_pointer != it._pointer); }
        bool        operator==(const _reverse_iterator & it) { return (_pointer == it._pointer); }
        bool        operator<(const _reverse_iterator & it) { return (_pointer < it._pointer); }
        bool        operator>(const _reverse_iterator & it) { return (_pointer > it._pointer); }
        bool        operator<=(const _reverse_iterator & it) { return (_pointer <= it._pointer); }
        bool        operator>=(const _reverse_iterator & it) { return (_pointer >= it._pointer); }

        operator    _reverse_iterator<const value_type> () const { return _reverse_iterator<const value_type>(_pointer) ; }

        reference   operator*() { return *_pointer; };
        reference   operator[](int n) { return _pointer[n]; };
        // OPERATORS END
    private:
        pointer _pointer;
    };
}