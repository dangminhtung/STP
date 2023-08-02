#include <iostream>
using namespace std;
char a[1000][1000];
int x[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int y[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int sum = 0;
void check_hand(int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 'o')
			{
				for (int k = 0; k < 8; k++)
				{
					int row = i + x[k];
					int col = j + y[k];
					if (row >= 0 && row < m && col >= 0 && col < n)
					{
						if (a[row][col] == 'o')
							sum++;
					}
				}
			}
		}
	}
	sum = sum / 2;
}
int main(int argc, char const *argv[])
{
	int m, n;
	cin >> m >> n;

	int check = true;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == '.')
			{
				check = false;
			}
		}
	}

	if (check)
	{
		check_hand(m, n);
	}
	else
	{
		check_hand(m, n);
		int max = 0;
		int dem;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] == '.')
				{
					dem=0;
					for (int k = 0; k < 8; k++)
					{
						int row = i + x[k];
						int col = j + y[k];
						if (row >= 0 && row < m && col >= 0 && col < n)
						{
							// cout << row << " " << col << endl;
							if (a[row][col] == 'o')
								dem++;
						}
					}
					if (dem > max)
					{
						max = dem;
					}
				}
			}
		}
		sum += max;
	}

	cout << sum;
}
