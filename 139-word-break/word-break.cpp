class Solution {
public:
    int helperFunction(string s, unordered_set<string> &Dict, int start, vector<int> &dp){
        if(start==s.size()) return 1;

        if(dp[start]!=-1) return dp[start];

        for(int i=start; i<s.size(); i++){
            string str = s.substr(start, i-start+1);

            if(Dict.find(str)!=Dict.end()){
                if(helperFunction(s, Dict, i+1, dp)==true) return dp[start] = 1;
            }
        }

        return dp[start] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> Dict;
        for(int i=0; i<wordDict.size(); i++){
            Dict.insert(wordDict[i]);
        }

        vector<int> dp(s.size(), -1);

        return helperFunction(s, Dict, 0, dp);
    }
};