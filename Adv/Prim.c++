#include<iostream>
using namespace std;

int test, n;
int arr[20][20]; 
int key[20];
int min_p=0;
int visited[20] = {0};

int minKey() {
    int min = 99999;
    int min_index;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void Prim() {
    for (int i = 0; i < n; i++) {
        key[i] = 99999;
        visited[i] = 0;
    }
    key[0] = 0;

    for (int c = 0; c < n ; c++) {
        int index = minKey();
        visited[index] = 1;
        min_p += key[index];
        for (int i = 0; i < n; i++) {
            if (!visited[i] && arr[index][i] && key[i] > arr[index][i]) {
                key[i] = arr[index][i];
            }
        }
    }
}

int main() {
    FILE* file;
    freopen_s(&file, "Text.txt", "r", stdin);
    cin >> test;
    for (int t = 0; t < test; t++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> arr[i][j];
        }
        Prim();
        cout << min_p << endl;
    }
    return 0;
}