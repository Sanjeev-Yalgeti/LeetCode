#217. Contains Duplicate

Problem Statement

Given an integer array "nums", return "true" if any value appears at least twice in the array, and return "false" if every element is distinct.

---

Logic

The idea is to keep track of every element that has already been seen.

1. Create an unordered set.
2. Traverse the array from left to right.
3. For each element:
   - Check if it already exists in the set.
   - If it does, return "true" because a duplicate has been found.
   - Otherwise, insert the element into the set.
4. If the entire array is traversed without finding any duplicate, return "false".

Since an "unordered_set" provides an average O(1) lookup and insertion time, the overall solution runs in linear time.

---

C++ Code

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

    


---

Time Complexity

- O(n)

Each element is processed exactly once, and every lookup and insertion into the "unordered_set" takes O(1) on average.

---

Space Complexity

- O(n)

In the worst case, all elements are distinct, so every element is stored in the "unordered_set".

---

Performance

Runtime:

75ms (beats 22.6%)
Memory:

111.2Mb (beats 14.7%)
---

Proof

