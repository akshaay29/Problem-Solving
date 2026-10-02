class Solution {
public:
    bool isValid(int mid,string s,string p,vector<int>&removable){
        for(int i=0;i<=mid;i++) s[removable[i]]='*';
        int i=0,j=0;
        while(i<s.size() && j<p.size()){
            if(s[i]==p[j]) j+=1;
            i+=1;
        }
        return (j==p.size() ? true:false);
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l=0,r=removable.size()-1 ,ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(mid,s,p,removable)){
                ans=mid;
                l=mid+1;
            } 
            else r=mid-1;
        }
        return ans+1;
    }
};