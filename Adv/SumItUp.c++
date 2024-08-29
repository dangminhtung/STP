#include <iostream>
using namespace std;

int t, n, arr[100], test;
int ans;
int map[50][50];
int c;
int check()
{
    int check_loop;
    for (int i = 0; i < c; i++)
    {
        check_loop = 0;
        for (int j = 1; j <= map[c][0]; j++)
        {
            if (map[i][j] != map[c][j])
            {
                check_loop = 1;
                break;
            }
        }
        if (check_loop == 0)
            return false;
    }

    return true;
}
void backtrack(int index, int sum)
{
    if (sum > t)
        return;
    if (sum == t)
    {
        if (check())
        {
            ans++;
            c++;
            for (int i = 0; i <= map[c - 1][0]; i++)
                map[c][i] = map[c - 1][i];
        }
        return;
    }
    if (index == n)
        return;
    map[c][0]++;
    map[c][map[c][0]] = arr[index];
    backtrack(index + 1, sum + arr[index]);
    map[c][0]--;
    backtrack(index + 1, sum);
}
int main()
{
    freopen("Text.txt", "r", stdin);
    cin >> test;
    for (int q = 0; q < test; q++)
    {
        cin >> t >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                map[i][j] = 0;
        }
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        ans = 0;
        c = 0;
        backtrack(0, 0);
        if (ans)
            cout << "#" << q + 1 << " " << ans << endl;
        else
            cout << "#" << q + 1 << " " << "-1" << endl;
    }
    return 0;
}
4

    4 6

    4 3 2 2 1 1

    5 3

    2 1 1

    400 12

    50 50 50 50 50 50 25 25 25 25 25 25

    20 10

    1 2 3 4 5 6 7 8 9 10

    Output

# 1 4

# 2 - 1

# 3 2

# 4 31

        Giải thích

# 1

    4

    3 +
    1

    2 +
    2

    2 +
    1 + 1

# 3

    50 +
    50 + 50 + 50 + 50 + 50 + 25 + 25 + 25 + 25

    50 +
    50 + 50 + 50 + 50 + 25 + 25 + 25 + 25 + 25 + 25

# 4

    1 +
    2 + 3 + 4 + 10

    1 +
    2 + 3 + 5 + 9

    1 +
    2 + 3 + 6 + 8

    1 +
    2 + 4 + 5 + 8

    1 +
    2 + 4 + 6 + 7

    1 +
    2 + 7 + 10

    1 +
    2 + 8 + 9

    1 +
    3 + 4 + 5 + 7

    1 +
    3 + 6 + 10

    1 +
    3 + 7 + 9

    1 +
    4 + 5 + 10

    1 +
    4 + 6 + 9

    1 +
    4 + 7 + 8

    1 +
    5 + 6 + 8

    1 +
    9 + 10

    2 +
    3 + 4 + 5 + 6

    2 +
    3 + 5 + 10

    2 +
    3 + 6 + 9

    2 +
    3 + 7 + 8

    2 +
    4 + 5 + 9

    2 +
    4 + 6 + 8

    2 +
    5 + 6 + 7

    2 +
    8 + 10

    3 +
    4 + 5 + 8

    3 +
    4 + 6 + 7

    3 +
    7 + 10

    3 +
    8 + 9

    4 +
    6 + 10

    4 +
    7 + 9

    5 +
    6 + 9

    5 +
    7 + 8