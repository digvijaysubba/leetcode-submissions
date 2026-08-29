class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        res = defaultdict(list)

        for s in strs: #cat
            count = [0] * 26
            for c in s:  #c 
                count[ord(c)-ord('a')] +=1 
                #c gets converted to number and that number is used as index for count list
                #then +1 is added to that index(number obratined by converting c)
            res[tuple(count)].append(s)
        return list(res.values())

        