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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //Solution: O(n) time traversing each node once. O(n) space storing all nodes of tree
        vector<vector<int>> result;
        if (root == nullptr){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> v;
            int n_level = q.size();
            for (int i = 0; i < n_level; i++){
                TreeNode *front = q.front();
                v.push_back(front->val);
                if (front->left != nullptr){
                    q.push(front->left);
                }
                if (front->right != nullptr){
                    q.push(front->right);
                }
                q.pop();
            }
            result.push_back(v);
        }
        reverse(result.begin(), result.end()); //to reverse
        return result;
    }
};