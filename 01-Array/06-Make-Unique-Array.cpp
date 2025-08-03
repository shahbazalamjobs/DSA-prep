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
