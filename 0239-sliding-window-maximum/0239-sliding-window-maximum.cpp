class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        deque<int>q;
        vector<int>res;
        for(int r=0;r<(int)nums.size();r++){
            if(!q.empty() && q.front()<=r-k) q.pop_front();
            while(!q.empty() && nums[q.back()]<nums[r]) q.pop_back();
            q.push_back(r);
            if(r>=k-1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};