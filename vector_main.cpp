# include <iostream>
# include <vector>
# include "vector.hpp"

using namespace std;
int main ()
{
    std::vector<int> std_vect(5, 2);
    ft::vector<int> ft_vect(5, 2);
    cout << "STD [0] operator : " << std_vect[0] << endl;
    cout << "FT [0] operator : " << ft_vect[0] << endl;
    return 0;
}