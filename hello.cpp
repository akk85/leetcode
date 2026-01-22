#include <iostream>
#include <ostream>
using namespace std;

/*
Function overloading 
                    Number of parameters
                    Type of parameter
                    Return type of function os not used to overload functions 
*/

int add(int x, int y){
    return x + y;
}

double add(double x, double y){
    return x + y;
}

double add(double x, double y, double z){
    return x + y;
}

/*
Function deleting
*/
void printInt(int x){
    cout << x << endl;
}
void printInt(char) = delete;
void printInt(bool) = delete;

template <typename T>
void printInt(T x) = delete;  // this ensures calls to any type will halt compilation 


/*
Function templates. DRY Don't repeat yourself 
*/

template <typename T>

T myMax(T x, T y){
    return x > y ? x : y;
}

/*
lvalues and rvalues
                lvalue evaluates to an identifiable object or function(bit field)
                rvalue evaluates to a value 
 */


void printAddresses(int val, int& ref){
    cout << &val << endl;
    cout << &ref << endl;
}
int main(){
    int x {5};
    cout << &x << endl;
    printAddresses(x, x);
    return 0;
}


