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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        //two stacks
        stack<TreeNode*> currentlevel;
        stack<TreeNode*> nextlevel;
        currentlevel.push(root);
        bool left=true;
        vector<int> tempans;
        while(!currentlevel.empty()){
            TreeNode* temp=currentlevel.top();
            currentlevel.pop();  
            if(temp!=NULL){
                tempans.push_back(temp->val);
                if(left){
                    //if left to right, actually it will be printed right to left 
                    if(temp->left)nextlevel.push(temp->left);
                    if(temp->right)nextlevel.push(temp->right);
                    
                }
                else{
                   //if right to left,actually it will be printed left to right  
                    if(temp->right)nextlevel.push(temp->right); 
                    if(temp->left)nextlevel.push(temp->left);  
                }
            }
            if(currentlevel.empty()){
                left=!left;
                swap(currentlevel,nextlevel);
                ans.push_back(tempans);
               tempans.resize(0);
            }
        }
        return ans;
    }
};
