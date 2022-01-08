#include <iostream>

using std::cout;
using std::endl;

#define MAX 9
int tmp[MAX];

void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int l = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            tmp[k] = arr[i];
            i++;
        }
        else {
            tmp[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i == mid + 1) {
        while (j <= right) {
            tmp[k] = arr[j];
            j++;
            k++;
        }
    }
    else {
        while (i <= mid) {
            tmp[k] = arr[i];
            i++;
            k++;
        }
    }
    while (l < k) {
        arr[l] = tmp[l];
        l++;
    }
}
void merge_sort(int arr[], int left, int right) {
    int mid = (left + right) / 2;

    if (left < right) {
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[MAX] = { 7,4,5,1,3,2,6,9,8 };

    int size = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }

    cout << endl;

    return 0;
}