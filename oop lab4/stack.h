#ifndef queue
#define queue

#include <array>

using namespace std;

constexpr int QSIZE{100};

class Queue
{
protected:
    array<double, QSIZE> q;
    int n;

    void advance();

public:
    Queue();
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    char top() const;
    void push(char item);
    char pop();
};

#endif
