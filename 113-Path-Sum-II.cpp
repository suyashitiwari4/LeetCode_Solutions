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
private:
    void dfs(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int>& currentPath){
           if(root == nullptr)return ;
           currentPath.push_back(root->val);

           if(root->left == nullptr && root->right == nullptr && targetSum==root->val){
               ans.push_back(currentPath);

        }
        else{
            dfs(root->left, targetSum-root->val,ans,currentPath);
            dfs(root->right, targetSum-root->val,ans,currentPath);
        }
        currentPath.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>currentPath;
        dfs(root,targetSum,ans,currentPath);
        return ans;
       
        
    }
};