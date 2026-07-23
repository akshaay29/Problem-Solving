class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<int>st;
        st.push(-1);
        unordered_map<int,int>mp;
        int n=nums2.size() , n1=nums1.size();
        vector<int>res;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            mp[nums2[i]]=(!st.empty()) ? st.top():-1;
            st.push(nums2[i]); 
        }
        for(int i:nums1){
            res.push_back(mp[i]);
        }
        return res;
    }
};