# Largest integer with given digit sum (LeetCode 4000)
(First Leetcode Contest Sum Solved)



## 🧾 Problem Statement



You are given two non-negative integers n and s.

Return the largest integer that has at most n digits and whose sum of digits is s. If no such integer exists, return -1.



---

## 💡 Logic



* This was my first experience with Leetcode Contest and only managed to solve this "Easy" Sum in the span of 74 mins.First time that i was time constrained and under pressure without any tools to help me .

* The approach I have used changed multiple times.In the end i applied teh 'greedy Approach' unknowingly which I later came to know. 
 
* Greedy appraoch is a way to solve which focuses on present and chooses the most optimal path in present without considering future consequences. Here the most optimal path was to assign highest possible value to the Most significant bit(leftmost) position and moving towards the LSB(right most) while doing so.

* First to counter unique / Special cases:-
    1. Numbers whose value exceeds the maximum possible digit sum are to be return -1.For every value of n, the max possible digit value is 9 times n because all digit can be of value 9 at most.
    2. Single Digit Numbers ,the largest possibe integer is their multiple of 10 raised to power of n-1.
    ex: if s=3 and n=4; largest possible integer with sum '3' and  4 digits will be 3000.

* To deal with the major cases, We create a vector 'result' which will store the result values.initialise digit which will store current digit value.Using greedy appraoch , if remaining value of s is greater than 9 , we assign 9 to digit and push it back in result and subtract 9 from s and run the loop till n becomes 0.


---



## ⚙️ Code



```cpp

#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int largestInteger(int n, int s) {
        const int pow[5]={1,10,100,1000,10000};
        if(s<10)
        {
            return s*pow[n-1];
        }
        int max=9*n;
        if(s>max)
        {
            return -1;
        }
        vector<int> result;
        int lenS=log10(n)+1;
        int remain;
        int digit=0;
        while(n--)
            {
                digit=min(9,s);
                result.push_back(digit);
                s=s-digit;
            }
        int final=0;
        for (int num:result){
            final=final*10+num;
        }
        return final;
    }
};
```



---



## ⏱️ Time Complexity



O(n)



## 🧠 Space Complexity



O(n)



---



## 📊 Performance



* Runtime: 0 ms (beats 100.%)

* Memory: 8.51 MB (beats 12.51%)



---



## 🖼️ Proof



![alt text](image.png)
