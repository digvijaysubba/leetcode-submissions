class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>output;
        deque<int>q;
        int l = 0;
        int r = 0;

        while( r < nums.size()){
            while ( !q.empty() && nums[q.back()] < nums[r]){
                q.pop_back();
            }
            q.push_back(r);

            if ( l > q.front()){
                q.pop_front();

            }

            if ( (r+1) >= k){
                output.push_back(nums[q[0]]);
                l++;
            }
            r++;

        }

        return output;
    }
};
