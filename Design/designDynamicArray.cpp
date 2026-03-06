#include "../common.hpp"

class DynamicArray{
private:
    int *vector;
    int length;
    int cap;
public:
    DynamicArray(int capacity){
        length = 0;
        cap = capacity;
        vector = new int[cap];
    }

    ~DynamicArray(){
        delete[] vector;
    }

    int get(int index){
        return vector[index];
    }

    void set(int index, int value){
        vector[index] = value;
    }

    void pushback(int value){
        if (length == cap){
            resize();
        }
        vector[length] = value;
        length ++;
    }

    int popback(){
        int last = vector[length];
        length --;
        return last;
    }

    void resize(){
        cap = cap * 2;
        int *newVec = new int[cap];
        for (int i = 0; i < length; i++){
            newVec[i] = vector[i];
        }
        delete[] vector;
        vector = newVec;
    }

    int size(){
        return length;
    }

    int getCapacity(){
        return cap;
    }
};

/*
l = 0
c = 2
[0, 1]
[0, 1, 2, 0]
*/
int main(){
    DynamicArray vec(2);

    cout << "size is: " << vec.size() << endl;
    cout << "capacity is: " << vec.getCapacity() << endl;

    vec.pushback(0);
    vec.pushback(1);
    vec.pushback(2);

    cout << "size is: " << vec.size() << endl;

    cout << "capacity is: " << vec.getCapacity() << endl;
    cout << "last element is: " << vec.get(vec.size() - 1) << endl;
}