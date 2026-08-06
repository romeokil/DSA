class Solution:
    def finddigitProduct(self,no):
        prod=1
        while no!=0:
            rem=no%10
            prod=prod*rem
            no//=10
        return prod

    def smallestNumber(self, n: int, t: int) -> int:
        for i in range(n,101):
            digitProduct=self.finddigitProduct(i)
            print(digitProduct)
            if digitProduct%t==0:
                return i
        return -1
        