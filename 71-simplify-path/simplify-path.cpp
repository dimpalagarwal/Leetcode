class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> st;

        vector<string> strs;
        int i = 1;
        
        while(i<n){
            int start = i;
            while(i<n && path[i]!='/') i++;

            string s = path.substr(start, i-start);

            bool allSlash = true;
            for(int j=0; j<s.size(); j++) if(s[j]!='/') allSlash = false;

            if(!allSlash) strs.push_back(s);
            i++;
        }

        int m = strs.size();
        for(int j=0; j<m; j++){
            if(strs[j]==".."){
                if(!st.empty()) st.pop();
            }else if(strs[j]==".") continue;
            else st.push(strs[j]);
        }

        string res = "";
        vector<string> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        int t = ans.size();
        res.push_back('/');
        for(int j=t-1; j>=0; j--){
            res = res + ans[j];
            res.push_back('/');
        }

        if(res.size() > 1) res.pop_back();

        return res;
    }
};