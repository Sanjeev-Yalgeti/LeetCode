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
        // int lenS=log10(n)+1;
       
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