#include <iostream>
namespace ttv{
    void insertion_sort(int* arr, int size);
}

int main(){
    int size;
    std:: cout << "Введите размер массива: ";
    std::cin>>size;

    int* arr = new int[size];
    for (int arr_number = 0; arr_number < size; arr_number++)
    {
        std::cout << "Введите " << arr_number + 1 << " элемент массива:" << std::endl;
        std::cin >> arr[arr_number];
    }

    ttv::insertion_sort(arr, size);

    std::cout << "Отсортированный массив: ";
    for (int arr_number = 0; arr_number < size; arr_number++){
        std::cout << arr[arr_number] << " " ;
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}

void ttv::insertion_sort(int* arr, int size){
    for (int i = 1;i < size; i++){
        int key = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > key){
            arr[prev + 1] = arr[prev];
            --prev;
        }
        arr[prev + 1] = key;
    }
}
