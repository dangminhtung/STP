#include <iostream>
using namespace std;

int check(int x)
{
    int a = x;
    int sum = 0;
    int temp;
    while (a > 0)
    {
        temp = a % 10;
        sum += temp;
        a = a / 10;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    // cout << 1 % 10;
    int n, testcase;
    cin >> testcase;
    int a[testcase];
    for (int i = 0; i < testcase; i++)
    {
        cin >> n;
        int sum;
        while (true)
        {
            n = check(n);
            if (n < 10)
                break;
        }
        a[i] = n;
    }
    for (int i = 0; i < testcase; i++)
    {
        cout << "#" << (i + 1) << " " << a[i] << endl;
    }
}
