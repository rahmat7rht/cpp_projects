#include <iostream>

class InsertionSort {
    public:
        void sort(int *array, size_t size) {
            insertionSort(array, size);
        }

    private:
        void insertionSort(int *array, size_t size) {
            int length = 0;
            int index_select = 0;

            while (length < size) {
                if (index_select <= 0) { //check if the index is equal or less than zero, if so, select next element
                    index_select = ++length;
                    continue;
                }

                if (array[index_select - 1] > array[index_select]) { //compare the selected index value with the element before it
                    swap(array[index_select - 1], array[index_select]); //swap or move the selected element to the left
                    index_select--; //keep track the selected element
                } else { //if the element value before it is less than it, leave it and select next element
                    index_select = ++length;
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
    const int size = 9;
    int list[size] = {65, 33, 98, 3, 2, 66, 89, 9, 5};

    std::cout << "Unsorted list:";
    print(list, size);

    InsertionSort insertionSort;
    insertionSort.sort(list, size);

    std::cout << "Sorted list:";
    print(list, size);
}