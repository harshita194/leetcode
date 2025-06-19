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
    // Helper function to find the position of the root element in inorder
    void createMapping(vector<int> &inorder, map<int,int> &nodeToIndex) {
        for(int i = 0; i < inorder.size(); i++) {
            nodeToIndex[inorder[i]] = i;
        }
    }

    // Recursive function to build the tree
    TreeNode* solve(vector<int> &inorder, vector<int> &preorder, int &preorderIndex, int inorderStart, int inorderEnd,map<int,int> &nodeToIndex) {
        if(preorderIndex >= preorder.size() || inorderStart > inorderEnd) {
            return NULL;
        }

        int element = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];

        // recursive calls to build left and right subtree
        root->left = solve(inorder, preorder, preorderIndex, inorderStart, position - 1,nodeToIndex);
        root->right = solve(inorder, preorder, preorderIndex, position + 1, inorderEnd,nodeToIndex);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        map<int,int> nodeToIndex;
        createMapping(inorder, nodeToIndex);
        return solve(inorder, preorder, preorderIndex, 0, inorder.size() - 1,nodeToIndex);
    }
};