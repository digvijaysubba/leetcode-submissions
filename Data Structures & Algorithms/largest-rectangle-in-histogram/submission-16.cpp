class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> stk;

        for ( int i = 0; i < heights.size(); i++){
            int h = heights[i];
            int start = i;

            while ( !stk.empty() && stk.top().second >h){
                int index = stk.top().first;
                int height = stk.top().second;
                stk.pop();
                maxArea = max( maxArea, height * ( i - index));
                start = index;
            }
            stk.push({start, h});
        }

        while (!stk.empty()){
            int index = stk.top().first;
            int height = stk.top().second;
            maxArea = max(maxArea, height *( static_cast<int>(heights.size()) - index));
            stk.pop();
        }
        
        return maxArea;
    }
};
