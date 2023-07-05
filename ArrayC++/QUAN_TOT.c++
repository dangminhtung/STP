#include <iostream>
using namespace std;

char check(int x)
{
    if (x == 0)
        return 'A';
    if (x == 2)
        return 'B';
    if (x == 4)
        return 'C';
    if (x == 6)
        return 'D';
    if (x == 8)
        return 'E';
    return 0;
}
int main(int argc, char const *argv[])
{
    int r, c;
    cin >> r >> c;
    if (r >= 3)
    {
        if (c == 0 || c == 2 || c == 4 || c == 6 || c == 8)
        {
            cout << r - 3 << endl;
            char ch = check(c);
            cout << ch;
        }
        else
        {
            cout << r - 3 + 1 << endl;
            int temp = c - 1;
            char ch = check(temp);
            cout << ch;
        }
    }
    else
    {
        cout << "-1";
    }

    return 0;
}
