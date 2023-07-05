#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n];
    long long sum[n];
    for (int i = 0; i < n; i++)
        sum[i] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 1; j <= a[i]; j++)
        {
            int temp = a[i] / j;
            sum[i] += temp * j;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << sum[i] << endl;
    }
}