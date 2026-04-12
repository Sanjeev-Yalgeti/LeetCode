#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numMap;
        int find;
        for(int i=0;i<nums.size();i++){
            find=target-nums[i];
            if(numMap.find(find)!=numMap.end()){
                return {numMap[find],i};
            }
            numMap[nums[i]]=i;
        }
        return {};
    }
};