class Solution {
public:
    static bool comp(const int &x,const int &y){
        int a=x,b=y,sum1=0,sum2=0;
        while(a>0){
            sum1+=a%10;
            a=a/10;
        }
        while(b>0){
            sum2+=b%10;
            b=b/10;
        }
        if(sum1!=sum2) return sum1<sum2;
        if(x==min(x,y)) return true;
        return false;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size(),m=0;
        vector<int>nums2=nums;
        vector<bool>visited(n+1,false);
        sort(nums2.begin(),nums2.end(),comp);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[nums2[i]]=i;
        for(int i=0;i<n;i++){
            int curr=i;
            if(visited[curr]==true) continue;
            while(!visited[curr]){
                visited[curr]=true;
                curr=mp[nums[curr]];
            }
            m+=1;
        }
        return n-m;
    }
};
