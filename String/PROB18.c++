#include <iostream>
#include <string.h>

using namespace std;
int sub_start = 0;
char str[1000][1000];
int check_row(int x, int y, int sub_len)
{
    for (int j = 0; j <= (sub_len - 1) / 2; j++)
    {
        if (str[x][y + j] != str[x][sub_len - 1 - j + y])
            return false;
    }
    return true;
}
int check_col(int x, int y, int sub_len)
{
    for (int j = 0; j <= (sub_len - 1) / 2; j++)
    {
        if (str[y + j][x] != str[sub_len - 1 - j + y][x])
            return false;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    int testcase;
    cin >> testcase;
    int n;
    for (int k = 0; k < testcase; k++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> str[i][j];
            }
        }

        int sub_len = n;
        while (sub_len >= 2)

        {
            int check_hang = false;
            int finish = false;
            // check hang
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j <= n - sub_len; j++)
                {
                    int check = check_row(i, j, sub_len);
                    if (check)
                    {
                        check_hang = true;
                        finish = true;
                        cout << "#" << (k + 1) << " " << sub_len << " ";
                        for (int x = j; x < sub_len + j; x++)
                        {
                            cout << str[i][x];
                        }
                        cout << endl;
                        break;
                    }
                }
                if (finish)
                    break;
            }

            // check cot
            if (check_hang == false)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j <= n - sub_len; j++)
                    {
                        int check = check_col(i, j, sub_len);
                        if (check)
                        {
                            finish = true;
                            cout << "#" << (k + 1) << " " << sub_len << " ";
                            for (int x = j; x < sub_len + j; x++)
                            {
                                cout << str[x][i];
                            }
                            cout << endl;
                            break;
                        }
                    }
                    if (finish)
                        break;
                }
            }
            if (finish)
                break;
            sub_len--;
        }
        if (sub_len == 1)
        {
            cout << "#" << (k + 1) << " "
                 << "-1" << endl;
        }
    }
}
