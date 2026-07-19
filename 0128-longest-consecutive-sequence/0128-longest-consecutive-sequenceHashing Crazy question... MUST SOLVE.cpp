class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_set<int>st(nums.begin(),nums.end());
        int max_len=0;
        for(int i:st){
            if(st.find(i-1)==st.end()){
                int curr_num=i , cnt=1;
                while(st.find(curr_num+1)!=st.end()){                   
                    curr_num+=1;
                    cnt+=1;
                }
                max_len=max(cnt,max_len);
            }
        }
        return max_len;
    }
};