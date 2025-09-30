
// You are given an array of integers. You need to make all the elements in the array unique.
// In one operation, you can remove an element from the array.
// Your task is to find the minimum number of elements you must remove so that all elements in the array become unique.

/*

Test case 1:
Array = [1, 2, 2, 3, 3, 3]

The duplicates are: two extra 2s and two extra 3s.

Remove 2 of the 3s and 1 of the 2s → 3 removals in total.
Final array could be [1, 2, 3].

Test case 2:
Array = [4, 5, 6, 7, 8]

All elements are already unique.

No removals needed → 0.

*/

// 1. 
// TC = O(n)
// SC = O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int minRemovalsToMakeUnique(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int num : arr)
        freq[num]++;
    
    int removals = 0;
    for (auto& entry : freq) {
        if (entry.second > 1)
            removals += entry.second - 1;
    }

    return removals;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; ++i)
            cin >> arr[i];

        cout << minRemovalsToMakeUnique(arr) << endl;
    }

    return 0;
}



