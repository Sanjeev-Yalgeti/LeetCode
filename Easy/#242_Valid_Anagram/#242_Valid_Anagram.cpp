#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> countS;        
        unordered_map<char,int> countT;
x
        for(char c:s)
        {
            countS[c]++;
        }        
        for(char c:t)
        {
            countT[c]++;
        }        
        if(countS==countT)
        {
            return true;
        }
        else{
            return false;
        }
    }
};