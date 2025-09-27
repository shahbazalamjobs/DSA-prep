
// kth-ancestor-node-binary-tree

// In Aakash’s family tree, every male (M) has children in the order M → F,
// and every female (F) has children in the order F → M. Given the generation
// number N and a position K, find the Kth child in the Nth generation.

/*

Generation Recap

Gen 1: M
Gen 2: M F
Gen 3: M F F M
Gen 4: M F F M F M M F
Gen 5: expand again → M F F M F M M F F M M F M F F M

Examples

N = 2, K = 2
Gen 2 = M F
2nd child = F

N = 3, K = 1
Gen 3 = M F F M
1st child = M

N = 3, K = 3
Gen 3 = M F F M
3rd child = F

*/

// 1. Recursive
// TC = O(N)
// SC = O(N)

/*

Logic:

if (N == 1) return 'M'; // Base Case
long long parentPos = (K + 1) / 2;


*/

#include <bits/stdc++.h>
using namespace std;

char findChild(int N, long long K)
{
    // Base case: 1st generation is always 'M'
    if (N == 1)
        return 'M';

    // Find parent's position in (N-1)th generation
    long long parentPos = (K + 1) / 2;
    char parent = findChild(N - 1, parentPos);

    // If parent is 'M'
    if (parent == 'M')
    {
        return (K % 2 == 1) ? 'M' : 'F';
    }
    // If parent is 'F'
    else
    {
        return (K % 2 == 1) ? 'F' : 'M';
    }
}

int main()
{
    int N;
    long long K;
    cin >> N >> K;

    cout << findChild(N, K) << endl;
    return 0;
}

// 2. Iterative
// TC = O(N)
// SC = O(1)

/*

logic: 
Odd K (1st child) → same gender as “first child” rule.
Even K (2nd child) → flips gender compared to odd.

So every time K is even, gender flips.
*/

#include <bits/stdc++.h>
using namespace std;

char findChild(int N, long long K)
{
    char ans = 'M'; // root is always M

    while (N > 1)
    {
        if (K % 2 == 0)
        {
            // even child => flip gender
            ans = (ans == 'M') ? 'F' : 'M';
        }
        // move to parent
        K = (K + 1) / 2;
        N--;
    }

    return ans;
}

int main()
{
    int N;
    long long K;
    cin >> N >> K;

    cout << findChild(N, K) << endl;
    return 0;
}
