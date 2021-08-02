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
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> smallans;
        while(!q.empty()){
            TreeNode* first=q.front();
            q.pop();
            if(first==NULL){
                //put ans in result;
                result.push_back(smallans);
                smallans.resize(0);
                if(q.size()>0){
                     q.push(NULL);
                }
            }
            else{
                smallans.push_back(first->val);
                if(first->left) q.push(first->left);
                if(first->right) q.push(first->right);
            }
        }
        return result;
    }
};
