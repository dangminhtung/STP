// thuat toan cay khung
#include <stdio.h>
int n, arr[100][100], sum;
bool visit[100];
void resetVS()
{
    for (int i = 0; i < n; i++)
        visit[i] = false;
}
void solution()
{
    resetVS();
    int dem = 1;
    sum = 0;
    int select;
    visit[0] = true;
    while (dem < n)
    {
        int min = 10000, index = 0;
        
        for (int select = 0; select < n; select++)
        {
            if (visit[select])
            {
                for (int i = 0; i < n; i++)
                {
                    if (i != select && !visit[i] && arr[select][i] < min)
                    {
                        min = arr[select][i];
                        index = i;
                    }
                }
            }
        }
        sum += min;
        visit[index] = true;
        select = index;
        dem++;
    }
}
int main()
{
    //  freopen("Text.txt","r",stdin);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &arr[i][j]);
        solution();
        printf("Case #%d\n%d\n", t, sum);
    }
    return 0;
}
// 1
// 4
// 0 4 9 21
// 4 0 8 17
// 9 8 0 16
// 21 17 16 0