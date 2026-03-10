#include <iostream>

class MergeSort {
    public:
        void sort(int *array, size_t size, bool reverse = false) {
            this->reverse = reverse;
            temp_array = new int[size]; //allocate memory same size as the original array
            mergeSort(array, size);
            delete [] temp_array; //delete allocated memory
        }

    private:
        bool reverse = false;
        int *temp_array = nullptr;

        void mergeSort(int *array, size_t size) {
            if (size <= 1) return; //break if the size is less or equal than one
            int middle = size / 2;

            mergeSort(array, middle); //left recursion, the size is half
            mergeSort(array + middle, size - middle); //right recursion, the begining of array is at the middle, size is also half

            merge(array, size, middle); //merge the two subarrays
        }

        void merge(int *array, size_t size, int middle) {
            int first = 0; //beginning of first sub array
            int second = middle; //beginning of second sub array
            int count = 0;

            while (first < middle && second < size) {
                //compare the elements in the two subarray
                if (!reverse? (array[first] < array[second]) : (array[first] > array[second])) {
                    temp_array[count++] = array[first++];
                } else {
                    temp_array[count++] = array[second++];
                }
            }

            while (first < middle) {
                temp_array[count++] = array[first++];
            }

            while (second < size) {
                temp_array[count++] = array[second++];
            }

            for (count = 0; count < size; count++) {
                array[count] = temp_array[count];
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