class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<int>st;
        int n=nums.size();
        vector<int>result(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
            result[i]=(!st.empty()) ? st.top():-1; 
            st.push(i);
        }
        for(int i=0;i<n;i++){
            result[i]=(result[i]!=-1) ? result[i]-i:0;
        }
        return result;
    }
};