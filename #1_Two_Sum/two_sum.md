# Two Sum (LeetCode 1)

## 🧾 Problem Statement

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to the target.

Each input has exactly one solution, and you may not use the same element twice.

---

## 💡 Approach

* Use a hashmap to store values and their indices.
* Iterate through the array:

  * For each element, calculate `target - nums[i]`.
  * Check if this value already exists in the hashmap.
  * If it exists, return the stored index and current index.
  * Otherwise, store the current value with its index.

This avoids checking all pairs and reduces time complexity significantly.

---

## ⚙️ Code

```cpp
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            int find = target - nums[i];
            if (numMap.find(find) != numMap.end()) {
                return {numMap[find], i};
            }

            numMap[nums[i]] = i;
        }
        return {};
    }
};
```

---

## ⏱️ Time Complexity

* **O(n)**
  Each element is processed once, and hashmap lookup is constant time on average.

---

## 🧠 Space Complexity

* **O(n)**
  Extra space is used to store elements in the hashmap.

---

## 📊 Key Insight

Instead of checking every pair (O(n²)), we store previously seen numbers and directly check if the complement exists.

---

## 🖼️ Proof

![alt text](two_sum.png)

