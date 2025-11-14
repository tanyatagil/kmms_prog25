#include "io.hpp"

namespace io
{
    void input_array(int*& arr, int& size)
    {
        std:: cout << "Введите размер массива: ";
        std::cin>>size;

        arr = new int[size];
        for (int arr_number = 0; arr_number < size; arr_number++)
        {
            std::cout << "Введите " << arr_number + 1 << " элемент массива:" << std::endl;
            std::cin >> arr[arr_number];
        }
    }

    void print_array(const int* arr, int size)
    {
        std::cout << "Отсортированный массив: ";
        for (int arr_number = 0; arr_number < size; arr_number++)
        {
            std::cout << arr[arr_number] << " " ;
        }
        std::cout << std::endl;
    }
}
