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

//Traversal and dfs question
//TreeNode(value, walk left, walk right *right)
//only have 4 case
//case 1: t1 and t2 doesn't have any edge
//case 2: t1 has edge, but t2 doesn't 
//case 3: t1 doesn't have edge, but t2 has
//case 4: t1 and t2 have any edge
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return createNode(t1, t2);
    }
private:
    TreeNode* createNode(TreeNode* t1, TreeNode* t2)
    {
        //case 1: t1 and t2 doesn't have any edge
        if(t1 == nullptr && t2 == nullptr)
            return nullptr;
        
        //case 2: t1 has edge, but t2 doesn't 
        if(t1 != nullptr && t2 == nullptr)
            return new TreeNode(t1->val,
                                createNode(t1 -> left, nullptr),
                                createNode(t1 -> right, nullptr));

        //case 3: t1 doesn't have edge, but t2 has
         if(t1 == nullptr && t2 != nullptr)
            return new TreeNode(t2->val,
                                createNode(nullptr, t2 -> left),
                                createNode(nullptr, t2 -> right));
        //case 4: t1 and t2 have any edge
        return new TreeNode(t1->val + t2->val,
                                createNode(t1 -> left, t2 -> left),
                                createNode(t1 -> right, t2 -> right));
    }
};
