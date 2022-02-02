//Approach 1

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mn=1e5, mx=-1,profit=0;
        for(int i=0;i<n;i++){
            if(i==0){
                mn=min(mn,prices[i]);continue;
            }
            if(prices[i]<=prices[i-1]){
                mx=-1;
                mn = min(mn,prices[i]);
            }
            else{
                mx = max(mx,prices[i]);
                profit = max(profit,mx-mn);
            }
        }
        return profit;
    }
};
