#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{

    int testcase, h, w, m, n, sum;
    cin >> testcase;
    int result[testcase];
    for (int i = 0; i < testcase; i++)
    {
        result[i] = 0;
    }
    for (int k = 0; k < testcase; k++)
    {
        cin >> h >> w >> m >> n;
        int arr[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i <= m - h; i++)
        {
            for (int j = 0; j <= n - w; j++)
            {
                sum = 0;
                // hang tren
                for (int a = j; a < w + j; a++)
                {

                    if (arr[i][a] % 2 == 0)
                    {
                        sum += arr[i][a];
                    }
                }

                // hang duoi
                for (int b = j; b < w + j; b++)
                {
                    if (arr[i + h - 1][b] % 2 == 0)
                        sum += arr[i + h - 1][b];
                }
                // cot trai
                for (int c = i + 1; c < i + h - 1; c++)
                {
                    if (arr[c][j] % 2 == 0)
                        sum += arr[c][j];
                }
                // cot phai
                for (int d = i + 1; d < i + h - 1; d++)
                {
                    if (arr[d][j + w - 1] % 2 == 0)
                        sum += arr[d][j + w - 1];
                }

                result[k] = result[k] > sum ? result[k] : sum;
            }
        }
    }
    for (int i = 0; i < testcase; i++)
    {
        cout << "#" << i + 1 << " " << result[i] << endl;
    }
}
