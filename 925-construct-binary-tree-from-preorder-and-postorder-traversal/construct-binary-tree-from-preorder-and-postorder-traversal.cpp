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
    TreeNode* helperFunction(int prestart, int postStart, int preend, vector<int>& preorder, vector<int>& postorder){
        if(prestart > preend) return NULL;

        TreeNode *root = new TreeNode(preorder[prestart]);
        if(prestart == preend) return root;
        int nextNode = preorder[prestart+1];

        int j = postStart;
        while(postorder[j]!= nextNode) j++;

        int num = j-postStart+1;
        root->left = helperFunction(prestart+1, postStart, prestart+num, preorder, postorder);
        root->right = helperFunction(prestart+num+1, j+1, preend, preorder, postorder);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();

        return helperFunction(0, 0, n-1, preorder, postorder);
    }
};