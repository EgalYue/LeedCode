#include<vector>
#include <string>
using namespace std;

#include<math.h>
int kthGrammar(int N, int K) {
    if(K >pow(N,K)){
        return 0;
    }

    if(N == 1){
        return 0;
    }

    if (0 == kthGrammar(N-1, (K-1)/2)){
        if(1 == K % 2){
            return 0;
        }else{
            return 1;
        }
    }else{
        if(1 == K % 2){
            return 1;
        }else{
            return 0;
        }
    }

}

//================================================================

int tribonacci2(int n) {
    if (0 == n){
        return 0;
    } else if (1 == n || 2 == n){
        return  1;
    } else{
        int pre0 = 1;
        int pre1 = 1;
        int pre2 = 0;
        int res = 0;
        for (int i = 3;i<= n; i++){
            res = pre0 + pre1 + pre2;
            pre2 = pre1;
            pre1 = pre0;
            pre0 = res;
        }
        return res;
    }
}

//===============================================================
#include <numeric>
#include <algorithm>
bool bool_search(vector<int> &groups, int row, vector<int> &nums, int target){
    if(row < 0){
        return true;
    }
    int v = nums[row--];
    for(int i = 0; i < groups.size(); i++){
        if(groups[i] + v<= target){
            groups[i] += v;
            if (bool_search(groups, row, nums, target)) return true;
            groups[i] -= v;
        }
        if (groups[i] == 0) break;
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin() , nums.end() , 0);
    if (0 != sum % k){
        return false;
    }
    int average = sum / k;
    sort(nums.begin(),nums.end(), greater<int>());
    int row = nums.size() - 1;
    int max_v = nums[row];
    if (max_v > average){
        return false;
    }
    vector<int> vec(k,0);

    return bool_search(vec, row, nums, average);
}

//============================================================
int max_value = 0;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int helper(TreeNode* root){ // the longest way, contains root
    if (root == nullptr){
        return 0;
    }
    int left_value = helper(root->left);
    int right_value = helper(root->right);

    if (root->left != nullptr && root->val == root->left->val){
        ++left_value;
    }else{
        left_value = 0;
    }

    if (root->right != nullptr && root->val == root->right->val){
        ++right_value;
    }else{
        right_value = 0;
    }

    max_value = max(max_value, left_value+right_value);
    return max(left_value, right_value);
}

int longestUnivaluePath(TreeNode* root) {
    helper(root);
    return max_value;
}

//========================================================================

int helper(TreeNode* root, int L, int R){
    if(root == nullptr){
        return 0;
    }
    if(root->val < L){
        return helper(root->right, L, R);
    }
    else if(root->val > R){
        return helper(root->left, L, R);
    }else{
        int left_sum = helper(root->left, L, R);
        int right_sum = helper(root->right, L, R);
        return root->val + left_sum + right_sum;
    }
}

int rangeSumBST(TreeNode* root, int L, int R) {
    return helper(root, L, R);
}

//=======================================================================

#include<limits.h>
class Solution {
    TreeNode* last = nullptr;
    int minDiff = INT_MAX;
public:
    int minDiffInBST(TreeNode* root) {
        inOrder(root);
        return minDiff;
    }

    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->left);
        if(last)
            minDiff = min(minDiff, root->val - last->val);
        last = root;
        inOrder(root->right);
    }
};

//=========================================================================
vector<TreeNode*> allPossibleFBT(int N) {
    vector<TreeNode*> res;
    if(1==N) {
        res.push_back(new TreeNode(0));
        return res;
    } else if(0 == N %2 ){
        return res;
    } else{
        int left_num = 1;
        int right_num = N - 2;

        while( right_num > 0){
            vector<TreeNode*> left_tree = allPossibleFBT(left_num);
            vector<TreeNode*> right_tree = allPossibleFBT(right_num);
            for(auto i:left_tree){
                for(auto j:right_tree){
                    TreeNode* root = new TreeNode(0);
                    root->left = i;
                    root->right = j;
                    res.push_back(root);
                }
            }
            left_num += 2;
            right_num += 2;
        }

        return res;
    }
}









