#include <iostream>
using namespace std;
int num[100];
int arr[100];
int phai(int value, int vitri, int n)
{
    if (vitri + 1 > n)
        return -1;
    for (int i = vitri + 1; i < n; i++)
    {
        if (num[i] >= 0)
            return num[i];
    }
    return -1;
}
int trai(int value, int vitri, int n)
{
    if (vitri - 1 < 0)
        return -1;
    for (int i = vitri - 1; i >= 0; i--)
    {
        if (num[i] >= 0)
            return num[i];
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int right = phai(num[arr[i] - 1], arr[i] - 1, n);
            int left = trai(num[arr[i] - 1], arr[i] - 1, n);
            if (right == -1 && left == -1)
            {
                sum += num[arr[i] - 1];
            }
            else if (right == -1)
            {
                sum += left;
            }
            else if (left == -1)
            {
                sum += right;
            }
            else
            {
                sum += right * left;
            }
            num[arr[i] - 1] = -1;
        }

        cout << "#" << k << " " << sum << endl;
    }
}
