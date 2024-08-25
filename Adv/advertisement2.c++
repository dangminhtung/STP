#include <stdio.h>
int arr[50][3];
int n, max;
int l[3], p[3];
int end, start;
bool visit[51];
void resetVS()
{
  for (int i = start; i <= end; i++)
    visit[i] = false;
}
void sortQC()
{
  for (int i = 0; i < 2; i++)
    for (int j = i + 1; j < 3; j++)
    {
      if (p[i] < p[j])
      {
        int temp = p[i];
        p[i] = p[j];
        p[j] = temp;
        temp = l[i];
        l[i] = l[j];
        l[j] = temp;
      }
    }
}
bool check(int k, int index)
{
  for (int i = index; i < index + l[k]; i++)
    if (visit[i])
      return false;
  return true;
}
void backTrack(int k, int count)
{
  if (k == 3)
  {
    if (count > max)
      max = count;
    return;
  }

  for (int i = start; i <= end - l[k] + 1; i++)
  {
    if (check(k, i))
    {
      for (int j = 0; j < n; j++)
      {
        if (arr[j][2] == -1 && arr[j][0] <= i && arr[j][0] + arr[j][1] >= i + l[k])
        {
          arr[j][2] = k;
          count += p[k];
        }
      }
      for (int j = i; j < i + l[k]; j++)
        visit[j] = true;
      backTrack(k + 1, count);
      for (int j = 0; j < n; j++)
      {
        if (arr[j][2] == k)
        {
          arr[j][2] = -1;
          count -= p[k];
        }
      }
      for (int j = i; j < i + l[k]; j++)
        visit[j] = false;
    }
  }
  backTrack(k + 1, count);
}
int main()
{
  // freopen("text.txt","r",stdin);
  int test;

  scanf("%d", &test);
  for (int t = 1; t <= test; t++)
  {
    scanf("%d%d%d%d%d%d%d", &n, &l[0], &l[1], &l[2], &p[0], &p[1], &p[2]);
    end = 0;
    start = 50;
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d", &arr[i][0], &arr[i][1]);
      arr[i][2] = -1;
      if (arr[i][0] + arr[i][1] > end)
        end = arr[i][0] + arr[i][1];
      if (arr[i][0] < start)
        start = arr[i][0];
    }
    max = 0;
    resetVS();
    sortQC();
    backTrack(0, 0);
    printf("Case #%d\n%d\n", t, max);
  }
  return 0;
}


