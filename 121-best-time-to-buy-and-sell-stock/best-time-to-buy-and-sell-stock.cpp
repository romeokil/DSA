class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprofit=INT_MIN;
        int curmin=prices[0];
        for(int i=0;i<n;i++){
            int curprofit=prices[i]-curmin;
            maxprofit=max(maxprofit,curprofit);
            curmin=min(curmin,prices[i]);
        }
        return maxprofit;
    }
};