#include <iostream>

class QuickSort {
    public:
        void sort(int *array, size_t size) {
            quickSort(array, size);
        }

    private:
        int *partition(int *array, size_t size) {
            int *pivot = &array[size - 1]; //pick the lass element as pivot
            int count = 0; 

            for (int i = 0; i < size; i ++) {
                if (array[i] < *pivot) {
                    if (i != count)
                        swap(array[i], array[count]);
                    count++; //count the element that are less(or more in reverse) than the pivot
                }
            }
            swap(array[count], *pivot); //move the pivot between the lower and higher value elements compare to it

            return &array[count]; //return the last pivot index position
        }

        void quickSort(int *array, size_t size) {
            if (size <= 1) return; //break the recursion if the size is less than two

            int *po_pivot = partition(array, size); //get the pivot last position
            int sub_size = po_pivot - array; //calculate the size of the last partition that contain elements less than the last pivot

            quickSort(array, sub_size); //make new recursion as the end is the last pivot
            quickSort(po_pivot, size - sub_size); //make new recursion as the begining is the last pivot
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
    int list[size] = {65, 33, 98, 7, 28, 66, 89, 9, 22};
    
    std::cout << "Unsorted List:\n";
    print(list, size);

    QuickSort quickSort;
    quickSort.sort(list, size);

    std::cout << "Sorted List:\n";
    print(list, size);
}