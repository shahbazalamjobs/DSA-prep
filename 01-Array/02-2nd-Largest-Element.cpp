
// 02 - 2nd  largest and 2nd smallest element in an array

// Input: [1,2,4,7,7,5]

// Output:

// Second Smallest : 2
// Second Largest : 5

#include<iostream>
#include <climits>

using namespace std;

int max2_element(int arr[], int len) {

    // int len = sizeof(arr) / sizeof(arr[0]);
    // can do above bcoz when arr is passed to function now it act like pointer and size of pointer will return size of pointer not size of array. 

    // int max1 = arr[0];
    // int max2 = arr[0];
    // can initialise with 1st element bcoz if all elements are same then it will give err

    int max1 = INT_MIN;
    int max2 = INT_MIN;

    for (int i = 0; i < len; i++) {
        if (max1 < arr[i]){
            max2 = max1;
            max1 = arr[i];        
        } else if (max2 < arr[i] && arr[i] < max1) {
            max2 = arr[i];
        }
    }

    // to check edge case to check whether there is valid 2nd largest element (all elements are same)
    if (max2 == INT_MIN) {
        cout << "There is no 2nd largest element." << endl;
        return -1;
    }
    
    return max2;
}

int least2_element(int arr[], int len) {
    int least1 = INT_MAX;
    int least2 = INT_MAX;

    for (int i = 0; i < len; i++) {
        if(least1 > arr[i]) {
            least2 = least1;
            least1 = arr[i];
        } else if (least2 > arr[i] && arr[i] > least1) {
            least2 = arr[i];
        }
    }

    if (least2 == INT_MAX) {
        cout << "There is not 2nd least no.";
        return -1;
    }

    return least2;
}

int main() {

    int arr[] =  { 1, 2, 4, 7, 7, 5 };
    int len = sizeof(arr) / sizeof(arr[0]);

    int max2_elem = max2_element(arr, len);

    int least2_elem = least2_element(arr, len);

    cout << "2nd Largest Element: " << max2_elem << endl;
    cout << "2nd Smallest Element: " << least2_elem << endl;

    return 0;
}
