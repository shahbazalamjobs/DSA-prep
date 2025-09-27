
// Tower of Hanoi (TOH):

// You have 3 pegs (rods) and n disks of different sizes.
// All disks start on the first peg, arranged from largest at bottom to smallest at top.
// Goal: Move all disks to the third peg.

// Rules:
// Only one disk can be moved at a time.
// You can only move the top disk of a peg.
// A larger disk cannot be placed on top of a smaller disk.

// Logic:
// To move n disks from peg A → peg C using peg B as helper:
// Move n-1 disks from A → B (using C as helper).
// Move the largest disk from A → C.
// Move n-1 disks from B → C (using A as helper).

// Minimum moves: 2^n−1

// 1.
// TC: O(2^n) // There are two possibilities for every disk. Therefore, 2 * 2 * 2 * . . . * 2(N times) is 2N
// SC: O(n)

#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    // Move n-1 disks from 'from' to 'aux'
    towerOfHanoi(n - 1, from, aux, to);

    // Move the nth disk from 'from' to 'to'
    cout << "Move disk " << n << " from " << from << " to " << to << endl;

    // Move n-1 disks from 'aux' to 'to'
    towerOfHanoi(n - 1, aux, to, from);
}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'C', 'B'); // A=source, C=destination, B=helper
    return 0;
}