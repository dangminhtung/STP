#include <iostream>
using namespace std;
char str[1000][1000];
int row[4] = {0, -1, 0, 1};
int col[4] = {-1, 0, 1, 0};
void moved(int &x, int &y, int dir)
{
    x = x + row[dir];
    y = y + col[dir];
}
int slove(int x, int y, int dir, int n)
{
    int sum = 0;
    while (true)
    {
        if (x < 0 || y < 0 || x >= n || y >= n)
            break;
        if (str[x][y] == '/')
        {
            if (dir == 2 || dir == 0)
            {
                dir = (dir + 3) % 4;
                moved(x, y, dir);
            }
            else
            {
                dir = (dir + 1) % 4;
                moved(x, y, dir);
            }
            sum++;
        }

        else if (str[x][y] == 92)
        {
            if (dir == 2 || dir == 0)
            {
                dir = (dir + 1) % 4;
                moved(x, y, dir);
            }
            else
            {
                dir = (dir + 3) % 4;
                moved(x, y, dir);
            }
            sum++;
        }
        else
        {
            moved(x, y, dir);
        }
        // cout << x << " " << y << endl;
    }
    return sum;
}
int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int n;
        cin >> n;

        int row[n * n];
        int col[n * n];
        int x = 0;
        // input
        // tim ra cac vi tri hang va cot chua / va 92
        for (int i = 0; i < n; i++)
        {
            int check = false;
            for (int j = 0; j < n; j++)
            {
                cin >> str[i][j];
                if (check)
                    continue;
                if (str[i][j] == '/' || str[i][j] == 92)
                {
                    check = true;
                    row[x] = i;
                    x++;
                }
            }
        }
        int y = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (str[j][i] == '/' || str[j][i] == 92)
                {
                    col[y] = i;
                    y++;
                    break;
                }
            }
        }
        // slove

        cout << "#" << (k + 1) << " " << hang << " " << cot << " " << max << endl;
    }
}