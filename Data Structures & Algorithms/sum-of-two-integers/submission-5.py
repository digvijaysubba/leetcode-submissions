class Solution:
    def getSum(self, a: int, b: int) -> int:
        MASK = 0xFFFFFFFF
        MAX = 0x7FFFFFFF

        while b!=0:
            tmp = (a & b) << 1
            a = a ^ b
            b = tmp
            a = a & MASK
            b = b & MASK
        return a if a <= MAX else ~(a ^ MASK)