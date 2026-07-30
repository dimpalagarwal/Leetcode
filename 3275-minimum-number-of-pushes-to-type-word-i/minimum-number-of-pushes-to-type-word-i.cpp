class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        int sum = 0;

        for(int i=0; i<n; i++){
            int div = i/8;
            sum = sum + div + 1;
        }

        return sum;
    }
};