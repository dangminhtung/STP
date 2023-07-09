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

int Precedence(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 3;
}
void InfixToPostFix(char str[], char postfix[], int len)
{
    Stack stack;
    char x, token;
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            postfix[j++] = str[i];
        if (str[i] >= 'A' && str[i] <= 'Z')
            postfix[j++] = str[i];
        else if (str[i] == '(')
            stack.push(str[i]);
        else if (str[i] == ')')
        {
            char c;
            while ((c = stack.pop()) != '(')
                postfix[j++] = c;
        }
        else
        {
            while (Precedence(str[i]) <= Precedence(stack.peek()) && !stack.is_Empty())
            {
                char c = stack.pop();
                postfix[j++] = c;
            }
            stack.push(str[i]);
        }
    }
    while (!stack.is_Empty())
    {
        /* code */
        char c = stack.pop();
        postfix[j++] = c;
    }
    postfix[j] = '\0';
}
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    for (int k = 0; k < 1; k++)
    {
        int len;
        cin >> len;
        char str[10000], postfix[10000];
        for (int i = 0; i < len; i++)
        {
            cin >> str[i];
        }
        InfixToPostFix(str, postfix, len);
        Stack s;
        s.reset();
        int sum = 0;
        int j = 0;
        // while (postfix[j] != '\0')
        // {
        //     cout << postfix[j];
        //     j++;
        // }
        while (postfix[j] != '\0')
        {
            if (postfix[j] >= '0' && postfix[j] <= '9')
            {
                // cout << postfix[j] - '0' << endl;
                s.push(postfix[j] - '0');
            }
            else if (postfix[j] == '+' || postfix[j] == '*' || postfix[j] == '-')
            {
                // cout << s.pop() - '0' << endl;
                int x = s.pop();
                int y = s.pop();
                // cout << x << " " << y << endl;
                if (postfix[j] == '+')
                    sum = y + x;
                else if (postfix[j] == '*')
                    sum = y * x;
                else if (postfix[j] == '-')
                    sum = y - x;
                s.push(sum);
            }
            j++;
        }
        cout << "#" << (k + 1) << " " << sum << endl;
    }
}