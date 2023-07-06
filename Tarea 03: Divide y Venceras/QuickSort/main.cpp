#include <iostream>

using namespace std;

class Quicksort {
private:
    int* arr;
    int size;

public:
    Quicksort(int* array, int arraySize) {
        arr = array;
        size = arraySize;
    }

    void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int partition(int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }

        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }

    void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);

            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    Quicksort quicksort(arr, size);
    cout << "Arreglo original: ";
    quicksort.printArray();

    quicksort.quickSort(0, size - 1);
    cout << "Arreglo ordenado: ";
    quicksort.printArray();

    return 0;
}
