class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>> um;
        for(string str:strs){
            string original=str;
            sort(str.begin(),str.end());
            um[str].push_back(original);
        }
        vector<vector<string>> result;
        for(const pair<string,vector<string>>& p:um){
            result.push_back(p.second);
        }
        return result;
    }
};