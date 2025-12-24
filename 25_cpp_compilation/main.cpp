#include <iostream>
#include "io.hpp"
#include "sort.hpp"

int main() {
    int size;
    std::cout << "Введите длину массива: ";
    std::cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++){
         std::cout << "Введите " <<i+1<< " элемент массива: " << std::endl;
         std::cin >> arr[i];
    }
    ttv::sortings::bubble_sort(arr, size);

    ttv::print_array("Отсортированный массив: ", arr, size);


    delete[] arr;

    return 0;
}
