#include <iostream>
#include <string.h>

using namespace std;
int main(int argc, char const *argv[])
{

    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        char str[10000];
        cin >> str;
        int length = strlen(str);
        int check = true;
        for (int i = 0; i <= (length - 1) / 2; i++)
        {
            if (str[i] != str[length - 1 - i])
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            cout << "#" << (k + 1) << " "
                 << "YES" << endl;
        }
        else
        {
            cout << "#" << (k + 1) << " "
                 << "NO" << endl;
        }
    }
    return 0;
}