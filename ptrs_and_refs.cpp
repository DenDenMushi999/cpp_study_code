#include <iostream>
#include <typeinfo>
#include <cxxabi.h>

char* demangle(const char* mangled_name, int *status){
    return (abi::__cxa_demangle(mangled_name, 0, 0, status));
}

int main(){

    // whats happening when when use '=' with initialized constant on left and right side
    int x = 5;
    int* px = &x;
    // px = 3; compile-error. cannot convert 'int' to 'int*'
    int status;
    std::cout << "type of 'px': "
    << demangle( typeid(px).name(), &status) << "\n" << px << '\n';
    int* px2 = px;
    *px2 += 1;
    std::cout << x << ' ' << *px << ' ' << *px2 << '\n' ;
    int** pp = &px;
    std::cout
    << "&px: " << &px
    << ", pp: " << pp
    << ", &pp: " << &pp
    << ", **pp: " << **pp << '\n';


    // what if we allocate space for int array but create const int*
    const int* parr = new int[10];
    // parr[0] = 0; // compile-error: read-only
    // parr[11] = 11; // also error: we cannot change anything via *parr
    int* parr2 = new int[10];
    parr2[0] = 0;

    int& refx = x;
    refx += 1;
    const int& c_refx = x;
    // c_refx += 1; compile-error: can't change through c_refx

    x+=1; // but you still can change x diretly, and c_refx will see this changes

    // it will return type of variable its refferenced
    std::cout << "type of 'refx:' "
    << demangle(typeid(refx).name(), &status) << "\n" << px << '\n';

    std::cout
    << "x: " << x
    << ", refx: " << refx
    << ", c_refx: " << c_refx << '\n';

    // assign refference with ranking pointer
    int& ref_from_ptr = *px;
    ref_from_ptr += 1;
    std:: cout
    << "ref_from_ptr: " << ref_from_ptr
    << ", *px: " << *px
    << ", x: " << x << '\n';
    // It works okay, but I'm not sure about side effects

    // TODO: Could we access to refference itself, not to variable its refferenced?

    return 0;

}

