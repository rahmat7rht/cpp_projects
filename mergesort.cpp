#include <iostream>

class MergeSort {
    public:
        void mergeSort(int *array, int size) {
            if (size <= 1) return;

            int middle = size / 2;
            int remain = size - (middle * 2); //a remaining element if the size is odd

            if (size > 2) { //make subarray if the elements are more than two
                mergeSort(array, middle); //left recursion
                mergeSort(array + middle, middle + remain); //right recurtion
            }

            merge(array, size, middle); //merge the subarray
        }
    private:
        bool reverse = false;

        void merge(int *array, int size, int middle) {
            int *temp_array = new int[size]; //allocated some memory for temp_array
            int first = 0; //beginning of first sub array
            int second = middle; //beginning of second sub array
            int count = 0;

            while (first < middle && second < size) {
                if (array[first] < array[second]) {
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

            delete [] temp_array; //delete allocated memory temp_array
        }

};

void print(int *array, int size) {
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

    mergesort.mergeSort(list, size);
    std::cout << "Sorted List:\n";
    print(list, size);
}