#include <iostream>

using namespace std;

class BinarySearch {
public:
    BinarySearch(int* arr, int size) : arr(arr), size(size) {}

    int search(int target) {
        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            }

            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

private:
    int* arr;
    int size;
};

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    BinarySearch binarySearch(arr, size);
    int index = binarySearch.search(target);

    if (index != -1) {
        cout << "El objetivo " << target << " se encuentra en el índice " << index << endl;
    } else {
        cout << "El objetivo " << target << " no se encuentra en el arreglo" << endl;
    }

    return 0;
}
