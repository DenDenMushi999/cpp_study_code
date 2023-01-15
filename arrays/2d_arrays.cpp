#include <iostream>
#include <typeinfo>
#include <cxxabi.h>

int main(){

    // 10 pointers to pointers
    // each pointer points to defferent a[10]
    int* a[10];
    // a -pointer to pointer
    // a[0] 0th pointer

    // a will be:
    // {
    //         *a[0],   *a[1],   *a[2]  *a[3],  *a[4], ...
    //    a   {   1,      2,       3,     4,      5,   6},
    //         *(a+1)[0], *(a+2)[1],   *(a+3)[2] ...
    //    a+1 {   1,         2,            3,       4,  5,  6},
    //              ...
    // }

    // int** arrarr[10]; it's not correct way to form 2d array;

    // int a[10] = {1,2,3,4,5,6,7,8,9,10};

    for (int i=0; i<10; ++i){
        // firstly allocate memory for subarray elements
        *(a+i) = new int[10];
        for (int j=0; j<10; ++j)
            *(*(a+i)+j) = j;
    }

    for (int i=0; i<10; ++i){
        for (int j=0; j<10; ++j)
            std::cout << a[i][j] << ' ';
        std::cout << '\n';
    }

    for (int i=0; i<10; ++i){
        for (int j=0; j<10; ++j)
            a[i][j] = 10-j;
    }

    for (int i=0; i<10; ++i){
        for (int j=0; j<10; ++j)
            std::cout << a[i][j] << ' ';
        std::cout << '\n';
    }

    //// TODO: 2D array where I can't change addreses of columns, but can change columns itself
    // const int* arr[5];

    // Can't do that
    // for (int i=0; i<5; ++i){
    //     // firstly allocate memory for subarray elements
    //     arr[i] = new int(5);
    //     for (int j=0; j<5; ++j)
    //         *(arr[i]+j) = j;
    // }

    // for (int i=0; i<5; ++i){
    //     for (int j=0; j<5; ++j)
    //         std::cout << arr[i][j] << ' ';
    //     std::cout << '\n';
    // }

    return 0;
}
