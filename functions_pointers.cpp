#include <iostream>
#include <typeinfo>
#include <cxxabi.h>

bool comparator(int* x, int* y){
    return *x > *y;
}

bool comparator2(int& x, int& y){
    return x > y;
}

int my_max(int* arr, const int len, bool (*comparator)(int*, int*) ){
    int max = 0;
    int* end = arr + len;
    for (; arr<end; ++arr){
        if (comparator(arr, &max)) max = *arr;
    }
    return max;
}

int my_max2(int* arr, const int len, bool (*comparator)(int&, int&) ){
    int max = 0;
    int* end = arr + len;
    for (; arr<end; ++arr){
        if (comparator(*arr, max)) max = *arr;
    }
    return max;
}

int main(){
    int arr[10] = {1,4,5,6,2,5,6,10,20,0};
    std::cout << my_max(arr, 10, &comparator) << '\n' ;
    std::cout << my_max2(arr, 10, &comparator2) << '\n' ;
    return 0;
}