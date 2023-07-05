#include <iostream>
using namespace std;
int row[4] = {-1, 0, 1, 0};
int col[4] = {0, 1, 0, -1};
// 11

int checkMove(long long x, long long y)
{
    for (int i = 0; i < 4; i++)
    {
        if (row[i] == x && col[i] == y)
        {
            return i;
        }
    }
    return -1;
}

main(int argc, char const *argv[])
{
    int t, n;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        cin >> n;
        long long a[n][2];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> a[i][j];
            }
        }
        int dir;
        long long sum = 0;
        long long x, y;
        x = a[1][0] - a[0][0];
        y = a[1][1] - a[0][1];
        dir = checkMove(x, y);
        for (int i = 1; i < n; i++)
        {
            int r = (dir + 1) % 4;
            x = a[i][0] - a[i - 1][0];
            y = a[i][1] - a[i - 1][1];
            dir = checkMove(x, y);
            if (r == dir)
            {
                sum++;
            }
        }
        cout << "#" << (k + 1) << " " << sum << endl;
    }
}
