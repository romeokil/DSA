class Solution {
public:
    int solve(int n,int target,vector<int>& nums,unordered_map<string,int> &um){
        if(n==0){
            if(target==0) return 1;
            else return 0;
        }
        string key=to_string(n)+"_"+to_string(target);
        if(um.find(key)!=um.end()) return um[key];
        // ek baar +1 krege
        int plus_case=solve(n-1,target-nums[n-1],nums,um);
        int minus_case=solve(n-1,target+nums[n-1],nums,um);
        return um[key]=plus_case+minus_case;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<string,int> um;
        return solve(n,target,nums,um);
    }
};