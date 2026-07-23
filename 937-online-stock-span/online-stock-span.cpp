class StockSpanner {
public:
    int idx = 1;
    stack<pair<int, int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }

        int ans = idx;
        if(!st.empty()){
            ans = idx-st.top().second;
        }

        st.push({price, idx});
        idx++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */