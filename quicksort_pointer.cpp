#include <iostream>

class QuickSort {
    public:
        void sort(int *array, size_t size) {
            quickSort(array, array + size - 1);
        }

    private:
        int *partition(int *start, int *end) {
            int *pivot = end; //pick the lass element as pivot
            int *low = start; 

            for (int *p = low; p < end; p++) {
                if (*p < *pivot) {
                    if (p != low)
                        swap(*p, *low);
                    low++; //move the low pointer to the next element
                }
            }
            swap(*low, *pivot); //swap the pivot with an element that is in the middle between low and high

            return low; //return the pivot address
        }

        void quickSort(int *start, int *end) {
            if (end - start < 1) return; //break the recursion if the size is less than one

            int *pivot = partition(start, end); //get the pivot partition address
            
            quickSort(start, pivot - 1); //make a new recursion with the end is the element before the pivot
            quickSort(pivot, end); //make a new recursion with the begining is at the pivot address
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