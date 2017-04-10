//
// Created by Bing on 17/4/2.
//

#include "leetcode.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        sumTree(root);
        for(int i= ls.size()-2;i>=0;i--){
            (this->ls)[i]->val += (this->ls)[i+1]->val;
        }
        return root;
    }
    int sumTree(TreeNode* node){
        if(node == NULL)    return 0;
        sumTree(node->left);
        this->ls.push_back(node);
        sumTree(node->right);
        return 0;
    }
    vector<TreeNode*> ls;
};


