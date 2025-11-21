#include <iostream>
#include <string>
#include "queue.h"

using namespace std;
bool isValid(const string &expr)
{
    Queue q;
    bool v;
    for (char ch : expr)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            q.enqueue(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            char top = q.front();
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
        qq.enqueue(s[i]);
    }
    int i = (s.size() / 2) + 1;

    while (s.size() > i)
    {
        if (qq.dequeue() != s[i])
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
        char item = q.dequeue();
        if (item == t)
        {
            r = true;
        }
        temp.enqueue(item);
    }

    while (!temp.isEmpty())
    {
        q.enqueue(temp.dequeue());
    }

    return r;
}
int main()
{
    //************************* */ TASK01 *************************
    // try
    // {
    //     Queue nq;
    //     nq.enqueue('A');
    //     nq.enqueue('B');
    //     nq.enqueue('c');
    //     nq.enqueue('d');
    //     nq.enqueue('e');
    //     cout << nq.dequeue() << endl;
    //     // cout << nq.dequeue() << endl;
    //     cout << nq.isFull() << endl;
    //     cout << nq.isEmpty() << endl;
    //     cout << nq.size() << endl;
    //     while (!nq.isEmpty())
    //     {
    //         cout << nq.dequeue() << endl;
    //     }
    //     cout << nq.isEmpty() << endl;
    //     cout << nq.front() << endl;
    // }
    // catch (string se)
    // {
    //     cout << "Exception occured: " << se << endl;
    //     cout << "This is line number " << __LINE__ << " in file " << __FILE__ << endl;
    // }

    // ***************************TASK-02***************************

    // string expr1 = "(a+b)";
    // string expr2 = "2+7(3*5]";
    // cout << "Expression 1 is " << (isValid(expr1) ? "Valid" : "Invalid") << endl;
    // cout << "Expression 2 is " << (isValid(expr2) ? "Valid" : "Invalid") << endl;

    // ***************************TASK-03***************************

    // string s = "madam";
    // cout << "Is " << s << " a palindrome? " << (ispal(s) ? "Yes" : "No") << endl;

    // ***************************TASK-04***************************

    Queue q;
    q.enqueue('a');
    q.enqueue('t');
    q.enqueue('z');

    char t = 'y';
    if (searchInStack(q, t))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    cout << "34786578" << endl;
    return 0;
}
