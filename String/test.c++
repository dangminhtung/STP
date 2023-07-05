#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "Hello world!";
    string subStr = "world";
    int subStrLen = subStr.length();
    int strLen = str.length();

    for (int i = strLen - 1; i >= 0; i--)
    {
        int j;
        for (j = 0; j < subStrLen && i - j >= 0; j++)
        {
            if (str[i - j] != subStr[subStrLen - j - 1])
            {
                break;
            }
        }
        if (j == subStrLen)
        {
            cout << "Substring found at position " << i - subStrLen + 1 << endl;
            return 0;
        }
    }

    cout << "Substring not found!" << endl;
    return 0;
}
