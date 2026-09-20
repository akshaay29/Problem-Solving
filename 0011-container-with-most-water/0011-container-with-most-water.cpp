class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int i=0 , j=height.size()-1 ,maxArea=INT_MIN;
        while(i<j){
            maxArea=max(maxArea,min(height[i],height[j]) * (j-i));
            if(height[i]<height[j]) i+=1;
            else j-=1;
        }
        return maxArea;
    }
};