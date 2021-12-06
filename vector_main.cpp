# include <iostream>
# include <vector>
# include "vector.hpp"

using namespace std;
int main ()
{
    typedef    char     type;
    std::vector<type> std_vect(5, 'X');
    ft::vector<type> ft_vect(5, 'X');
    
    cout << "STD [0] operator : " << std_vect[0] << endl;
    cout << "FT [0] operator : " << ft_vect[0] << endl;
    cout << "STD max_size : " << std_vect.max_size() << endl;
    cout << "FT max_size : " << ft_vect.max_size() << endl;
    return 0;
}