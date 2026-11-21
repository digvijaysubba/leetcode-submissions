class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      if (s1.size() > s2.size()){
        return false;
      }

      vector<int>counts1(26,0);
      vector<int>counts2(26,0);

      int  matches = 0;

      for (int i =0; i < s1.size(); i ++){
        counts1[s1[i] - 'a'] ++;
        counts2[s2[i] - 'a'] ++;
      }

      for ( int r = 0 ; r < 26 ; r++){
        if ( counts1[r] == counts2[r]){
            matches ++;
        }
        else{
            matches += 0;
        }
      }

      int l = 0;

      for ( int r = s1.size(); r < s2.size(); r ++){
        if (matches == 26){
            return true;
        }

        int index = s2[r] - 'a';
        counts2[index] += 1;

        if ( counts1[index] == counts2[index]){
            matches ++;
        }
        else if ( counts1[index] + 1 == counts2[index]){
            matches --;
        }

        index = s2[l] - 'a';
        counts2[index] -= 1;

        if (counts1[index] == counts2[index]){
            matches ++;
        }

        else if ( counts1[index]-1 == counts2[index]){
            matches --;
        }

        l ++;
      }

      return (matches == 26) ?true:false ;  
    }
};
