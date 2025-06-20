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
    void createMapping(vector<int> &inorder, map<int,int> &nodeToIndex) {
        for(int i = 0; i < inorder.size(); i++) {
            nodeToIndex[inorder[i]] = i;
        }
    }
    TreeNode* solve(vector<int> &inorder, vector<int> &postorder, int &postorderIndex, int inorderStart, int inorderEnd,map<int,int> &nodeToIndex) {
        if(postorderIndex < 0 || inorderStart > inorderEnd) {
            return NULL;
        }

        int element = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];

        // recursive calls to build left and right subtree
        root->right = solve(inorder, postorder, postorderIndex, position + 1, inorderEnd,nodeToIndex);
        root->left = solve(inorder, postorder, postorderIndex, inorderStart, position - 1,nodeToIndex);
        // root->right = solve(inorder, postorder, postorderIndex, position + 1, inorderEnd,nodeToIndex);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderIndex = postorder.size()-1;
        map<int,int> nodeToIndex;
        createMapping(inorder, nodeToIndex);
        return solve(inorder, postorder, postorderIndex, 0, inorder.size() - 1,nodeToIndex);
    }
};