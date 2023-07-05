#include <iostream>
using namespace std;

int main()
{
    int m, n, testcase;
    cin >> testcase;
    int sum[testcase];
    int x[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int y[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int k = 0;
    for (k = 0; k < testcase; k++)
    {
        int result = 0;
        sum[k] = 0;
        cin >> m >> n;
        char a[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int row = 0, col = 0;
                if (a[i][j] == '.')
                {
                    for (int z = 0; z < 8; z++)
                    {
                        row = i + x[z];
                        col = j + y[z];
                        if (row < m && col < n && row >= 0 && col >= 0)
                        {

                            if (a[row][col] == '*')
                            {
                                result++;
                            }
                        }
                        else
                            continue;
                    }
                }
            }
        }
        cout << "Case "
             << "#" << (k + 1) << ": " << result << endl;
    }

    // for (int i = 0; i < testcase; i++)
    // {
    //     cout << "Case "
    //          << "#" << (i + 1) << ": " << sum[i] << endl;
    // }

    return 0;
}
