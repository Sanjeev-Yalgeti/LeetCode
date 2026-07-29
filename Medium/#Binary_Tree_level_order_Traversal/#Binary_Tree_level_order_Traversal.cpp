
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
#include <vector>
#include <queue>
using namespace std;    
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
        {
            return {};
        }
        queue<TreeNode*> order;
        vector<vector<int>> result;
        order.push(root);
        while(!order.empty())
        {
            int queueSize=order.size();
            if(!queueSize)
            {
                break;
            };
            int currLevel[]={};
            while(queueSize)
            {
                int curr=order.front()->val;
                currLevel.push(curr);
                if(curr->left)
                {
                    currLevel.push(curr->left);

                }
                if(curr->right)
                {
                    currLevel.push(curr->right);
                }
                queueSize--;
            }
            result.push_back(currLevel);
        }
        return result;
    }
};