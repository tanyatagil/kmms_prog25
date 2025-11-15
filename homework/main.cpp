#include "sorting.hpp"
#include "io.hpp"

#include <iostream>

int main()
{
    int size;
    int* arr = nullptr;

    std:: cout << "Введите размер массива: ";
    std::cin>>size;

    arr = new int[size];

    ttv::input_array(arr, size);
    ttv::insertion_sort(arr, size);
    ttv::print_array(arr, size);

    delete[] arr;
    return 0;
}
