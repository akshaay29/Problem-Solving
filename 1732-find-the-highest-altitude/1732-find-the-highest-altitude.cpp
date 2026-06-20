class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=INT_MIN , sum=0;
        for(int val:gain){
            sum+=val;
            maxi=max(maxi,sum);
        }
        return (maxi<0 ? 0:maxi);
    }
};  