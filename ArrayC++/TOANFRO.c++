#include <iostream>
using namespace std;

int getLength(char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int n;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        char str[1000];
        cin >> str;
        cout << getLength(str) << endl;
    }
}