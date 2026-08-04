class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        n=len(nums)
        maxi=float("-inf")
        mini=float("inf")
        v=[]
        st=set()
        for i in range(n):
            maxi=max(maxi,nums[i])
            mini=min(mini,nums[i])
            st.add(nums[i])
        for i in range(mini,maxi):
            if i not in st:
                v.append(i)
        return v
            