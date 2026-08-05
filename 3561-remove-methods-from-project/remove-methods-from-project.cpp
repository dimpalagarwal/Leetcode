class Solution {
public:
    void dfs(unordered_map<int, list<int>> &adjList, int node, vector<bool> &isSuspicious) {
        isSuspicious[node] = true;

        for(auto it : adjList[node]){
            if(!isSuspicious[it]){
                dfs(adjList, it, isSuspicious);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, list<int>> adjList;

        for (int i = 0; i < invocations.size(); i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];
            adjList[u].push_back(v);
        }

        vector<bool> isSuspicious(n, false);
        dfs(adjList, k, isSuspicious);

        bool canRemove = true;
        for(int i = 0; i < invocations.size(); i++){
            int u = invocations[i][0]; 
            int v = invocations[i][1]; 

            if(!isSuspicious[u] && isSuspicious[v]){
                canRemove = false;
                break;
            }
        }

        vector<int> result;
        for(int i = 0; i<n; i++){
            if(canRemove){
                if(!isSuspicious[i]){
                    result.push_back(i);
                }
            }else{
                result.push_back(i);
            }
        }

        return result;
    }
};
