class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair< int, int>> fleet;

        for ( int i = 0 ; i < position.size(); i ++){
            fleet.push_back({position[i], speed[i]});
        }
        sort(fleet.rbegin(), fleet.rend());

        vector<double>stk;

        for ( auto & p : fleet){
            stk.push_back((double)(target - p.first)/p.second);
            if ( stk.size() >= 2 && stk.back() <= stk[stk.size()-2]){
                stk.pop_back();
            }
        }
        return stk.size();
    }   
};
