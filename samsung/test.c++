#include <iostream>
using namespace std;

#define MAX 100000

class Stack
{
    int data[MAX];
    int top;

public:
    Stack();
    bool is_Empty();
    bool is_Full();
    void push(int value);
    int pop();
    void reset();
    int peek();
};
Stack::Stack()
{
    top = -1;
}
bool Stack::is_Empty()
{
    if (top == -1)
        return true;
    return false;
}
bool Stack::is_Full()
{
    if (top == MAX)
        return true;
    return false;
}
void Stack::push(int value)
{
    data[++top] = value;
}
int Stack::pop()
{
    int res = data[top--];
    return res;
}
void Stack::reset()
{
    top = -1;
}
int Stack::peek()
{
    return data[top];
}
int main()
{
    freopen("output.out", "w", stdout);
    Stack stack;
    char a = 'a';
    stack.push(a);
    cout << stack.pop();
}