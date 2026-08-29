class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        numsSet = set(nums)
        Longest = 0

        for nums in numsSet:
            if (nums-1) not in numsSet:
                length = 1
                while (nums + length) in numsSet:
                    length +=1
                Longest = max(Longest, length)

        return Longest