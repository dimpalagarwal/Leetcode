class Solution {
public:
    unordered_map<int, string> mpp = {
        {0, "Zero"},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"},
        {100, "One Hundred"}
    };

    string findAns(string str){
        reverse(str.begin(), str.end());

        int num = stoi(str);

        if(num==0) return "";
        if(mpp.find(num)!=mpp.end()) return mpp[num];

        string res = "";

        if(str.size()==3){
            if(str[0]!='0') res += mpp[str[0]-'0'] + " Hundred";

            int rem = stoi(str.substr(1));
            if(rem>0){
                if(!res.empty()) res += " ";

                if(mpp.find(rem)!=mpp.end()) res += mpp[rem];
                else{
                    res += mpp[(str[1]-'0')*10];
                    if(str[2] != '0') res += " " + mpp[str[2]-'0'];
                }
            }
        }else if(str.size()==2){
            res += mpp[(str[0]-'0')*10];
            if(str[1] != '0') res += " " + mpp[str[1]-'0'];
        }else if(str.size()==1){
            return mpp[str[0]-'0'];
        }

        return res;
    }

    string numberToWords(int num) {
        if(num==0) return "Zero";
        string number = to_string(num);

        int n = number.size();

        string ans = "";

        int pos = 0;
        for(int i=n-1; i>=0; i-=3){
            string str = "";
            for(int idx=i; idx>i-3; idx--){
                if(idx >= 0){
                    str.push_back(number[idx]);
                }
            }
            string tempAns = findAns(str);

            if(!tempAns.empty()){
                if(pos==0){
                    ans = tempAns + (ans.empty() ?"":" " + ans);
                }else if(pos==1){
                    ans = tempAns + " " + "Thousand" + (ans.empty()? "":" " + ans);
                }else if(pos==2){
                    ans = tempAns + " " + "Million" + (ans.empty() ? "" : " " + ans);
                }else if(pos==3){
                    ans = tempAns + " " + "Billion" + (ans.empty()? "":" " + ans);
                }
            }

            pos++;
        }

        return ans;
    }
};