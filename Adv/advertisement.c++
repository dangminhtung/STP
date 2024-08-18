#include<iostream>
using namespace std;

int n, point, maxTime;
int ads[3][3];
int visitor[50][3];
int watch[50][3];
int arr[3][2];

int cal(int x, int start, int end, int p) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (visitor[i][0] <= start && visitor[i][1] >= end) {
      watch[i][x] = true;
      if (visitor[i][2] < p) {
        sum += (p - visitor[i][2]);
        visitor[i][2] = p;
      }
    }
  }
  return sum;
}
void unchoose(int x) {
  for (int i = 0; i < n; i++) {
    watch[i][x] = false;
  }
  for (int i = 0; i < n; i++) {
    visitor[i][2] = 0;
    for (int j = 0; j < 3; j++) {
      if (watch[i][j]) visitor[i][2] = max(visitor[i][2], ads[j][1]);
    }
  }
}
void backtrack(int cur, int choose, int score) {
  if (choose == 3) {
    point = max(point, score);
    return;
  }
  if (cur >= maxTime) {
    point = max(point, score);
    return;
  }
  for (int i = 0; i < 3; i++) {
    if (ads[i][2] == 0 && cur + ads[i][0] <= maxTime) {
      ads[i][2] = 1;
      backtrack(cur + ads[i][0], choose + 1, score + cal(i, cur, cur + ads[i][0], ads[i][1]));
      unchoose(i);
      ads[i][2] = 0;
    }
  }
  backtrack(cur + 1, choose, score);
}
int main() {
  FILE* file;
  freopen_s(&file, "input.txt", "r", stdin);
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> n;
    point = 0;
    for (int i = 0; i < 3; i++) {
      cin >> ads[i][0];
    }
    for (int i = 0; i < 3; i++) {
      cin >> ads[i][1];
      ads[i][2] = 0;
    }
    maxTime = 0;
    for (int i = 0; i < n; i++) {
      cin >> visitor[i][0];
      cin >> visitor[i][1];
      visitor[i][1] += visitor[i][0];
      maxTime = max(maxTime, visitor[i][1]);
      visitor[i][2] = 0;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 3; j++) {
        watch[i][j] = false;
      }
    }
    backtrack(1, 0, 0);
    cout<<"Case #"<<t+1<<" "<< point << endl;
  }
  return 0;
}
1
7 1 2 3 1 2 3
2 2
6 4
3 3
7 2
1 1
2 1
1 10
