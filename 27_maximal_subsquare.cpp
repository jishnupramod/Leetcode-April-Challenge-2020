/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = rows > 0 ? matrix[0].size() : 0;
        int ans[rows+1][cols+1];
        int height = 0;
        for(int i=0; i<rows+1; ++i) {
            for(int j=0; j<cols+1; ++j) 
                ans[i][j] = 0;
        }
        for(int i=1; i<rows+1; ++i) {
            for(int j=1; j<cols+1; ++j) {
                if(matrix[i-1][j-1] == '1') {
                    ans[i][j] = 1 + min({ans[i-1][j], ans[i][j-1], ans[i-1][j-1]});
                    height = max(height, ans[i][j]);
                }
            }
        }
        return height*height;
    }
};