#include <iostream>
#include <string>

using namespace std;

int main()
{
    string arr[3] = {"abc", "def", "ghi"};
    for(string& str : arr)
        cout << str << endl; 
    return 0;
}