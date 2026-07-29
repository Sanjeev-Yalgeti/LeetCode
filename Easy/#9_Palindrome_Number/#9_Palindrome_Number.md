# Container With Most Water (LeetCode 11)

## 🧾 Problem Statement

Given an integer x, determine whether it is a palindrome.

---
## 📌 Rules

- A palindrome reads the same forward and backward
- Negative numbers are not palindromes
- Do this without converting the number to a string

---

## 💡 Logic

* This code follows comparing rightmost and leftmost integer using mathematical operators .
* Traverse the string from both left and right.
* Create a copy of given integer and calculate Number of Digits using logarithmic formulae and determine the leftcheck varaible .
* Any Negative Integer is not a palindrome due to negative sign and all single digit integers are palindrome so return accordingly. 
* For each iteration of loop from 0 to half of number of digits:
    - check if leftmost and rightmost integer are same if yes continue else return false.
    - if leftmost and rightmost are same then remove both the leftmost and rightmost integers using modulus and division operators and adjust leftcheck variable by dividing it with 100 as two numbers are removed.

---

## ⚙️ Code

```cpp
#include <cmath>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        if(x<10)
        {
            return true;
        }
        else
        {
            int n=x;
            int digit=floor(log10(n))+1;
            int leftcheck=pow(10,digit-1);
            for(int i=0;i<floor(digit/2);i++)
            {
                if(n/leftcheck != n%10)return false;
                else{
                    n = (n % leftcheck) / 10;
                    leftcheck=leftcheck/100;
                    
                }
            }
            return true;
        }
    }
};
```

---

## ⏱️ Time Complexity

O(logn)

## 🧠 Space Complexity

O(1)

---

## 📊 Performance

* Runtime: 0 ms (beats 100.00%)
* Memory: 8.64 MB (beats 37.47%)

---

## 🖼️ Proof

![alt text](image.png)