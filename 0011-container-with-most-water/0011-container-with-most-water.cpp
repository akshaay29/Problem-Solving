class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1 , max_area=0;
        while(i<j){
            int w=j-i , h=min(height[i],height[j]);
            int area=w*h;
            max_area=max(area,max_area);
            if(height[i]<height[j]) i+=1;
            else j-=1;
        }
        return max_area;
    }
};