#include "../common.hpp"

/*
Design and implement a data structure for a compressed string iterator. 

The given compressed string will be in the form of each letter followed by a 
positive integer representing the number of this letter existing in the original uncompressed string.

Implement the StringIterator class:

char next() Returns the next character if the original string still has uncompressed characters, otherwise returns a white space.

boolean hasNext() Returns true if there is any letter needs to be uncompressed in the original string, otherwise returns false.

N25e2t1C1o1d1e1
              I
index = 2;
value = e
num = 20 + 5
2 50
1 49
0 48

*/

class StringIterator {
private:
    int index  = 0;
    char value = ' ';
    int freq   = 0;
    int size   = 0;

    string res;
public:
    StringIterator(string compressedString) {
        size = compressedString.size();
        res = compressedString;
    }
    
    char next() {
        if (!hasNext()) return ' ';
        
        if (freq == 0){
            value = res[index]; index ++;
            while(index < size && isdigit(res[index])){
                freq = freq * 10 + res[index] - 48;
                index ++;
            }
        }
        freq --;
        return value;
    }
    
    bool hasNext() {
       if (freq > 0 || index < size) return true;

       return false;
    }
};

int main(){
    string compressedString = "N1e2t1C1o1d1e1";

    StringIterator st(compressedString);

    cout << st.next() << endl; // N
    cout << st.next() << endl; // e
    cout << st.next() << endl; // e
    cout << st.next() << endl; // t
    cout << st.next() << endl; // C
    cout << st.next() << endl; // o

    cout << boolalpha << st.hasNext() << endl; // true

    cout << st.next() << endl; // d

    cout << boolalpha << st.hasNext() << endl; // true

    cout << st.next() << endl; // e

    cout << boolalpha << st.hasNext() << endl; // false


}
