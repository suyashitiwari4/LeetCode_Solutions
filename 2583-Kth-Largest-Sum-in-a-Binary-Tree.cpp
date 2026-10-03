/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root) return -1;
        vector<long long>levelsums;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            long long currentlevelsum=0;
            for(int i=0; i<size; i++){
                TreeNode*node = q.front();
                q.pop();
                currentlevelsum+=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            levelsums.push_back(currentlevelsum);
        }
        if(levelsums.size()<k) return -1;
        sort(levelsums.rbegin(),levelsums.rend());
        return  levelsums[k-1];
    }
};