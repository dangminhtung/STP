#include <iostream>
using namespace std;
int main()
{
    int m, n;
    int casetest;
    cin >> casetest;
    int arr[casetest][5];
    for (int c = 0; c < casetest; c++)
    {
        for (int i = 0; i < 5; i++)
            arr[c][i] = 0;
        cin >> m >> n;
        int height = m * 5 + 1;
        int width = n * 5 + 1;
        char a[height][width];
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                cin >> a[i][j];
            }
        }
        int t = 0;
        // 6 11
        for (int i = 1; i < height; i += 5)
        {
            for (int j = 1; j < width; j += 5)
            {
                for (int k = i; k < i + 4; k++)
                {
                    if (a[k][j] == '*')
                    {
                        t++;
                    }
                    else
                    {
                        break;
                    }
                }
                arr[c][t]++;
                t = 0;
            }
        }
    }
    for (int i = 0; i < casetest; i++)
    {
        cout << "#" << (i + 1) << " " << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << " " << arr[i][3] << " " << arr[i][4] << endl;
    }
}
