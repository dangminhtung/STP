#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int r, c;
        cin >> r >> c;
        char arr[r][c];
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> arr[i][j];
            }
        }

        int sum = 0;
        int result = 0;
        int check = 0;
        for (int i = 0; i < r; i++)
        {
            sum = 0;
            for (int j = 0; j < c; j++)
            {
                if (arr[i][j] == '1')
                {
                    // sum = 0;
                    break;
                }
                sum++;
            }
            if (sum == c)
            {
                check++;
                result += sum;
            }
        }
        // cout << result << endl;
        sum = 0;
        for (int i = 0; i < c; i++)
        {
            sum = 0;

            for (int j = 0; j < r; j++)
            {
                if (arr[j][i] == '1')
                {
                    // sum = 0;
                    break;
                }
                sum++;
            }
            if (sum == r)
            {
                sum -= check;
                result += sum;
                sum = 0;
            }
        }
        cout << "#" << (k + 1) << " " << result << endl;
    }
    return 0;
}
