class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = max(nums)
        maxnum,minnum = 1,1

        for n in nums:
            if n == 0:
                maxnum,minnum = 1,1
                continue
            
            tmp = maxnum * n
            maxnum = max(maxnum * n, minnum * n, n)
            minnum = min(tmp, minnum * n, n)
            res = max(res, maxnum)
        return res
        