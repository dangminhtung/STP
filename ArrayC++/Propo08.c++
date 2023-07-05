#include <iostream>
using namespace std;
int K_row[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int K_col[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int board[1001][1001];
int check_K(int x, int y, int n)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        int r = x + K_row[i];
        int c = y + K_col[i];
        if (r >= 0 && c >= 0 && r < n && c < n)
        {
            if (board[r][c] == 1)
            {
                count++;
            }
        }
    }
    return count;
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int n, r, c;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board[i][j] = 0;
            }
        }
        int a, b, p;
        cin >> a >> b >> p;
        int indexK[2][a];
        for (int i = 0; i < a; i++)
        {
            cin >> r >> c;
            indexK[0][i] = r;
            indexK[1][i] = c;
            board[r][c] = 1;
        }
        for (int i = 0; i < b; i++)
        {
            cin >> r >> c;
            board[r][c] = 1;
        }
        for (int i = 0; i < p; i++)
        {
            cin >> r >> c;
            board[r][c] = 0;
        }
        int max = 0;
        int index = 0;
        for (int i = 0; i < a; i++)
        {
            int dem = check_K(indexK[0][i], indexK[1][i], n);
            if (max < dem)
            {
                max = dem;
                index = i;
            }
        }
        cout << "#" << (k + 1) << " " << indexK[0][index] << " " << indexK[1][index] << " " << max << endl;
    }
}
