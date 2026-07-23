class Solution {
public:
    void helperFunction(string s, int idx, int count, string str, vector<string> &strs){
        int n = s.size();

        if(idx>=n){
            if(count == 4){
                str.pop_back();
                strs.push_back(str);
            }
            return;
        }

        if(count==4) return ;

        for(int p=1; p<=3; p++){
            if(idx + p > n) break; 

            int newIdx = idx+p;
            string number = s.substr(idx, newIdx-idx);

            bool notLeadingZero = false;
            if(number.size() > 1 && number[0]=='0') notLeadingZero = true;

            int num = stoi(number);
            if(num >= 0 && num <= 255 && notLeadingZero==false){
                string altStr = str + number;
                altStr.push_back('.');
                helperFunction(s, idx+p, count+1, altStr, strs);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.size()< 4 || s.size() > 12) return {};

        vector<string> strs;

        helperFunction(s, 0, 0, "", strs);

        return strs;
    }
};