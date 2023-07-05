#include <iostream>
using namespace std;

//   1
// 0   2
//   3
//   gap L
//   huong =(huong +3)%4

//   gap R
//   huong=(huong +1)%4
int row[4] = {0, -1, 0, 1};
int col[4] = {-1, 0, 1, 0};

void moved(int &x, int &y, int dir)
{
    x = x + row[dir];
    y = y + col[dir];
    // cout << x << " " << y << endl;
}
int main(int argc, char const *argv[])
{
    int testcase, n, m;
    cin >> testcase;
    for (int k = 0; k < testcase; k++)
    {
        cin >> n >> m;
        int a[n][n];
        char C[2][m];
        int dirP, dirG, xP, yP, xG, yG;
        long long GoldP = 0, GoldG = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> C[i][j];
            }
        }
        // contructor Pacman
        xP = 0;
        yP = 0;
        dirP = 3;
        // contructor ghost
        xG = n - 1;
        yG = n - 1;
        dirG = 1;
        for (int i = 0; i < m; i++)
        {
            if (C[0][i] == 'L')
                dirP = (dirP + 3) % 4;
            else if (C[0][i] == 'R')
                dirP = (dirP + 1) % 4;
            if (C[1][i] == 'L')
                dirG = (dirG + 3) % 4;
            else if (C[1][i] == 'R')
                dirG = (dirG + 1) % 4;
            moved(xP, yP, dirP);
            moved(xG, yG, dirG);
            if (xP == xG && yP == yG)
                break;
            GoldP += a[xP][yP];
            GoldG += a[xG][yG];
            a[xP][yP] = 0;
            a[xG][yG] = 0;
        }
        cout << "#" << (k + 1) << " " << GoldP << " " << GoldG << endl;
    }
}
