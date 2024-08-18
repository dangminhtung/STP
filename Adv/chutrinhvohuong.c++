#include <iostream>

using namespace std;

const int MAX = 100; // Số đỉnh tối đa

int adj[MAX][MAX]; // Ma trận kề
bool visited[MAX]; // Mảng đánh dấu đã thăm
int parent[MAX];   // Mảng lưu đỉnh cha của mỗi đỉnh trong DFS
int V;             // Số đỉnh

void printCycle(int start, int end) {
    cout << "Chu trinh: ";
    cout << start;
    int temp = end;
    while (temp != start) {
        cout << " <- " << temp;
        temp = parent[temp];
    }
    cout << " <- " << start << endl;
}

bool DFS(int v) {
    visited[v] = true;

    // Duyệt qua tất cả các đỉnh kề của v
    for (int u = 0; u < V; u++) {
        if (adj[v][u]) { // Nếu có cạnh từ v đến u
            if (!visited[u]) { // Nếu đỉnh u chưa được thăm
                parent[u] = v; // Đặt đỉnh cha của u là v
                if (DFS(u)) {
                    return true;
                }
            } else if (u != parent[v]) { // Nếu u đã được thăm và không phải là cha của v
                printCycle(u, v); // In chu trình
                return true;
            }
        }
    }
    return false;
}

bool hasCycle() {
    for (int v = 0; v < V; v++) {
        visited[v] = false; // Đánh dấu tất cả các đỉnh là chưa được thăm
        parent[v] = -1; // Đặt cha của mỗi đỉnh là -1 (chưa có cha)
    }

    // Kiểm tra tất cả các đỉnh
    for (int v = 0; v < V; v++) {
        if (!visited[v]) { // Nếu đỉnh chưa được thăm
            if (DFS(v)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cout << "Nhap so dinh cua do thi: ";
    cin >> V;

    // Khởi tạo ma trận kề với tất cả các phần tử bằng 0
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    int E;
    cout << "Nhap so canh cua do thi: ";
    cin >> E;

    cout << "Nhap cac canh (dinh u va v voi moi canh):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // Vì là đồ thị vô hướng
    }

    if (hasCycle()) {
        cout << "Do thi co chu trinh" << endl;
    } else {
        cout << "Do thi khong co chu trinh" << endl;
    }

    return 0;
}
