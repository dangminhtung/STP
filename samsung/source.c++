#include <iostream>
using namespace std;
int row[4] = {0, -1, 0, 1};
int col[4] = {-1, 0, 1, 0};
int arr[200][200];
void moved(int &x, int &y, int dir)
{
    // cout << row[dir] << " " << col[dir] << " " << dir << endl;
    x = x + row[dir];
    y = y + col[dir];
}
int main()
{
    freopen("input.txt", "rt", stdin);
    int testcase;
    for (int k = 0; k < 1; k++)
    {
        cin >> testcase;
        int sum = 1;
        int max = 10000;
        int result = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cin >> arr[i][j];
            }
        }
        int dir = 3;
        for (int i = 0; i < 10; i++)
        {

            if (arr[0][i] == 1)
            {
                sum = 1;
                dir = 3;
                int x = 1, y = i;
                while (true)
                {
                    // cout << arr[x][y - 1];
                    // cout << dir << endl;
                    if (x < 0 || y < 0 || x >= 10 || y >= 10)
                    {
                        break;
                    }

                    // cout << x << " " << y << " " << dir << endl;

                    if (dir == 3 && (arr[x][y + 1] == 1 || arr[x][y - 1] == 1))
                    {
                        // cout << x << " " << y << endl;
                        if (arr[x][y + 1] == 1)
                        {
                            dir = (dir + 3) % 4;
                            moved(x, y, dir);
                            sum++;
                        }
                        else if (arr[x][y - 1] == 1)
                        {
                            dir = (dir + 1) % 4;
                            moved(x, y, dir);
                            sum++;
                        }
                    }
                    else if ((dir == 0 || dir == 2) && arr[x + 1][y] == 1)
                    {

                        if (dir == 2)
                        {
                            dir = (dir + 1) % 4;
                            moved(x, y, dir);
                            sum++;
                        }
                        else if (dir == 0)
                        {
                            dir = (dir + 3) % 4;
                            moved(x, y, dir);
                            sum++;
                        }
                    }
                    else
                    {
                        // cout << dir;
                        // cout << x << " " << y << endl;
                        moved(x, y, dir);
                        // cout << row[dir] << " " << col[dir] << endl;
                        sum++;
                    }
                    // cout << x << " " << y << " " << sum << endl;
                    if (arr[x][y] == 2)
                    {
                        if (max > sum)
                        {
                            max = sum;
                            result = i;
                        }
                    }
                }
            }
        }
        cout << "#" << (k + 1) << " " << result << endl;
    }
}