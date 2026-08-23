class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftKnownSum = 0;
        int rightKnownSum = 0;
        int leftQs = 0;
        int rightQs = 0;

        int half = n/2;
        for(int i=0; i<half; i++){
            if(num[i]!='?') leftKnownSum = leftKnownSum + num[i]-'0';
            else leftQs++;
        }

        for(int i=half; i<n; i++){
            if(num[i]!='?') rightKnownSum = rightKnownSum + num[i]-'0';
            else rightQs++;
        }

        if(((leftQs + rightQs) % 2) != 0) return true;

        return (leftKnownSum + (4.5)*leftQs)!=(rightKnownSum + (4.5)*rightQs);
    }
};