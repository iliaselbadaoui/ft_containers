# include <iostream>
# include <vector>
# include "vector.hpp"

using namespace std;
int main ()
{
    typedef    int     type;
    std::vector<type> std_vect(5, 101);
    ft::vector<type> ft_vect(5, 101);
    
    cout << "STD [0] operator : " << std_vect[0] << endl;
    cout << "FT [0] operator : " << ft_vect[0] << endl;
    cout << "STD max_size : " << std_vect.max_size() << endl;
    cout << "FT max_size : " << ft_vect.max_size() << endl;

    cout << "------------------" << endl;
    cout << "AFTER RESIZE" << endl;
    cout << "------------------" << endl;
    std_vect.resize(10, 11);
    ft_vect.resize(10, 11);
    cout << "STD [0] operator : " << std_vect[0] << endl;
    cout << "FT [0] operator : " << ft_vect[0] << endl;
    cout << "STD [6] operator : " << std_vect[6] << endl;
    cout << "FT [6] operator : " << ft_vect[6] << endl;
    cout << "STD max_size : " << std_vect.max_size() << endl;
    cout << "FT max_size : " << ft_vect.max_size() << endl;

    cout << "------------------" << endl;
    cout << "EMPTY METHOD" << endl;
    cout << "------------------" << endl;
    cout << "STD EMPTY : " << std_vect.empty() << endl;
    cout << "FT EMPTY : " << ft_vect.empty() << endl;
    cout << "------------------" << endl;
    cout << "RESERVE METHOD" << endl;
    cout << "------------------" << endl;
    std_vect.reserve(12);
    ft_vect.reserve(12);
    cout << "STD [11] operator : " << std_vect[11] << endl;
    cout << "FT [11] operator : " << ft_vect[11] << endl;
    cout << "STD [6] operator : " << std_vect[6] << endl;
    cout << "FT [6] operator : " << ft_vect[6] << endl;
    cout << "------------------" << endl;
    cout << "FRONT METHOD" << endl;
    cout << "------------------" << endl;
    std_vect.front() = 3;
    std_vect.front() = 3;
    cout << "STD FRONT : " << std_vect.front() << endl;
    cout << "FT FRONT : " << ft_vect.front() << endl;
    cout << "------------------" << endl;
    cout << "BACK METHOD" << endl;
    cout << "------------------" << endl;
    cout << "STD BACK : " << std_vect.back() << endl;
    cout << "FT BACK : " << ft_vect.back() << endl;
    return 0;
}