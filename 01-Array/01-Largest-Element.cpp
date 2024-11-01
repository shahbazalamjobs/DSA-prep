
// 01- Largest Element in array

// Example 1:
// Input:
//  arr[] = {2,5,1,3,0};
// Output:
//  5

// 1. using loop -> t.c: O(n) s.c: O(1)

#include <iostream>
using namespace std;

int maxElement(int arr[], int length) {
        int max = arr[0];

    for(int i=1; i<length; i++) {
        if(max<arr[i]) {
            max = arr[i];
        }
    }

    return max;
}

int main() {

    int arr[] =  {2,5,1,3,0};
    int length = sizeof(arr) / sizeof(arr[0]);

    int maxElem = maxElement(arr, length);

    cout<<maxElem;
    return 0;
}



// 2. using sorting -> O(nlogn), s.c: o(logn)


#include <iostream>
#include <vector>
#include <algorithm> // for sort func

using namespace std;

int maxElement(vector<int>& arr) {
    sort(arr.begin(), arr.end());   // sort take nlogn t.c. and logn s.c
    return arr[arr.size() - 1];
}

int main() {

    vector<int> arr = {2,5,1,3,0};

    int maxElem = maxElement(arr);
    cout<<maxElem;
    return 0;
}
