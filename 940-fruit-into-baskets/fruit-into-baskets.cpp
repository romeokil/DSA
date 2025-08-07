class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0,j=0;
        int result=0;
        unordered_map<int,int> um;
        while(j<n){
            um[fruits[j]]++;
            while(i<j && um.size()>2){
                um[fruits[i]]--;
                if(um[fruits[i]]==0) um.erase(fruits[i]);
                i++;
            }
            if(um.size()<=2){
                result=max(result,(j-i+1));
            }
            j++;
        }
        return result;
    }
};