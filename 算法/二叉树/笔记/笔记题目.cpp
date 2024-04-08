验证二叉搜索树
所以左子节点小于当前节点
所有当前节点小于右子节点

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
    bool isValidBST(TreeNode* root) {
        
        return isValidBST(root, LONG_MAX, LONG_MIN );
    }

    bool isValidBST(TreeNode*root,long max_value,long min_value)
    {
        if(root==nullptr)return true;
        if(root->val>=max_value||root->val<=min_value)return false;
        return isValidBST(root->left, root->val,min_value)&&isValidBST(root->right,max_value,  root->val);
    }

};

非递归遍历后续：
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr)return nums;
        TreeNode*last_visit = nullptr;
        q.push(root);

        while(!q.empty())
        {
            TreeNode*node = q.top();
            if((node->left==nullptr&&node->right==nullptr)||(last_visit!=nullptr&&(last_visit==node->left||last_visit==node->right)))
            {
                nums.push_back(node->val);
                q.pop();
                last_visit = node;
            }
            else
            {
                if(node->right!=nullptr)q.push(node->right);
                if(node->left!=nullptr)q.push(node->left);
            }
        }
            return nums;


    }
    private:
    vector<int>nums;
    stack<TreeNode*>q;
};


镜像递归
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
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
        return ismirror(root->left,root->right);
    }

    bool ismirror(TreeNode*left,TreeNode*right)
    {
        if(left==nullptr&&right==nullptr)return true;
        if(left==nullptr||right==nullptr)return false;
        if(left->val!=right->val)return false;
        return ismirror(left->left, right->right)&&ismirror(left->right, right->left);
    }
};

迭代：
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
    bool isSymmetric(TreeNode* root) {
        q.push(root->left);
        q.push(root->right);

        while(!q.empty())
        {
            TreeNode*leftNode = q.front();
            q.pop();
            TreeNode*rightNode = q.front();
            q.pop();

            if(leftNode==nullptr&&rightNode==nullptr)continue;
            if(leftNode==nullptr||rightNode==nullptr)return false;
            if(leftNode->val!=rightNode->val)return false;

            q.push(leftNode->left);
            q.push(rightNode->right);
            q.push(leftNode->right);
            q.push(rightNode->left);
        }
        return true;
    }
    private:
    queue<TreeNode*>q;

};