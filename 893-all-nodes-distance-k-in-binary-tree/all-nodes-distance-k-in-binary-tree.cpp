/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void prepareList(TreeNode* root, unordered_map<int, list<int>> &adjList, int &nodeCount){
        if(root==NULL) return;

        int u = root->val;
        nodeCount++;
        int v1 = -1;
        if(root->left!=NULL) v1 = root->left->val;
        int v2 = -1;
        if(root->right!=NULL) v2 = root->right->val;

        if(v1!=-1){
            adjList[u].push_back(v1);
            adjList[v1].push_back(u);
        }

        if(v2!=-1){
            adjList[u].push_back(v2);
            adjList[v2].push_back(u);
        }

        prepareList(root->left, adjList, nodeCount);
        prepareList(root->right, adjList, nodeCount);
    }

    unordered_map<int, int> bfs(unordered_map<int, list<int>> &adjList, int start, int &nodes){
        unordered_map<int, int> distance;

        unordered_map<int, bool> visited;
        queue<int> q;
        q.push(start);
        visited[start] = true;
        distance[start] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it: adjList[node]){
                if(!visited[it]){
                    distance[it] = distance[node]+1;
                    q.push(it);
                    visited[it] = true;
                }
            }
        }

        return distance;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k == 0) return {target->val};

        unordered_map<int, list<int>> adjList;
        int nodes = 0;
        prepareList(root, adjList, nodes);
        int start = target->val;

        unordered_map<int, int> distance = bfs(adjList, start, nodes);

        vector<int> ans;
        for(auto it: distance){
            if(it.second==k) ans.push_back(it.first);
        }

        return ans;
    }
};