class Solution {
public:
    int calcArea(int left,int right,int hl,int hr)
    {
        int b=right-left;
        int h;
        if(hl>=hr)h=hr;
        else h=hl;
        return b*h;
    }
    int maxArea(vector<int>& height) {
        int maxVal,area,left;
        maxVal=area=left=0;
        int right=height.size()-1;
        while(left<right)
        {
            area=calcArea(left,right,height[left],height[right]);
            if (area>maxVal) maxVal=area;
            if(height[left]>=height[right])
            {
                right--;
            }
            else left++;          
        };
        return maxVal;
    }
};