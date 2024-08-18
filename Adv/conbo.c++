// cho n con bò với số cân nặng lần lượt 
// nêu khối lượng tối đa có thể vận chuyển trên xe tải có khối lượng tối đa cho trước 

#include <iostream>
#include <algorithm>
using namespace std;

// Định nghĩa hằng số cho kích thước tối đa của mảng dp
#define MAX_CAPACITY 1000
#define MAX_COWS 1000

int main() {
    int n, maxCapacity;
    
    // std::cout << "Nhập số lượng bò: ";
    std::cin >> n;

    int weights[MAX_COWS];
    
    // std::cout << "Nhập khối lượng mỗi con bò: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i];
    }

    // std::cout << "Nhập trọng tải xe: ";
    std::cin >> maxCapacity;

    int dp[MAX_CAPACITY + 1] = {0};

    for (int i = 0; i < n; ++i) {
        
        for (int w = maxCapacity; w >= weights[i]; --w) {
            dp[w] = std::max(dp[w], dp[w - weights[i]] + weights[i]);

        }
        for(int i=0; i<=10; i++) cout<<dp[i]<<" ";
        cout<<endl;
    }
    
    int maxWeight = dp[maxCapacity];
    // std::cout << "Khối lượng tối đa có thể vận chuyển mà không vượt quá trọng tải xe: " << maxWeight << std::endl;

    return 0;
}
