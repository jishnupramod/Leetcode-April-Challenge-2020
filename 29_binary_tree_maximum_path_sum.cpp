/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int maxUtil(TreeNode* root, int &res) {
        if(root == NULL)
            return 0;
        int l = maxUtil(root->left, res);
        int r = maxUtil(root->right, res);
        
        int max_single = max(max(l, r)+root->val, root->val);
        int max_top = max(max_single, l+r+root->val);
        res = max(res, max_top);
        return max_single;
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxUtil(root, res);
        return res;
    }
};