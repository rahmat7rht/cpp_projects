#include <iostream>

class QuickSort {
    public:
        void sort(int *array, size_t size) {
            quickSort(array, size);
        }

    private:
        int *partition(int *array, size_t size) {
            int *pivot = &array[size - 1];
            int count = 0; //count the element that are less(or more) than the pivot

            for (int i = 0; i < size; i ++) {
                if (array[i] < *pivot) {
                    if (i != count)
                        swap(array[i], array[count]);
                    count++;
                }
            }
            swap(array[count], *pivot); //move the pivot between the lower and higher values compare to it

            return &array[count]; //return the last pivot position
        }

        void quickSort(int *array, size_t size) {
            if (size <= 1) return; //break the recursion if the size is less than two

            int *po_partition = partition(array, size); //get the pivot position
            int sub_size = po_partition - array; //the size of the left subpartition

            quickSort(array, sub_size);
            quickSort(po_partition, size - sub_size); //the size is remain size of the total size minus the sub_size
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
    int list[size] = {65, 33, 98, 3, 2, 66, 89, 9, 44};
    
    std::cout << "Unsorted List:\n";
    print(list, size);

    QuickSort quickSort;
    quickSort.sort(list, size);

    std::cout << "Sorted List:\n";
    print(list, size);
}