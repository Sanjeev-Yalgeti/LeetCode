#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        char stk[s.size()];
        int top=-1;
        if(s.size()==0)
        {
            return true;
        }
        if(s[0]==']' || s[0]==')' ||s[0]=='}')
        {
            return false;   
        }
        else{
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='[' || s[i]=='{' ||s[i]=='(')
                {
                    stk[++top]=s[i];
                }
                else if(s[i]==']')
                {
                    if(top==-1)
                    {
                        return false;
                    }
                    else if(stk[top]=='[')
                    {
                        top--;
                    }
                    else{
                        return false;
                    }
                }
                else if(s[i]=='}' )
                {
                    if(top==-1)
                    {
                        return false;
                    }
                    else if( stk[top] =='{' )
                    {
                        top--;
                    }
                    else{
                        return false;
                    }
                }
                else
                {
                    if(top==-1)
                    {
                        return false;
                    }
                    else if(stk[top]=='(' )
                    {
                        top--;
                    }
                    else{
                        return false;                
                    }
                }
            }
        }
        if(top==-1)
        {
            return true;
        }
        else return false;
    }
};
