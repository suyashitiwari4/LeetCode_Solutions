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
    TreeNode* helper(vector<int>& inorder,int in_start, int in_end, vector<int>& postorder,int post_start,int post_end,unordered_map<int, int>& in_map){
                        if(post_start>post_end || in_start>in_end) return nullptr;
                        int rootval=postorder[post_end];
                        TreeNode* root =new TreeNode(rootval);
                        int inroot=in_map[rootval];
                        int leftsize=inroot-in_start;
                        root->left=helper(inorder, in_start, inroot - 1, 
                            postorder, post_start, post_start + leftsize - 1, 
                            in_map);
                        root->right=helper(inorder,inroot+1,in_end,postorder,post_start+leftsize,post_end-1,in_map);
                        return root;

                 }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>in_map;
        for(int i=0; i<inorder.size();i++){
            in_map[inorder[i]]=i;
        }
        return helper(inorder, 0, inorder.size() - 1, 
                      postorder, 0, postorder.size() - 1, 
                      in_map);

    }
};