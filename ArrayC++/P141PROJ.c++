#include <iostream>
using namespace std;

int check(char a[4][4])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int sum = 0;
            if (a[i + 1][j] == a[i][j])
            {
                sum++;
            }
            if (a[i + 1][j + 1] == a[i][j])
            {
                sum++;
            }
            if (a[i][j + 1] == a[i][j])
            {
                sum++;
            }
            if (sum != 1)
            {
                return 1;
            }
        }
    }

    return 0;
}
int main(int argc, char const *argv[])
{
    char a[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
        }
    }
    int c = check(a);
    if (c)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
