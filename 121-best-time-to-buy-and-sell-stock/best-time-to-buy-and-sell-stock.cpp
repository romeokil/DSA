class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int curprofit=0,maxprofit=0,curmin=prices[0];
        for(int i=1;i<n;i++){
            curprofit=prices[i]-curmin;
            maxprofit=max(curprofit,maxprofit);
            curmin=min(curmin,prices[i]);
        }
        return maxprofit;
    }
};