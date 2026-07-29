# Container With Most Water (LeetCode 11)

## 🧾 Problem Statement

Given a string representing a Roman numeral, convert it to an integer.
---
## 📌 Rules

Symbols and values:
I = 1, V = 5, X = 10
L = 50, C = 100, D = 500, M = 1000
Normally values are added left to right
If a smaller value appears before a larger one, subtract it

---

## 💡 Logic

* Use a mapping (e.g., map<char, int>) to store Roman symbols and their corresponding integer values.
* Traverse the string from left to right.
* For each character:
    - Add its value to the total.
    - Exception (subtractive cases):
    - If the current symbol has a greater value than the previous one (e.g., IV, IX, XL), it means the previous value was added incorrectly.
        - To fix this, subtract twice the previous value (once to cancel the earlier addition, and once to account for subtraction), then add the current value.


---

## ⚙️ Code

```cpp
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> RomInt={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int value=0;
        for(int i=0;i<s.size();i++)
        {
            if(i==0 || RomInt[s[i]]<=RomInt[s[i-1]])
            {
                value=value+RomInt[s[i]];
            }
            else
            {
                value=value+RomInt[s[i]]-2*RomInt[s[i-1]];
            }
        }
        return value;
    }
};
```

---

## ⏱️ Time Complexity

O(n)

## 🧠 Space Complexity

O(1)

---

## 📊 Performance

* Runtime: 0 ms (beats 100.00%)
* Memory: 13.42 MB (beats 18.01%)

---

## 🖼️ Proof

![alt text](image.png)