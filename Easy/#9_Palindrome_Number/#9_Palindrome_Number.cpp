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