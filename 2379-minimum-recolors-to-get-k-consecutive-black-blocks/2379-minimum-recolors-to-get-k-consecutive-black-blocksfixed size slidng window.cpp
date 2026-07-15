class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left=0 , need=0 , min_color=INT_MAX;
        unordered_map<char,int>mp;
        for(int right=0;right<blocks.size();right++){
            mp[blocks[right]]+=1;
            while(right-left+1 > k){
                mp[blocks[left]]-=1;
                left+=1;
            }
            need=mp['W'];
            if(right-left+1 == k) min_color=min
            (min_color,need);
        }
        return min_color;
    }
};