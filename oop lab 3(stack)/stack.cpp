#include "stack.h"
#include <string>
using namespace std;

Queue::Queue() : n(0)
{
}
void Queue::advance()
{
    int i = n - 1;
    while (i > 0)
    {
        this->q[i] = this->q[i - 1];
        i--;
    }
}
bool Queue::isEmpty() const
{
    return this->n == 0;
}
bool Queue::isFull() const
{
    return this->n == QSIZE;
}
int Queue::size() const
{
    return this->n;
}
char Queue::top() const
{
    if (this->size() > 0)
    {
        return this->q[n - 1];
    }
    else
    {
        throw string("Empty");
    }
}
void Queue::push(char item)
{
    if (this->size() < QSIZE)
    {
        this->q[this->n] = item;
        this->n += 1;
    }
    else
    {
        throw string("Full");
    }
}
char Queue::pop()
{
    char item = this->top();
    this->n -= 1;
    return item;
}
