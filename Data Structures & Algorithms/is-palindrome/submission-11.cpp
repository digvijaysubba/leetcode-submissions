class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        

        while (l<r){
            while ( l < r && !charCheck(s[l])){
                l += 1;
            }

            while ( l < r && !charCheck(s[r])){
                r -= 1;
            }

            if ( tolower(s[l]) != tolower(s[r])){
                return false;
            }
            else {
                r--;
                l++;
            }
        }
        return true;

    }

    bool charCheck(char c){
        return ( c >= 'A' && c<= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <='9');
    }
};
