#include <iostream>
using namespace std;
long n, value, len;

int main(int argc, char const *argv[])
{
    int testcase;
    cin >> testcase;

    for (int tc = 0; tc < testcase; tc++)
    {
        // khoi tao mang luu tru
        static long long arr[1000000];
        len = 2;
        arr[0] = 1;
        arr[1] = 0;
        // input str
        char str;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> str;
            if (j % 2 == 0)
                value = 1;
            else
                value = 0;
            if (str == 'L')
            {

                len++;
                for (int i = len - 1; i > 0; i--)
                {
                    arr[i] = arr[i - 1];
                }
                arr[0] = value;
                if (arr[1] == value)
                    continue;
                else
                {
                    int check = false;
                    for (int i = 1; i < len; i++)
                    {
                        if (arr[i] == value)
                            check = true;
                    }
                    if (check)
                    {
                        int h = 1;
                        while (arr[h] != value)
                        {
                            arr[h] = value;
                            h++;
                        }
                    }
                }
            }
            else if (str == 'R')
            {
                len++;
                arr[len - 1] = value;
                if (arr[len - 2] == value)
                    continue;
                else
                {
                    int check = false;
                    for (int i = len - 2; i >= 0; i--)
                    {
                        if (arr[i] == value)
                            check = true;
                    }
                    if (check)
                    {
                        int h = len - 2;
                        while (arr[h] != value)
                        {
                            arr[h] = value;
                            h--;
                        }
                    }
                }
            }
        }
        int den = 0, trang = 0;
        for (int i = 0; i < len; i++)
        {
            if (arr[i] == 1)
                den++;
            else
                trang++;
        }
        cout << "#" << (tc + 1) << " " << den << " " << trang << endl;
    }
    return 0;
}