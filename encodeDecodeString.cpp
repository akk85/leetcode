#include "common.hpp"


class Decoder{
public:
    /*
    neet, code -> 4#neet4#code 
    4#neet4#code
          i
           j 
    neet, code 
    */
    string encode(const vector<string>& str){
        string encodedString {};
        for (const string& word : str){
            string length = to_string(word.size());
            string pound = "#";

            encodedString.append(length + pound + word);
        }
        return encodedString;
    }
    /*
    4#Neet4#Code
    i
     j
    */

    vector<string> decode(string s){
        vector<string> result;
        int i = 0;
        int size = s.size();

        while (i < size){
            int j = i;
            while (s[j] != '#'){
                j++;
            }

            int length = stoi(s.substr(i, j - i));
            string word = s.substr(j + 1, length);
            result.push_back(word);
            i = j + 1 + length;
        }

        return result;
    }

    void printMessage(const vector<string>& str){
        for (const string& s : str){
            cout << s << " " ;
        }
        cout << endl;
    }
};

int main(){
    Decoder decoder;
    vector<string> str = {"Neet","Code"};
    
    string encodedString = decoder.encode(str);

    cout << encodedString << endl;

    vector<string> decodedString = decoder.decode(encodedString);

    
    decoder.printMessage(decodedString);
}