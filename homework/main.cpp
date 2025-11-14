#include "sort.hpp"
#include "io.hpp"

int main()
{
    int size;
    int* arr = nullptr;

    io::input_array(arr, size);
    ttv::insertion_sort(arr, size);
    io::print_array(arr, size);

    delete[] arr;
    return 0;
}
