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
public:
    bool hasPathSum(TreeNode* root, int sum) {
        //O(n) time traversing each node once, O(1) space not storing anything
        if (root == nullptr){
            return false;
        }
        if (root->left == nullptr && root->right == nullptr){
            sum -= root->val;
            return sum == 0;
        }
        int new_sum = sum - root->val;
        return hasPathSum(root->left, new_sum) || hasPathSum(root->right, new_sum);
    }
};