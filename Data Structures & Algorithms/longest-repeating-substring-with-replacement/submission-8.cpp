class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int maxf = 0;
        int l = 0;
        unordered_map<char , int>count;

        for ( int r = 0; r < s.size(); r++){
            count[s[r]] = 1 + count[s[r]];
            maxf = max(maxf, count[s[r]]);


            while ((r-l+1) - maxf > k){
                count[s[l]] --;
                l ++;
            }

            res = max(res, r-l+1);
        }

        return res;

        
    }
};
