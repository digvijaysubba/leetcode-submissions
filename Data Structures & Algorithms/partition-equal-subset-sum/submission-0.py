class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums) % 2:
            return False
        

        dp = set()
        target = sum(nums)//2
        dp.add(0)


        for i in range(len(nums)-1,-1,-1):
            dpnext = set()
            for t in dp:
                if (t + nums[i])== target:
                    return True
                dpnext.add(t+nums[i])
                dpnext.add(t)
            dp = dpnext
        return False
