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
    void solve(TreeNode* root, vector<int> &bt){
        if(!root)
            return;
        if(root->left==nullptr && root->right==nullptr){
            bt.push_back(root->val);
            return;
        }
        solve(root->left, bt);
        solve(root->right, bt);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> bt1, bt2;
        solve(root1, bt1);
        solve(root2, bt2);

        if(bt1.size() == bt2.size()){
            for(int i = 0; i < bt1.size(); i++){
                if(bt1[i] != bt2[i]){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};