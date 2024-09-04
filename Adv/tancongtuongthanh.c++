#include<stdio.h>
int map[100];
int arr[102][100];
bool visit[100];
int top, m;
void push(int x) {
    map[++top] = x;
}
int pop() {
    return map[top--];
}
bool timChuTrinh(int t, int cur) {
    visit[cur] = true;
    push(cur);
    for (int i = 2; i <= arr[1][cur] + 1; i++) {
        if (arr[i][cur] == t && top > 1)
            return true;
        if (arr[i][cur] != -1 && !visit[arr[i][cur]] && timChuTrinh(t, arr[i][cur]))
            return true;
    }
    pop();
    return false;
}
void resetVS() {
    for (int i = 0; i < m; i++)
        visit[i] = false;
}
void solution(int t) {

    long long int sum = 0;
    for (int t = 0; t < m; t++) {
        resetVS();
        top = -1;
        while (timChuTrinh(t, t)) {
            int min = 100000, x, y;
            for (int i = 0; i < top; i++) {
                if (arr[0][map[i]] + arr[0][map[i + 1]] < min) {
                    min = arr[0][map[i]] + arr[0][map[i + 1]];
                    x = map[i];
                    y = map[i + 1];
                }
            }
            if (arr[0][map[top]] + arr[0][map[0]] < min) {
                min = arr[0][map[top]] + arr[0][map[0]];
                x = map[top];
                y = map[0];
            }
            top = -1;
            sum += min;
            for (int i = 2; i <= arr[1][x] + 1; i++)
                if (arr[i][x] == y) {
                    arr[i][x] = -1;
                    break;
                }
            for (int i = 2; i <= arr[1][y] + 1; i++)
                if (arr[i][y] == x) {
                    arr[i][y] = -1;
                    break;
                }
            resetVS();
        }

    }
    printf("Case #%d\n%lld\n", t, sum);
}   
int main() {
   //FILE* file;
    //freopen_s(&file,"Text.txt","r",stdin);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++) {

        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            int k;
            scanf("%d", &k);
            scanf("%d%d", &arr[0][k], &arr[1][k]);
            for (int j = 2; j <= arr[1][k] + 1; j++)
                scanf("%d", &arr[j][k]);
        }

        solution(t);
    }

    return 0;
}