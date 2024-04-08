 
//前序 递归版本
 vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr)return nums;
        nums.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return nums;
    }
    private:vector<int>nums;

//中序迭代版本
   vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode*>st;
        TreeNode*cur = root;
        while(!st.empty()||cur!=nullptr)
        {
            if(cur!=nullptr)
            {
                st.push(cur);
                cur = cur->left;//左
            }
            else
            {
                cur  = st.top();
                st.pop();
                nums.push_back(cur->val);//中
                cur = cur->right;//右边
            }
        }
        return nums;
        
    }

    vector<int>nums;


后序迭代版本：
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root ==nullptr)return nums;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode*cur = st.top();
            st.pop();
            nums.push_back(cur->val);

            if(cur->left)st.push(cur->left);
            if(cur->right)st.push(cur->right);
        }
        reverse(nums.begin(),nums.end());
        return nums;
    }
    private:
    vector<int>nums;
};


寻找最深的左值
class Solution {
public:
    void travel(TreeNode*root,int depth)
    {
        if(root->left==nullptr&&root->right==nullptr)
        {
            if(depth>maxdepth)
            {
                maxdepth = depth;
                result = root->val;
            }
            return;
        }
        if(root->left)
        {
            depth++;
            travel(root->left,depth);
            depth--;
        }
        if(root->right)
        {
            depth++;
            travel(root->right,depth);
            depth--;
        }

        return ;
    }
    int findBottomLeftValue(TreeNode* root) {
        travel(root,0);
        return result;
    }
    private:
    int result;
    int maxdepth = INT_MIN;

    
};

路径总和等于一个值
class Solution {
private:
    bool traversal(TreeNode* cur, int count) {
        if (!cur->left && !cur->right && count == 0) return true; // 遇到叶子节点，并且计数为0
        if (!cur->left && !cur->right) return false; // 遇到叶子节点直接返回

        if (cur->left) { // 左
            count -= cur->left->val; // 递归，处理节点;
            if (traversal(cur->left, count)) return true;
            count += cur->left->val; // 回溯，撤销处理结果
        }
        if (cur->right) { // 右
            count -= cur->right->val; // 递归，处理节点;
            if (traversal(cur->right, count)) return true;
            count += cur->right->val; // 回溯，撤销处理结果
        }
        return false;
    }

public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        return traversal(root, sum - root->val);
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right && sum == root->val) {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

通过前序和后序构造二叉树
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    //     vector<TreeNode*>st;
    //     st.push_back(new TreeNode(preorder[0]));
    //     for(int i =1,j=0;i<preorder.size();i++)
    //     {
    //         TreeNode* node = new TreeNode(preorder[i]);
    //         while(st.back()->val == postorder[j])
    //         {
    //             st.pop_back();
    //             ++j;
    //         }
    //     if(st.back()->left ==nullptr)
    //     {
    //         st.back()->left = node;
    //     }
    //     else
    //     {
    //         st.back()->right = node;
    //     }
    //     st.push_back(node);
    //     }
    // return st[0];
    TreeNode*node = new TreeNode(preorder[preidx++]);
    if(node->val!=postorder[postidx])
    {
        node->left = constructFromPrePost(preorder,postorder);
    }
    if(node->val != postorder[postidx])
    {
        node->right = constructFromPrePost(preorder,postorder);
    }
    postidx++;
    return node;
    }
    private:
     int preidx = 0, postidx = 0;
};

寻找祖先：
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==q||root==p||root==NULL)return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode*right = lowestCommonAncestor(root->right,p,q);

        if(left!=NULL&&right!=NULL)return root;
        if(left==NULL&&right!=NULL)return right;
        else if(left!=NULL&&right==NULL)return left;
        else{
            return NULL;
        }
        

    }
};

插入值任然是二叉搜素树：
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr)
        {
            TreeNode*root = new TreeNode(val);
            return root;
        }
        if(root->val >val)root->left = insertIntoBST(root->left, val);
        if(root->val<val)root->right = insertIntoBST(root->right,val);
        return root;
    }
};

修剪二叉树：
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==nullptr)return nullptr;
        if(root->val<low)
        {
            TreeNode*right = trimBST(root->right,low,high);
            return right;
        }
        if(root->val>high)
        {
            TreeNode*left = trimBST(root->left,low,high);
            return left;
        }
        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);
        return root;
    }
};