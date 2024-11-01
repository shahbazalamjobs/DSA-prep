
// basics

#include <iostream>
#include <vector>

#include <algorithm> // sort

using namespace std;

int main() {    


    // declaring and initializing vector
    vector<int> vec1; // empty vector of int
    vector<int> vec2 = { 1, 5, 3, -2, 8 };   // vector with elements
    

    // adding elements to vector
    vec2.push_back(10); // add 10 to end of vector
    vec2.push_back(20);  // add 20 to end of vector

    // accesss element of vector
    cout<<vec2[0];  // acess 1st element
    cout<<vec2.at(1);  // acess 1st element
    cout<<vec2.front();  // first element    
    cout<<vec2.back();   // last element

    
    // removing element 
    vec2.pop_back(); // removes the last element
    vec2.clear();   // clears all elements, size becomes 0

    vec2.size();    //  returns the current number of elements.
    vec2.capacity();    // returns the amount of memory allocated, which might be larger than the size due to optimization.


    // Iterating Through a Vector
    // 1. for loop
    for(int i=0; i<vec2.size(); i++) {
        cout<<vec2[i] << " ";
    }

    // range based for loop
    for(int num: vec2) {
        cout<< num << " ";
    }


    // common operations

    // 1. sort(): Sorts the vector in ascending order.
    // 2. resize(): Changes the number of elements in the vector.
    // 3. empty(): Checks if the vector is empty.

    sort(vec2.begin(), vec2.end()); // Sorts in ascending order
    vec2.resize(10); // Resizes vector to hold 10 elements
    if (vec2.empty()) {
        cout << "Vector is empty";
    }

    return 0;
}
