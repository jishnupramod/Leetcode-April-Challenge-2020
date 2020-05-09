/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stk1, stk2;
        for(char ch : S) {
            if(ch != '#')
                stk1.push(ch);
            else if(!stk1.empty())
                stk1.pop();
        }
        for(char ch : T) {
            if(ch != '#')
                stk2.push(ch);
            else if(!stk2.empty())
                stk2.pop();
        }
        if(stk1 == stk2)
            return true;
        else
            return false;
    }
};

// Solution is not space optimised !
