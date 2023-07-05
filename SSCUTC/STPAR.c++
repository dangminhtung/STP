#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;

    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        int a[n];
        int start = 1, check = 1;
        int stack[n];
        int size_stack = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            // phai tru di 1 vì dưới cộng sẵn size_stack ở phần else
            while (size_stack > 0 && stack[size_stack - 1] == start)
            {
                start++;
                size_stack--;
            }
            if (a[i] == start)
            {
                start++;
            }
            else if (size_stack > 0 && stack[size_stack - 1] < a[i])
            {
                check = 0;
                break;
            }
            else
            {
                stack[size_stack] = a[i];
                size_stack++;
            }
        }
        if (check)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}
