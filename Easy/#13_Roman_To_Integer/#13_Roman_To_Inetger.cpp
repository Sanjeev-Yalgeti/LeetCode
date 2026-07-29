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