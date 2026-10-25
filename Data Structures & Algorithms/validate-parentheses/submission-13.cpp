class Solution {
public:
    bool isValid(string s) {
        vector<char> stackA;
        unordered_map<char, char> characters ={
            { ')','('},
            {'}','{'},
            {']','['}
        };


        for ( char c : s){
            if ( characters.count(c)){
                if (!stackA.empty() && stackA.back()== characters[c]){
                    stackA.pop_back();
                }

                else {
                    return false;
                }
            }
            else {
            stackA.push_back(c);
            }
        }

        return stackA.empty();


    }
};
