#include <iostream>
using namespace std;

#define MAX 100000

class Stack
{
    char data[MAX];
    int top;

public:
    Stack();
    bool is_Empty();
    bool is_Full();
    void push(char value);
    char pop();
    void reset();
    char peek();
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
void Stack::push(char value)
{
    data[++top] = value;
}
char Stack::pop()
{
    int res = data[top--];
    return res;
}
void Stack::reset()
{
    top = -1;
}
char Stack::peek()
{
    return data[top];
}

int main()
{
    freopen("input.txt", "rt", stdin);
    for (int k = 0; k < 1; k++)
    {
        int len;
        cin >> len;
        char str[10000];
        for (int i = 0; i < len; i++)
        {
            cin >> str[i];
        }
        Stack stack;
        int check = true;
        for (int i = 0; i < len; i++)
        {
            if ((str[i] == ')' || str[i] == ']' || str[i] == '}' || str[i] == '>') && stack.is_Empty())
            {
                check = false;
            }
            else if (str[i] == '(' || str[i] == '[' || str[i] == '{' || str[i] == '<')
            {
                stack.push(str[i]);
            }
            else if (
                (str[i] == ')' && stack.peek() == '(') ||
                (str[i] == '}' && stack.peek() == '{') ||
                (str[i] == ']' && stack.peek() == '[') ||
                (str[i] == '>' && stack.peek() == '<'))
            {
                stack.pop();
            }
            else
            {
                check = false;
            }
        }
        if (check)
            cout << "thoa man";
        else
            cout << "ko thoa man";
    }
}