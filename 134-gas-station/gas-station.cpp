class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        // if(n==1 && gas[0]==2 && cost[0]==2) return 0;

        // int start = -1;
        // for(int i=0; i<n; i++){
        //     if(gas[i] > cost[i]){
        //         bool check = true;
        //         int point = gas[i]-cost[i];
        //         int j = (i+1)%n;
        //         while(j!=i){
        //             point = point + gas[j] - cost[j];
        //             if(point<0){
        //                 check = false;
        //                 break;
        //             }
        //             j = (j+1)%n;
        //         }

        //         if(check == true){
        //             start = i;
        //             break;
        //         }
        //     }
        // }

        // return start;

        int totalGas = 0;
        int totalCost = 0;
        int currGas = 0;
        int start = 0;

        for(int i=0; i<n; i++){
            totalGas += gas[i];
            totalCost += cost[i];

            currGas += gas[i]-cost[i];
            if(currGas < 0){
                start = i+1;
                currGas = 0;
            }
        }

        return (totalGas < totalCost) ? -1 : start;
    }
};