#include <iostream>
using namespace std;
int dirX[3] = {-1, -1, -1};
int dirY[3] = {0, -1, 1};
void moved(int &x, int &y, int dir)
{
    x = x + dirX[dir];
    y = y + dirY[dir];
}

int main(int argc, char const *argv[])
{
    int testcase, n;
    cin >> testcase;
    for (int k = 0; k < testcase; k++)
    {
        cin >> n;
        int a[n][5];
        char C[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++)
            cin >> C[i];
        int x = n;
        int y = 2;
        long long sum = 0;
        int check = 1;
        for (int i = 0; i < n; i++)
        {
            if (C[i] == 'C')
                moved(x, y, 0);
            if (C[i] == 'L')
                moved(x, y, 1);
            if (C[i] == 'R')
                moved(x, y, 2);
            if (a[x][y] == 2)
            {
                check = 0;
                break;
            }
            sum += a[x][y];
        }
        if (check)
        {
            cout << "#" << (k + 1) << " "
                 << "YES " << sum << endl;
        }
        else
        {
            cout << "#" << (k + 1) << " "
                 << "NO" << endl;
        }
    }
}
