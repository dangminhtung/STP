#include <iostream>
#include <string.h>
using namespace std;
char str[10000];
int check_rev(int i, int sub_len)
{
    for (int j = 0; j <= (sub_len - 1) / 2; j++)
    {
        if (str[j + i] != str[sub_len - 1 - j + i])
        {
            return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {

        cin >> str;
        int length = strlen(str);
        int sub_len = length;
        while (sub_len >= 2)
        {
            int finish = false;
            for (int i = 0; i <= length - sub_len; i++)
            {
                int check = check_rev(i, sub_len);
                if (check)
                {
                    finish = true;
                    cout << "#" << (k + 1) << " " << sub_len << " ";
                    for (int x = i; x < sub_len + i; x++)
                    {
                        cout << str[x];
                    }
                    cout << endl;
                    break;
                }
            }
            if (finish)
            {
                break;
            }
            sub_len--;
        }
        if (sub_len == 1)
        {
            cout << "#" << (k + 1) << " "
                 << "-1" << endl;
        }
    }
}
