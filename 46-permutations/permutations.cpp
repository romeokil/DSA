class Solution {
public:
    void solve(vector<int> temp,vector<vector<int>> &result,vector<int> nums,vector<bool> visited){
        if(temp.size()==nums.size()){
            result.push_back(temp);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
                visited[i]=true;
                temp.push_back(nums[i]);
                solve(temp,result,nums,visited);
                visited[i]=false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        vector<bool> visited(n,false);
        vector<vector<int>> result;
        solve(temp,result,nums,visited);
        return result;
    }
};