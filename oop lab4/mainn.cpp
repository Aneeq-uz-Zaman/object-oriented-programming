#include <iostream>
#include <string>
#include "stack.h"
#include<algorithm>
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

using namespace std;
bool isValid(const string &expr)
{
    Queue q;
    bool v;
    for (char ch : expr)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            q.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            char top = q.top();
            if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
            {
                v = true;
            }
            else
            {
                v = false;
                break;
            }
        }
    }

    return v;
}
bool ispal(const string &s)
{
    Queue qq;

    for (int i = 0; i < s.size() / 2; i++)
    {
        qq.push(s[i]);
    }
    int i = (s.size() / 2) + 1;

    while (s.size() > i)
    {
        if (qq.pop() != s[i])
        {
            return false;
        }
        i++;
    }
    return true;
}
bool searchInStack(Queue &q, char t)
{
    Queue temp;
    bool r = false;

    while (!q.isEmpty())
    {
        char item = q.pop();
        if (item == t)
        {
            r = true;
        }
        temp.push(item);
    }

    while (!temp.isEmpty())
    {
        q.push(temp.pop());
    }

    return r;
}
void rev(string& a)
{
    Queue nq;
    for (char s : a)
    {
        nq.push(s);
    }
    for (int i = 0;!(nq.isEmpty()); i++)
    {
        a[i]=nq.pop();
    }

}
void dup(string& a)
{
    Queue nq;
    for(char s:a)
    {
        nq.push(s);
    }
    string b="";
    int c=0;
    for(int i=0;!(nq.isEmpty());i++)
    {
        bool r=true;
        char q=nq.pop();
        for(char s:b)
        {
            if(q==s){
                r=false;
            }
        }
        if(r)
        {
            b=b+q;
        }
    }
    a=b;
}
int main()
{
    //************************* */ TASK01 *************************
    // try
    // {
    //     Queue nq;
    //     nq.push('A');
    //     nq.push('B');
    //     nq.push('c');
    //     nq.push('d');
    //     nq.push('e');
    //     cout << nq.pop() << endl;
    //     // cout << nq.pop() << endl;
    //     cout << nq.isFull() << endl;
    //     cout << nq.isEmpty() << endl;
    //     cout << nq.size() << endl;
    //     while (!nq.isEmpty())
    //     {
    //         cout << nq.pop() << endl;
    //     }
    //     cout << nq.isEmpty() << endl;
    //     cout << nq.top() << endl;
    // }
    // catch (string se)
    // {
    //     cout << "Exception occured: " << se << endl;
    //     cout << "This is line number " << __LINE__ << " in file " << __FILE__ << endl;
    // }

    // ***************************TASK-02***************************

    // string expr1 = "(a+b)";
    // string expr2 = "2{+7(3*5)*6}";
    // cout << "Expression 1 is " << (isValid(expr1) ? "Valid" : "Invalid") << endl;
    // cout << "Expression 2 is " << (isValid(expr2) ? "Valid" : "Invalid") << endl;

    // ***************************TASK-03***************************

    // string s = "madam";
    // cout << "Is " << s << " a palindrome? " << (ispal(s) ? "Yes" : "No") << endl;

    // ***************************TASK-04***************************

    // Queue q;
    // q.push('a');
    // q.push('t');
    // q.push('z');

    // char t = 'y';
    // if (searchInStack(q, t))
    // {
    //     cout << "Found" << endl;
    // }
    // else
    // {
    //     cout << "Not found" << endl;
    // }



    string a = "abccd";
    dup(a);
    cout <<a;




    return 0;
}
