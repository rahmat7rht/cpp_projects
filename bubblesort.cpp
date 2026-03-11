#include <iostream>

class BubbleSort {
    public:
        void sort(int *array, size_t size) {
            bubbleSort(array, size);
        }

    private:
        void bubbleSort(int *array, size_t size) {
            int n = 0;
            int length = size;
            while (length > 0) {
                if (array[n] > array[n + 1]) {
                    swap(array[n], array[n + 1]);
                }
                
                if (!(++n < length)) {
                    n = 0;
                    length--;
                }
            }
        }

        void swap(int &a, int &b) {
            int temp = a;
            a = b;
            b = temp;
        }
};

void print(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << ((i + 1) < size? ", ":"\n");
    }
}

int main() {
    int size = 8;
    int array[size] = {5, 3, 99, 32, 44, 2, 13, 11};

    std::cout << "Unsorted list:\n";
    print(array, size);

    BubbleSort bubble;
    bubble.sort(array, size);

    std::cout << "Sorted list:\n";
    print(array, size);
}