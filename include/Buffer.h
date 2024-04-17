#pragma once
// #include <cstdint>
#include <stdio.h>

namespace std{
    using size_t = long unsigned int;
};

template<typename T, std::size_t SIZE>
class Buffer{
public:

    template<std::size_t NEW_SIZE>
    void Allocate(){
        delete[] arr;
        arr = int(NEW_SIZE);
    }

    void displayPrint(){
        std::size_t size = sizeof(arr);
        printf("Size is %u\n", size);
    }


private:
    T arr[SIZE];
};