/*
Arrays stores data sequnetially in memory with no gaps
c++ gives us three types of array types: c-style arrays
                                        std::vector
                                        std::array  

*/

#include <iostream>
#include <vector>
using namespace std;

void user(){
    vector <int> values (3);
    cout << "Enter 3 integers: ";
    cin >> values[0] >> values[1] >> values[2];
    int sum = values[0] + values[1] + values[2];
    int product = values[0] * values[1] * values[2];

    cout << "The sum is: " << sum << endl;
    cout << "The product is: " << product << endl;

}

template <typename T>
void printElement(const vector<T>& vec, int index){
    if (index < 0 || index > vec.size() - 1){
        cout << "Invalid Index" << endl;
    }
    else {
        cout << "The element has value " << vec.at(index) << endl;
    }
}


int main()
{
    std::vector v1 { 0, 1, 2, 3, 4 };
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2 { 1.1, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}
