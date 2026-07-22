class Solution {
public:
    vector<int> bfs(unordered_map<int, list<int>> &adjList, int time, int change, int n){
        vector<int> minArray(n+1, INT_MAX);
        vector<int> secondMinArray(n+1, INT_MAX);
        minArray[1] = 0;

        queue<pair<int, int>> q;
        q.push({0,1});
        while(!q.empty()){
            int node = q.front().second;
            int curr_time = q.front().first;
            q.pop();

            int time_to_add = curr_time;
            if(curr_time/change % 2 == 1){
                time_to_add = change*(curr_time/change) + change;
            }

            int next_time = time_to_add + time;

            for(auto it: adjList[node]){
                if(next_time < minArray[it]){
                    secondMinArray[it] = minArray[it];
                    minArray[it] = next_time;
                    q.push({next_time, it});
                }else if(next_time > minArray[it] && next_time < secondMinArray[it]){
                    secondMinArray[it] = next_time;
                    q.push({next_time, it});
                }
            }
        }

        return secondMinArray;
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, list<int>> adjList;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> secondMinArray = bfs(adjList, time, change, n);

        return secondMinArray[n];
    }
};