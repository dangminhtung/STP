// https://pastecode.io/s/50cvnm9b
#include<iostream>
using namespace std;
#define MAX 10000
struct Point
{
    int x, y;
};
class Queue
{
    Point data[MAX];
    int rear, front;

public:
    Queue();
    bool is_empty();
    void enQue(Point& value);
    Point deque();
};
Queue::Queue()
{
    front = -1;
    rear = -1;
}
bool Queue::is_empty()
{
    if (front == rear)
        return true;
    return false;
}
void Queue::enQue(Point& value)
{
    data[++rear] = value;
}
Point Queue::deque()
{
    front++;
    Point value = data[front];
    return value;
}


int n, m;
int arr[100][100];
Point dirty[21];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int visited[100] = { 0 };

void bfs(int index, int distance[][21][21]) {
    Point value = dirty[index];
    
    distance[index][value.x][value.y] = 1;
    Queue queue;
    queue.enQue(value);
    
    while (!queue.is_empty()) {
        value = queue.deque();
        for (int i = 0; i < 4; i++) {
            int tempx = value.x + dx[i];
            int tempy = value.y + dy[i];
            
            if (tempx >= 0 && tempx < n && tempy >= 0 && tempy < m && distance[index][tempx][tempy] == 0 && arr[tempx][tempy] != 2) {
                distance[index][tempx][tempy] = distance[index][value.x][value.y]+1;
                Point temp{};
                temp.x = tempx; temp.y = tempy;
                queue.enQue(temp);
            }
            
        }
    }

        
}


void backtract(int index, int nDirty, int dis, int &min, int count, int distance[][21][21]) {
    if (dis > min) return;
    if (nDirty == count) {
        if (dis < min) min = dis;
        return;
    }
    visited[index] = 1;
    for (int i = 1; i < count; i++) {
        if (visited[i] == 0) {
            if (distance[index][dirty[i].x][dirty[i].y] != 0)
                backtract(i, nDirty + 1, dis + distance[index][dirty[i].x][dirty[i].y] - 1, min, count, distance);
            else break;
        }
    }
    visited[index] = 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int count = 1;
    Point value{};
    int min = 5000;
    int distance[21][21][21] = { 0 };
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            for (int k = 0; k < 21; k++) distance[i][j][k] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 3) {
                dirty[0].x = i;
                dirty[0].y = j;
            }
            if (arr[i][j] == 1) {
                value.x = i;
                value.y = j;
                dirty[count++] = value;
            }
        }
    }   
     for (int i = 0; i < count; i++)
        bfs(i, distance);
     backtract(0, 1, 0, min, count, distance);
     cout << min << endl;

}