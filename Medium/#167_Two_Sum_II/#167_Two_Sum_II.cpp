#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> done;   
        for(int i=0;i< numbers.size();i++)
        {
            int need=target-numbers[i];
            if(done.find(need)!=done.end())
            {
                return {done[need]+1,i+1};
            }           
            done[numbers[i]]=i;
        };
        return {};
    }
};