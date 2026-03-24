#include "../common.hpp"
#include <thread>
using namespace std;
class ThreadSafeQueue {
private:
    queue<int>          sharedQueue;
    mutex               queueMutex;
    condition_variable  conditionVariable;
public:
    void push(int value){
        unique_lock<mutex> lock(queueMutex);
        sharedQueue.push(value);

        lock.unlock();
        conditionVariable.notify_one();     // notiy consumer to pop from queue
    }
    int pop(){
        unique_lock<mutex> lock(queueMutex);
        
        while(sharedQueue.empty()){
            conditionVariable.wait(lock);
        }
        int value = sharedQueue.front(); sharedQueue.pop();
        lock.unlock();

        return value;
    }
};

class Producer{
private:
    ThreadSafeQueue& queue;
    mutex& coutMutex;
public:
    Producer(ThreadSafeQueue& q, mutex& coutM) : queue(q), coutMutex(coutM) {};
    void run(){
        for (int data = 0; data < 10; data ++){
            queue.push(data);
            unique_lock<mutex> coutLock(coutMutex);
            cout << "Producer pushed: " << data << endl;
            coutLock.unlock();
        }
        unique_lock<mutex> coutLock(coutMutex);
        cout << endl;
        coutLock.unlock();
    }
};

class Consumer{
private:
    ThreadSafeQueue& queue;
    mutex& coutMutex;
public:
    Consumer(ThreadSafeQueue& q, mutex& coutM) : queue(q), coutMutex(coutM) {};
    void run(){
        for (int i = 0; i < 10; i ++){
            int data = queue.pop();
            unique_lock<mutex> coutLock(coutMutex);
            cout << "Consumer popped: " << data << endl;
            coutLock.unlock();
        }

    }
};

int main(){
    ThreadSafeQueue q;
    mutex coutMutex;
    Producer producer(q, coutMutex);
    Consumer consumer(q, coutMutex);

    thread producerThread(&Producer::run, &producer);
    thread consumerThread(&Consumer::run, &consumer);

    producerThread.join();
    consumerThread.join();
}