#include <iostream>
using namespace std;
#define MAX 10000
class Queue
{
    int data[MAX];
    int rear, front;

public:
    Queue();
    bool is_empty();
    void enQue(int value);
    int deque();
};
Queue::Queue()
{
    rear = front = -1;
}
bool Queue::is_empty()
{
    if (front = rear)
        return true;
    return false;
}
void Queue::enQue(int value)
{
    data[++rear] = value;
}
int Queue::deque()
{
    front++;
    return data[front];
}

int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int n;
    int arr[300][300];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = n;
        }
    }
    int x, y;
    bool visited[1000];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout << i << endl;

            cin >> x >> y;
            x = x - 1;
            y = y - 1;
            arr[x][y] = i + 1;
        }
        visited[i + 1] = false;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
