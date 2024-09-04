#include <iostream>
using namespace std;

int S, power;
int arr[5][2];
int min_time;
void backtrack(int k, int time, int pow, int s)
{
	if (pow > power)
		return;
	if (time >= min_time)
	{
		return;
	}
	if (s == 0)
	{
		min_time = min(min_time, time);
		return;
	}
	if (k == 4)
	{
		backtrack(k + 1, time + arr[k][0] * s, pow + arr[k][1] * s, 0);
	}
	else
	{
		for (int i = s; i >= 0; i--)
		{
			backtrack(k + 1, time + arr[k][0] * i, pow + arr[k][1] * i, s - i);
		}
	}
}

int main()
{
	freopen("Text.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> power >> S;
		int m;
		for (int i = 0; i < 5; i++)
		{
			cin >> m;
			cin >> arr[i][0];
			cin >> arr[i][1];
			arr[i][0] = arr[i][0] + m * 60;
		}
		// sort();
		min_time = 1000000;
		backtrack(0, 0, 0, S);
		cout << "Case #" << t + 1 << endl;
		if (min_time == 1000000)
		{
			cout << "-1" << endl;
		}
		else
			cout << min_time / 60 << " " << min_time % 60 << endl;
	}
	return 0;
}
4

	297 10

	5 38 23 5 22 12 4 16 6 5 38 20 0 20 17

	192 10

	2 6 12 6 5 24 2 22 22 4 13 12 4 30 16

	503 10

	1 42 20 1 8 14 0 33 15 2 6 6 5 3 16

	122 10

	2 37 21 3 59 22 6 0 22 4 56 5 0 9 10 Case #1

	3 20

	Case #2

	21 0

	Case #3

	5 30

	Case #4

	1 30