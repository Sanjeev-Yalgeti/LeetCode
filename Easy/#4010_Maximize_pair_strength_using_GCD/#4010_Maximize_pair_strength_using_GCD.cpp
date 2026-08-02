#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int max=0;
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)//Outer loop
        {
            for(int j=i+1;j<n;j++)//Inner Loop
            {
                long long g=gcd(nums[i],nums[j]);
                long long result=(nums[i]/g)*(nums[j]/g);
                if(result>ans)
                {
                    ans=result;
                }
            }
        }
        return ans ;
    }
};