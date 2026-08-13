class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        n=len(nums)
        i,j=0,0
        result=0
        um={}
        while j<n:
            um[nums[j]]=um.get(nums[j],0)+1
            while i<j and um[nums[j]]>k:
                um[nums[i]]-=1
                i+=1
            result=max(result,(j-i+1))
            j+=1
        return result