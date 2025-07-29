
#include <iostream>
#include <climits>
using namespace std;

int findSecondLargest(int arr[], int n)
{

    if (n < 2)
    {
        cout << "Array must have atleast 2 elements." << endl;
        return -1;
    }

    int first = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] != first)
        {
            second = arr[i];
        }
    }

    if (second == INT_MIN)
    {
        return -1;
    }

    return second;
}

int main()
{

    int arr[] = {2, 5, 30, 7, 60, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    int second = findSecondLargest(arr, n);
    if (second != -1)
    {
        cout << "Second largest element is, " << second << endl;
    }
    else
    {
        cout << "Second Largest element not found";
    }

    return 0;
}
