#include "ttv.hpp"
#include "io.hpp"

int main() {
    int size;
    int* arr = nullptr;

    IO::input_array(arr, size);
    ttv::insertion_sort(arr, size);
    IO::print_array(arr, size);

    delete[] arr;
    return 0;
}
