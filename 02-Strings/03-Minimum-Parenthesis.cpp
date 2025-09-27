
// Given a string pattern of only ( and ), find the minimum number of parentheses we must add to make it valid.

// A string is valid if every ( has a matching ).

// Examples:

// Valid: (()(())), ()()(), ((()))
// Invalid: (((, ((), )(())
// Return the minimum number of parentheses required to make a string valid.

/*

Ex.

Input: str = "())"
Output: 1
One '(' is required at beginning.

Input: str = "((("
Output: 3
Three ')' is required at end.

*/

// 1. Iterative Approach
// TC: O(N)
// SC: O(1)

#include <iostream>
#include <string>
using namespace std;

int minAddToMakeValid(string &pattern)
{
    int open = 0, add = 0;
    for (char c : pattern)
    {
        if (c == '(')
        {
            open++; // need a closing ')'
        }
        else
        {
            if (open > 0)
                open--; // match with '('
            else
                add++; // extra ')', need '('
        }
    }
    return add + open; // add for extra ')' + unmatched '('
}

int main()
{
    string pattern;
    cout << "Enter string: ";
    cin >> pattern;

    cout << "Minimum additions needed: " << minAddToMakeValid(pattern) << endl;
    return 0;
}

// 2.  Using Stack
// TC: O(N)
// SC: O(N) // in worst case stack is holding all the ( characters

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return required minimum number
int minParentheses(string p)
{
    stack<int> stk;
    int ans = 0;

    for (int i = 0; i < p.length(); ++i)
    {

        if (p[i] == '(')
        {
            stk.push(i);
        }
        else
        {
            if (!stk.empty())
            {
                stk.pop();
            }
            else
            {
                ans += 1;
            }
        }
    }

    // add remaining '(' characters to end
    ans += stk.size();

    return ans;
}

int main()
{
    string p = "())";

    cout << minParentheses(p);

    return 0;
}
