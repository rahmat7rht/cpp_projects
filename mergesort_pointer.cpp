#include <iostream>

class MergeSort {
    public:
        void sort(int *array, size_t size, bool reverse = false) {
            this->reverse = reverse;
            temp_array = new int[size]; //allocate memory same size as the original array
            mergeSort(array, array + size - 1);
            delete [] temp_array; //delete allocated memory
        }

    private:
        bool reverse = false;
        int *temp_array = nullptr;

        void mergeSort(int *start, int *end) {
            if ((end - start) < 1) return; //break if the size is less than one
            int *middle = start + ((end - start) / 2);

            mergeSort(start, middle); //left recursion, the size is half
            mergeSort(middle + 1, end); //right recursion, the begining of array is at the middle, size is also half

            merge(start, middle, middle + 1, end); //merge the two subarrays
        }

        void merge(int *start, int *end, int *start2, int *end2) {
            int *first = start; //beginning of first sub array
            int *second = start2; //beginning of second sub array
            size_t count = 0;
            bool condition = false;

            while (first <= end && second <= end2) {
                //compare the elements in the two subarray
                condition = !reverse?
                    *first < *second :
                    *first > *second;
                
                if (condition) {
                    temp_array[count++] = *(first++);
                } else {
                    temp_array[count++] = *(second++);
                }
            }

            while (first <= end) {
                temp_array[count++] = *(first++);
            }

            while (second <= end2) {
                temp_array[count++] = *(second++);
            }

            for (int i = 0; i < count; i++) {
                start[i] = temp_array[i];
            }
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
    MergeSort mergesort;
    
    std::cout << "Unsorted List:\n";
    print(list, size);

    mergesort.sort(list, size);
    std::cout << "Sorted List:\n";
    print(list, size);
}