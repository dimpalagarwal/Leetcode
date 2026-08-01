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
    int helperFunction(TreeNode *root, bool flag, map<pair<TreeNode*, bool>,int> &dp){
        if(root==NULL) return 0;
        
        if(dp.find({root, flag})!=dp.end()) return dp[{root, flag}]; 
        
        int take = 0;
        if(flag==true){
            take = root->val + helperFunction(root->left, false, dp) + helperFunction(root->right, false, dp);
        }
        
        int skip = helperFunction(root->left, true, dp) + helperFunction(root->right, true, dp);
        
        return dp[{root, flag}] = max(take, skip);
    }

    int rob(TreeNode* root) {
        map<pair<TreeNode*, bool>,int> dp;
        
        return helperFunction(root, true, dp);
    }
};