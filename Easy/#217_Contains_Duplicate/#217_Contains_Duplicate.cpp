#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        
       unordered_set<int> ele;
    
       for (int i = 0; i < nums.size(); i++) 
    {
        if (ele.find(nums[i]) != ele.end()) 
        {
            return true; 
        }
        else 
        {
            ele.insert(nums[i]);
        }
    }
return false;
    }
    };

    
