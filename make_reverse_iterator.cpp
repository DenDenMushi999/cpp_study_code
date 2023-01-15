#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> vec = {1,2,3,4,5,6,7,8};
    vector<int>::const_iterator iter = vec.begin()+2;
    vector<int>::const_reverse_iterator iter_r = make_reverse_iterator(iter);
    cout << "*iter = " << *iter << ", *iter_r = " << *iter_r << ", *(iter_r-1) = " << *(iter_r-1) << endl;
}