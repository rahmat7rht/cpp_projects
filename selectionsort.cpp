#include <iostream>

class SelectionSort {
    public:
        void sort(int *array, size_t size) {
            selectionSort(array, size);
        }
    
    private:
        void selectionSort(int *array, size_t size) {
            if (size < 1) return;

            int target = 0;
            int selected = 0;
            int count = 0;

            while (target < size) {
                if (array[selected] > array[count]) {
                    selected = count;
                }

                if (++count >= size) {
                    if (target != selected)
                        swap(array[target], array[selected]); //swap target element with the selected element

                    target++;
                    selected = target;
                    count = target;
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
    
    std::cout << "Unsorted List:\n";
    print(list, size);

    SelectionSort selectionSort;
    selectionSort.sort(list, size);

    std::cout << "Sorted List:\n";
    print(list, size);
}