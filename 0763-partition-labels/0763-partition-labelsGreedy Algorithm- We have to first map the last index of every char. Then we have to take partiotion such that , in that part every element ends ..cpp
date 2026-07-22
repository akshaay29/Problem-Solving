class Solution {
public:
    vector<int> partitionLabels(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int>last(26,0);
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
        }
        int max_end=-1 , start=0;
        vector<int>res;
        for(int i=0;i<s.size();i++){
            max_end=max(max_end,last[s[i]-'a']);
            if(i==max_end){
                res.push_back(i-start+1);
                start=i+1;
            }
        }
        return res;
    }
};