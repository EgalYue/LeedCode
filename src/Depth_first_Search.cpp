struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr){
            return true;
        } else if(p == nullptr && q != nullptr){
            return false;
        } else if(p != nullptr && q == nullptr){
            return false;
        }

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        if(p->val == q->val && left && right){
            return true;
        } else{
            return false;
        }
    }
};

#include <queue>
class Solution2 {
public:
    bool check_curr_node(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr){
            return true;
        }
        if(p == nullptr || q == nullptr){
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        return true;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr){
            return true;
        }
        if(! check_curr_node(p,q)){
            return false;
        }

        std::queue<TreeNode*> queueP;
        std::queue<TreeNode*> queueQ;
        queueP.push(p);
        queueQ.push(q);

        while(!queueP.empty()){
            p = queueP.front();
            queueP.pop();
            q = queueQ.front();
            queueQ.pop();

            if(!check_curr_node(p->left,q->left)){
                return false;
            }

            if(p->left != nullptr){
                queueP.push(p->left);
                queueQ.push(q->left);
            }

            if(!check_curr_node(p->right,q->right)){
                return false;
            }

            if(p->right != nullptr){
                queueP.push(p->right);
                queueQ.push(q->right);
            }

        }
        return true;
    }
};


class Solution3 {
public:
    bool isEqual(TreeNode* left, TreeNode* right){
        if (left == nullptr && right == nullptr){
            return true;
        }
        if(left != nullptr && right == nullptr){
            return false;
        }
        if(left == nullptr && right != nullptr){
            return false;
        }
        if(left->val == right->val){
            return isEqual(left->left, right->right) && isEqual(left->right, right->left);
        }else{
            return false;
        }

    }
    bool isSymmetric(TreeNode* root) {
        return isEqual(root, root);
    }
};

class Solution4 {
public:
    bool isSymmetric(TreeNode* root) {
        std::queue<TreeNode*> q;
        if(root == nullptr){
            return true;
        }

        q.push(root);
        q.push(root);

        while(!q.empty()){
            TreeNode* leftNode = q.front();
            q.pop();
            TreeNode* rightNode = q.front();
            q.pop();

            if(leftNode == nullptr && rightNode != nullptr){
                return false;
            }
            if(leftNode != nullptr && rightNode == nullptr){
                return false;
            }
            if (leftNode == nullptr && rightNode == nullptr){
                continue;
            }
            if(leftNode->val == rightNode->val){
                q.push(leftNode->left);
                q.push(rightNode->right);
                q.push(leftNode->right);
                q.push(rightNode->left);
            } else{
                return false;
            }

        }

        return true;
    }
};

#include <algorithm>
class Solution5 {
public:
    int max_d = 0;
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        int max_left = maxDepth(root->left) + 1;
        int max_right = maxDepth(root->right) + 1;
        max_d = std::max(max_left, max_right);
        return max_d;

    }
};

class Solution6 {
public:
    int max_d = 0;
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        int max_left = maxDepth(root->left) + 1;
        int max_right = maxDepth(root->right) + 1;
        max_d = std::max(max_left, max_right);
        return max_d;

    }
};

#include <vector>
using namespace std;
class Solution7 {
public:

    TreeNode* sortedArray(vector<int>& nums, int start, int end){
        if (start >= end){
            TreeNode* root = new TreeNode(nums[start]);
            return root;
        }

        int middle = (start + end)/2;
        int this_val = nums[middle];


        TreeNode* root = new TreeNode(this_val);
        root->left = sortedArray(nums, start, middle);
        root->right = sortedArray(nums, middle + 1, end);
        return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArray(nums, 0, nums.size());
    }
};

class Solution8 {
public:
    int getHeight(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left_d = isBalanced(root->left) + 1;
        if(-1 == left_d){
            return -1;
        }
        int right_d = isBalanced(root ->right) + 1;
        if(-1 == right_d){
            return -1;
        }
        return (abs(left_d - right_d) > 1? -1 : max(left_d, right_d));
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1? false: true;
    }
};



class Solution9 {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        int minLeft = minDepth(root->left);
        int minRight = minDepth(root->right);

        return root->left == nullptr|| root->right == nullptr ? minLeft + minRight + 1 : min(minLeft,minRight) + 1;

    }
};

#include <stack>
#include <utility>
#include <limits.h>

class Solution10 {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int res = INT_MAX;

        std::stack<std::pair<TreeNode*, int>> st;
        st.push(std::make_pair(root, 1));

        while(!st.empty()){
            TreeNode* currNode = st.top().first;
            int currDepth = st.top().second;
            st.pop();
            if (currNode->left == nullptr && currNode->right == nullptr){
                res = min(res, currDepth);
            }
            if (currNode->left != nullptr){
                st.push(std::make_pair(currNode->left, currDepth + 1));
            }
            if (currNode->right != nullptr){
                st.push(std::make_pair(currNode->right, currDepth + 1));
            }

        }

        return res;
    }
};

class Solution11 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr ){
            return false;
        } else if(root != nullptr && root->val == sum && (root->left != nullptr || root->right != nullptr)){
            return false;
        } else if (root != nullptr && root->left == nullptr && root->right == nullptr && root->val == sum){
            return true;
        }

        std::stack<std::pair<TreeNode*, int>> st;
        st.push(std::make_pair(root, sum));

        while(!st.empty()){
            TreeNode* currNode = st.top().first;
            int currSum = st.top().second;
            st.pop();

            if( 0 == currSum - currNode->val && currNode->left == nullptr && currNode->right == nullptr){
                return true;
            }

            if(currNode->left != nullptr){
                st.push(std::make_pair(currNode->left, currSum - currNode->val));
            }

            if(currNode->right != nullptr){
                st.push(std::make_pair(currNode->right, currSum - currNode->val));
            }

        }
        return false;

    }
};

using namespace std;

#include <string>
class Solution12 {
public:
    vector<string> res;
    string sig = "->";

    void helper(TreeNode* root, string curr){
        if(root== nullptr){
            return;
        }
        if (root->left == nullptr && root->right == nullptr){
            curr = curr + to_string(root->val);
            res.push_back(curr);
        }
        if(root->left != nullptr){
            helper(root->left, curr  + to_string(root->val) + sig);
        }

        if(root->right != nullptr){
            helper(root->right, curr  + to_string(root->val) + sig);
        }

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string tem = "";
        helper(root, tem);
        return res;
    }
};


class Solution13 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {


        vector<string>  res;

        stack<std::pair<TreeNode*, string>> st;

        st.push(make_pair(root, to_string(root->val)));

        while(!st.empty()){
            TreeNode* currNode = st.top().first;
            string currStr = st.top().second;
            st.pop();

            if(root->left == nullptr && root->right == nullptr){

                res.push_back(currStr);
            }

            if(root->left != nullptr){
                st.push(make_pair(root->left, currStr+"->" + to_string(root->left->val)));
            }

            if(root->right != nullptr){
                st.push(make_pair(root->right, currStr+"->" + to_string(root->right->val)));
            }
        }

        return res;
    }
};
