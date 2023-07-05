#include <iostream>
using namespace std;
int row[4] = {0, -1, 0, 1};
int col[4] = {-1, 0, 1, 0};
void moved(int &x, int &y, int dir)
{
    x = x + row[dir];
    y = y + col[dir];
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int n;
        cin >> n;
        char str[1000][1000];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> str[i][j];
            }
        }
        int x = 0;
        int y = 1;
        int dir = 2;
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
        cout << "#" << (k + 1) << " " << sum << endl;
    }
    return 0;
}
