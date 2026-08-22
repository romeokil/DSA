class Solution:
    def checkDivisibility(self, n: int) -> bool:
        originalNo=n
        sum=0
        prod=1
        while n!=0:
            rem=n%10
            sum+=rem
            prod*=rem
            n//=10
        print(sum+prod)
        return True if originalNo%(sum+prod)==0 else False