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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return NULL;

        int value = 0;
        TreeNode* temp1 = root1;
        TreeNode* temp2 = root2;

        if(root1) value+=temp1->val;
        if(root2) value+=temp2->val;

        TreeNode *node = new TreeNode(value);
        node->left = mergeTrees(temp1==NULL?NULL:temp1->left, temp2==NULL?NULL:temp2->left);
        node->right = mergeTrees(temp1==NULL?NULL:temp1->right, temp2==NULL?NULL:temp2->right);

        return node;
    }
};