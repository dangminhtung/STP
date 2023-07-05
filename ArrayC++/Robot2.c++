#include <iostream>
#include <math.h>
using namespace std;
const int W = 0;
const int N = 1;
const int E = 2;
const int S = 3;
int row[4] = {-1, 0, 1, 0};
int col[4] = {0, 1, 0, -1};
void moved(int &x, int &y, int dir)
{
    x = x + row[dir];
    y = y + col[dir];
}
int main(int argc, char const *argv[])
{
    int testcase;
    cin >> testcase;

    for (int k = 1; k <= testcase; k++)
    {
        int m, n, z;
        cin >> m >> n >> z;
        char c[2][201];
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < z; j++)
            {
                cin >> c[i][j];
            }
        }
        float sum[2];
        int xA = 0, yA = 0;
        int dirA = N;
        int xB = 0, yB = 0;
        int dirB = N;

        int checkAll = false;
        int checkA = false;
        int checkB = false;
        for (int j = 0; j < z; j++)
        {
            // robot A
            if (c[0][j] == 'W')
                dirA = W;
            if (c[0][j] == 'N')
                dirA = N;
            if (c[0][j] == 'E')
                dirA = E;
            if (c[0][j] == 'S')
                dirA = S;
            if (c[0][j] == 'L')
                dirA = (dirA + 3) % 4;
            if (c[0][j] == 'R')
                dirA = (dirA + 1) % 4;
            if (c[0][j] == 'B')
                dirA = (dirA + 2) % 4;
            // robot B
            if (c[1][j] == 'W')
                dirB = W;
            if (c[1][j] == 'N')
                dirB = N;
            if (c[1][j] == 'E')
                dirB = E;
            if (c[1][j] == 'S')
                dirB = S;
            if (c[1][j] == 'L')
                dirB = (dirB + 3) % 4;
            if (c[1][j] == 'R')
                dirB = (dirB + 1) % 4;
            if (c[1][j] == 'B')
                dirB = (dirB + 2) % 4;
            moved(xA, yA, dirA);
            moved(xB, yB, dirB);
            if (xA == m && yA == n && xB == m && yB == n)
            {
                checkAll = true;
                break;
            }
            else if (xA == m && yA == n)
            {
                checkA = true;
                break;
            }
            else if (xB == m && yB == n)
            {
                checkB = true;
                break;
            }
        }
        if (checkAll)
            cout << "#" << (k) << " "
                 << "Good game!" << endl;
        else if (checkA)
            cout << "#" << (k) << " "
                 << "Team A win" << endl;
        else if (checkB)
            cout << "#" << (k) << " "
                 << "Team B win" << endl;
        else
        {
            sum[0] = sqrt(pow((m - xA), 2) + pow((n - yA), 2));
            sum[1] = sqrt(pow((m - xB), 2) + pow((n - yB), 2));
            printf("#%d %0.3f %0.3f\n", k, sum[0], sum[1]);
        }
    }
}
