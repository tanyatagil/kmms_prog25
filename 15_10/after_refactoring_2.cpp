#include <cmath>
#include <iostream>

int main()
{
    int  arr_number;
    int size_arr;
    std::cout << "Введите размер массива: " << std::endl;
    std::cin >> size_arr;
    double arr[size_arr];
    for ( arr_number = 1; arr_number < size_arr + 1; arr_number++)
    {
        std::cout << "Введите " << arr_number << " элемент массива:" << std::endl;
        std::cin >> arr[arr_number];
    }

    int premature = 0;
    arr_number = 0;
    bool is_decreasing = false;
    while (arr_number <= size_arr)
    {
        if (arr[arr_number] > arr[arr_number + 1]){
            is_decreasing = true;
            break;
        }
        arr_number++;
    }

    if (is_decreasing) {
        std::cout << "Последовательность не возрастающая";
    }
    else {
        std::cout << "Последовательность возрастающая";
    }

    return 0;
}
