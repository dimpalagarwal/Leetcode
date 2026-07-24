class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(); 
        int wt = w; 
        int totalChose = 0; 
        
        map<int, vector<int>> mpp;
        for(int i=0; i<n; i++){ 
            mpp[capital[i]].push_back(profits[i]); 
        } 
        
        priority_queue<int> pq; 
        auto it = mpp.begin(); 
        
        while(totalChose != k){
            while(it != mpp.end() && it->first <= wt) {
                for(auto profit : it->second) {
                    pq.push(profit);
                }
                it++;
            }
            
            if(pq.empty()) {
                break; 
            }
            
            wt = wt + pq.top(); 
            pq.pop(); 
            totalChose += 1; 
        } 
        
        return wt;
    }
};