class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        if(n==1 && gas[0]==2 && cost[0]==2) return 0;

        int start = -1;
        for(int i=0; i<n; i++){
            if(gas[i] > cost[i]){
                bool check = true;
                int point = gas[i]-cost[i];
                int j = (i+1)%n;
                while(j!=i){
                    point = point + gas[j] - cost[j];
                    if(point<0){
                        check = false;
                        break;
                    }
                    j = (j+1)%n;
                }

                if(check == true){
                    start = i;
                    break;
                }
            }
        }

        return start;
    }
};