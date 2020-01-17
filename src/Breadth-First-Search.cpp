//
// Created by yuehu on 2020/1/13.
//

#include <vector>
#include <string>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution01 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }

        queue<TreeNode*> q;

        q.push(root);

        while(! q.empty()){
            int q_size = q.size();

            vector<int> temp;
            for (int i =0;i< q_size;i++){
                TreeNode* currNode = q.front();
                q.pop();

                temp.push_back(currNode->val);
                if(currNode->left != nullptr){
                    q.push(currNode->left);
                }
                if(currNode->right != nullptr){
                    q.push(currNode->right);
                }
            }
            res.insert(res.begin(), temp);
        }

        return res;
    }
};


//==============================================================================

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution02 {
public:
    int maxDepth(Node* root) {

        if(root == nullptr){
            return 0;
        }
        queue<pair<Node*, int>> q;
        q.push(make_pair(root,1));

        int maxD = 1;
        while(! q.empty()){
            int q_size = q.size();

            pair<Node*, int> currPair = q.front();
            Node* currNode = currPair.first;
            int currDepth = currPair.second;
            q.pop();

            int childNum = currNode->children.size();
            for(int i =0;i<childNum;i++){
                Node* child = currNode->children[i];
                if(child != 0){
                    q.push(make_pair(child, currDepth +1));
                    maxD = maxD > currDepth +1? maxD:currDepth +1;
                }
            }
        }

        return maxD;

    }
};