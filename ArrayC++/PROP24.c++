#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int n;
        cin >> n;
        int arr[n][n];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[j][i] == 1)
                {
                    for (int x = j; x < n; x++)
                    {
                        if (arr[x][i] == 2)
                        {
                            sum++;
                            j = x;
                            break;
                        }
                    }
                }
            }
        }
        cout << "#" << (k + 1) << " " << sum << endl;
        ;
    }
}