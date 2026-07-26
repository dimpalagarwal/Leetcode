class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = sentence.size();
        int m = dictionary.size();
        
        unordered_map<string, int> mpp;
        for(int i=0; i<m; i++){
            mpp[dictionary[i]]++;
        }

        int j = 0;
        vector<string> res;

        string str = "";
        while(j<n){
            if(sentence[j]==' '){
                res.push_back(str);
                str = "";
                j++;
            }

            str.push_back(sentence[j]);
            if(mpp.find(str)!=mpp.end()){
                res.push_back(str);
                str = "";
                while(j<n && sentence[j]!=' '){
                    j++;
                }
            }
            j++;
        }

        if(!str.empty()) {
            res.push_back(str);
        }

        string ans = "";
        for(int i=0; i<res.size(); i++){
            string str = res[i];
            if(i!=res.size()-1){
                ans += str;
                ans.push_back(' ');
            }else{
                ans += str;
            }
        }

        return ans;
    }
};