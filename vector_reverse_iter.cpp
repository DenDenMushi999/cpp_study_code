#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {1,2,3,4,5};
    for (vector<int>::const_reverse_iterator iter = vec.rbegin(); iter != vec.rend(); ++iter)
        cout << *iter << " ";
    cout << endl;
    return 0;
}