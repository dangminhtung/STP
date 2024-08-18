#include <iostream>
using namespace std;

const int MAX = 100;
bool adj[MAX][MAX];  // Ma trận kề
bool visited[MAX];   // Mảng đánh dấu đỉnh đã thăm
int parent[MAX];     // Mảng lưu cha của mỗi đỉnh
int cycle[MAX];      // Mảng lưu các đỉnh trong chu trình
int cycleIndex;      // Chỉ số hiện tại trong mảng cycle

// Hàm DFS để tìm chu trình
bool dfs(int v, int V) {
    visited[v] = true;

    // Duyệt qua các đỉnh kề
    for (int u = 0; u < V; u++) {
        if (adj[v][u]) {
            // Nếu đỉnh u chưa được thăm, gọi đệ quy DFS
            if (!visited[u]) {
                parent[u] = v;
                if (dfs(u, V)) {
                    return true;
                }
            }
            // Nếu đỉnh u đã được thăm và không phải là cha của v, thì có chu trình
            else if (u != parent[v]) {
                // Xây dựng chu trình từ u đến v
                cycle[cycleIndex++] = u;
                int cur = v;
                while (cur != u) {
                    cycle[cycleIndex++] = cur;
                    cur = parent[cur];
                }
                cycle[cycleIndex++] = u; // Đóng chu trình
                return true;
            }
        }
    }
    return false;
}

// Hàm kiểm tra và in ra chu trình
void findCycle(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            parent[i] = -1; // Đỉnh đầu tiên không có cha
            cycleIndex = 0; // Đặt lại chỉ số mảng cycle
            if (dfs(i, V)) {
                // In ra chu trình
                cout << "Chu trinh: ";
                for (int j = cycleIndex - 1; j >= 0; j--) {
                    cout << cycle[j] << " ";
                }
                cout << endl;
                return;
            }
        }
    }
    cout << "Do thi khong co chu trinh.\n";
}

int main() {
    int V, E;
    cout << "Nhap so dinh (V) va so canh (E): ";
    cin >> V >> E;

    // Khởi tạo ma trận kề và mảng visited, parent
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = false;
        }
        visited[i] = false;
        parent[i] = -1;
    }

    // Nhập các cạnh của đồ thị
    cout << "Nhap cac canh (u, v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = true;
    }

    // Tìm và in ra chu trình nếu có
    findCycle(V);

    return 0;
}
