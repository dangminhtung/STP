#include <iostream>
using namespace std;
int arr[100];
int n = 5;
int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int left = start;
    int right = end - 1;
    while (true)
    {
        while (left <= right && arr[left] < pivot)
            left++;
        while (right >= left && arr[right] > pivot)
            right--;
        if (left >= right)
            break;
        swap(arr[left], arr[right]);
        right--;
        left++;
    }
    swap(arr[left], arr[end]);
    return left;
}
void quicksort(int arr[], int start, int end)
{
    if (start < end)
    {
        int index = partition(arr, start, end);

        quicksort(arr, start, index - 1);
        quicksort(arr, index + 1, end);
    }
}
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}