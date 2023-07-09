#include <iostream>
using namespace std;

class Stack
{
    int data[10000];
    int top;

public:
    Stack();
    bool is_Empty();
    void push(int value);
    int pop();
    int peek();
    void reset();
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
void Stack::push(int value)
{
    data[++top] = value;
}
int Stack::pop()
{
    int res;
    res = data[top--];
    return res;
}
int Stack::peek()
{
    return data[top];
}
void Stack::reset()
{
    top = -1;
}
int n = 0, m = 0;
int arr[10000][10000];
bool visited[1000];
Stack stack;
bool check(int node)
{
    stack.reset();
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }
    stack.push(node);
    visited[node] = true;

    while (!stack.is_Empty())
    {

        int cnode = stack.pop();
        // cout << cnode << endl;
        for (int i = 0; i < m; i++)
        {
            if (arr[i][0] == cnode && visited[arr[i][1]] == false)
            {
                visited[arr[i][1]] = true;
                stack.push(arr[i][1]);
            }
            else if (arr[i][0] == cnode && visited[arr[i][1]] == true && arr[i][1] == node)
                return true;
        }
    }
    return false;
}
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }

    int res = false;
    for (int i = 1; i <= n; i++)
    {
        if (check(i))
        {
            res = true;
            break;
        }
    }
    if (res)
        cout << "co";
    else
        cout << "ko";
}