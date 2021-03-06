//
// Created by yuehu on 19-4-17.
//
#include <iostream>
#include <vector>
#include <limits>

using namespace std;


//class Solution1{
//    int removeElement(int A[], int n, int elem){
//        int i = 0;
//        int j = 0;
//        for(i = 0; i < n; i++){
//            if (elem == A[i]){
//                continue;
//            }
//            A[j] = A[i];
//            j++;
//        }
//        return j;
//    }
//};
//
//class Solution2{
//    int removeDuplicates(int A[], int n){
//        int j = 0;
//        for(int i = 0; i < n; i++){
//            if (A[i] == A[j]){
//                continue;
//            }
//            else{
//                j++;
//                A[j] = A[i];
//            }
//        }
//        return j + 1;
//    }
//};
//
//class Solution3{
//    int removeDuplicates(int A[], int n){
//        int j = 0;
//        int num = 0;
//        for(int i = 0; i < n; i++){
//            if (A[i] == A[j]){
//                if (num < 2){
//                    j++;
//                    A[j] = A[i];
//                }
//            }
//            else{
//                j++;
//                A[j] = A[i];
//                num = 0;
//            }
//        }
//        return j + 1;
//    }
//};
//
//class Solution4{
//public:
//    vector<int> plusOne(const vector<int> &digits){
//        vector<int> res(digits.size(), 0);
//
//        int sum = 0;
//        int carry = 1;
//        for (int i=0;i<digits.size();i++){
//            sum = digits[i] + carry;
//            res[i] = sum % 10;
//            carry = sum / 10;
//        }
//        if (carry > 0){
//            res.insert(res.begin(), carry);
//        }
//        return res;
//    }
//};
//
//class Solution5{
//public:
//    vector<int> getRow(int rowIndex){
//        vector<int> res;
//        for(int i=0;i<rowIndex;i++){
//            for(int j=1;j<i-1;j++){
//                res[j] = res[j] + res[j-1];
//            }
//        }
//        return res;
//    }
//};
//
//class Solution6{
//public:
//    void merge(int A[], int a_num, int B[], int b_num){
//        int res_index = a_num + b_num - 1;
//        int a_index = a_num - 1;
//        int b_index = b_num - 1;
//        while(res_index >= 0){
//            if (a_index >= 0 && b_index >= 0){
//                if(A[a_index] > B[b_index]){
//                    A[res_index] = A[a_index];
//                    a_index--;
//                }
//                else{
//                    A[res_index] = B[b_index];
//                    b_index--;
//                }
//            } else if(a_index >= 0 && b_index < 0){
//                A[res_index] = A[a_index];
//                a_index--;
//            } else if(b_index >= 0 && a_index < 0){
//                A[res_index] = B[a_index];
//                b_index--;
//            }
//            res_index--;
//        }
//
//    }
//};
//
//class Solution7{
//public:
//    int findMin(vector<int> &num){
//        int size = num.size();
//
//        if(size == 0) {
//            return 0;
//        } else if(size == 1){
//            return num[0];
//        } else if (size == 2){
//            return min(num[0], num[1]);
//        }
//
//        int start = 0;
//        int end = size - 1;
//        while(start < end - 1){
//            if (num[start] < num[end]){
//                return num[start];
//            }
//
//            int mid = (start + end) / 2;
//            if (num[mid] > num[start]){
//                start = mid;
//            } else if (num[mid] < num[start]){
//                end = mid;
//            } else {
//                start++;
//            }
//        }
//
//        return min(num[start], num[end]);
//
//    }
//};
//
//class Solution8{
//public:
//    int largestRectangArea(vector<int> &height){
//        vector<int> s;
//        height.push_back(0);
//
//        int sum = 0;
//        int i = 0;
//        while(i < height.size()){
//            if (s.empty() || height[i] > height[s.back()]){
//                s.push_back(i);
//                i++;
//            } else{
//                int t = s.back();
//                s.pop_back();
//                sum = max(sum, height[t] * (s.empty()? i : i - s.back() - 1));
//            }
//        }
//        return sum;
//    }
//};
//
//class Solution9{
//public:
//    int missingNumber(vector<int> &nums){
//        int x = 0;
//        for (int i=0;i<nums.size();i++){
//            x ^= i;
//        }
//        for(auto one:nums){
//            x ^= one;
//        }
//        return x;
//    }
//};
//
//class Solution10{
//public:
//    bool isPowerOfTwo(int n){
//        if (n < 0) return false;
//
//        bool hasOne = false;
//        while(n > 0){
//            if (n & 1){
//                if (hasOne){
//                    return true;
//                }else{
//                    hasOne = true;
//                }
//            }
//            n >>= 1;
//        }
//        return hasOne;
//    }
//};
//
//// Tree
//struct TreeNode{
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x): val(x), left(nullptr), right(nullptr){};
//};
//
//class Solution11{
//public:
//    int num;
//    int maxDepth(TreeNode *root){
//        if(!root){
//            return 0;
//        }
//        num = numeric_limits<int>::min();
//        travel(root, 1);
//        return num;
//    }
//
//    void travel(TreeNode* node, int level){
//        if (!node->left && !node->right){
//            num = max(num, level);
//            return;
//        }
//
//        if (node->left){
//            travel(node->left, level + 1);
//        }
//        if (node->right){
//            travel(node->right, level + 1);
//        }
//    }
//};
//
//class Solution12{
//public:
//    int	n;
//    int	minDepth(TreeNode *root){
//        if(!root){
//            return	0;
//        }
//
//        n = numeric_limits<int>::max();
//        int	d =	1;
//        depth(root,	d);
//        return n;
//    }
//
//    void depth(TreeNode* node, int& d){
//        if(!node->left && !node->right)	{
//            n = min(n, d);
//            return;
//        }
//
//        if(node->left){
//            depth(node->left, d+1);
//        }
//        if(node->right)	{
//            depth(node->right, d+1);
//        }
//    }
//};
//
//class Solution13{
//public:
//    vector<vector<int>> levelOrder(TreeNode *root){
//        int depth = getHeight(root);
//        vector<vector<int>> ret(depth);
//        if(depth == 0){
//            return ret;
//        }
//        getSolution(ret, root, 0);
//        return ret;
//    }
//
//    int getHeight(TreeNode *root){
//        if(root == nullptr){
//            return 0;
//        }
//        int left = getHeight(root->left);
//        int right = getHeight(root->right);
//        int height = (left > right?left:right) + 1;
//        return height;
//    }
//
//    void getSolution(vector<vector<int>>& ret, TreeNode* root, int level){
//        if(root == nullptr){
//            return;
//        }
//        ret[level].push_back(root->val);
//        getSolution(ret, root->left, level+1);
//        getSolution(ret, root->right, level+1);
//    }
//};
//
//class Solution14{
//public:
//    bool isSymmetric(TreeNode *root){
//        if(root == nullptr) return true;
//
//        return helper(root->left, root->right);
//    }
//
//    bool helper(TreeNode *left, TreeNode *right){
//        if(left == nullptr && right == nullptr) return true;
//        else if (left == nullptr || right == nullptr) return false;
//
//        bool cond1 = (left->val == right->val);
//        bool cond2 = helper(left->left, right->right);
//        bool cond3 = helper(left->right, right->left);
//        return cond1 && cond2 & cond3;
//    }
//};
//
//class Solution15{
//public:
//    bool hasPathSum(TreeNode *root, int sum){
//        if(root == nullptr) return false;
//        return dfs(sum, 0, root);
//    }
//    bool dfs(int target, int sum, TreeNode *root){
//        if(root == nullptr) return false;
//
//        sum += root->val;
//        if(root->left == nullptr && root->right == nullptr){
//            if(sum == target) return true;
//            else return false;
//        }
//
//        bool leftPart = dfs(target, sum, root->left);
//        bool rightPart = dfs(target, sum, root->right);
//        return leftPart || rightPart;
//    }
//};
//
//class Solution16{
//public:
//    vector<vector<int>> combine(int n, int k){
//        vector<vector<int>> ret;
//        if(n <= 0){
//            return ret;
//        }
//
//        vector<int> curr;
//        DFS(ret, curr, n, k, 1);
//        return ret;
//    }
//
//    void DFS(vector<vector<int>>& ret, vector<int> curr, int n, int k, int level){
//        if(curr.size() == k){
//            ret.push_back(curr);
//            return;
//        }
//        if(curr.size() > k){
//            return;
//        }
//        for(int i=level; i<=n; i++){
//            curr.push_back(i)
//            DFS(ret,curr,n,k,i+1);
//            curr.pop_back();
//        }
//    }
//};

//class Node{
//public:
//    int value;
//    Node *next;
//
//    explicit Node(int value): value(value), next(nullptr){}
//};
//
//Node* addTwoNum(Node *l1, Node *l2){
//    int sum = 0;
//    int carry = 0;
//    Node *res_head = new Node(-1);
//    Node *res_next = res_head;
//    Node *p = l1;
//    Node *q = l2;
//
//    while(p != nullptr || q != nullptr || carry){
//        sum = (p?p->value:0) + (q?q->value:0);
//        if (sum >= 10){
//            carry = 1;
//            sum = sum - 10;
//        }
//
//        Node* res_temp = new Node(sum);
//        res_next->next = res_temp;
//
//        res_next = res_next->next;
//        if(p) p = p->next;
//        if(q) q = q->next;
//    }
//    return res_head->next;
//}
//
//#include <vector>
//#include <set>
//
//using namespace std;
//vector<int> intersection(const vector<int> &v1, const vector<int> &v2){
//    set<int> s1;
//    for (int i : v1) {
//        s1.insert(i);
//    }
//    set<int> resSet;
//    for(int j=1;j<v2.size();j++){
//        if(s1.find(v2[j]) != s1.end()){
//            resSet.insert(v2[j]);
//        }
//    }
//    vector<int> resVec;
//    resVec.reserve(resSet.size());
//    for (int iter : resSet) {
//        resVec.push_back(iter);
//    }
//
//    return resVec;
//}
//
//#include <vector>
//#include <map>
//using namespace std;
//
//vector<int> intersection2(const vector<int> &v1, const vector<int> &v2){
//    map<int, int> record;
//    for(int i : v1){
//        record[i] += 1;
//    }
//    vector<int> resVec;
//    for(int j : v2){
//        if(record[j] > 0){
//            resVec.push_back(j);
//            record[j] --;
//        }
//    }
//
//    return resVec;
//}
//
//#include <string>
//string reverseString(string &str){
//    int i = 0;
//    int j = str.size() - 1;
//    while(i < j){
//        swap(str[i], str[j]);
//        i++;
//        j--;
//    }
//    return str;
//}


//using namespace std;
//class Node{
//public:
//    int value;
//    Node *next;
//    explicit Node(int value): value(value), next(nullptr){
//
//    }
//};
//
//Node* oddEvenLinkedList(Node *input){
//    if (input == nullptr || input->next == nullptr || input->next->next == nullptr){
//        return input;
//    }
//
//    Node *odd = new Node(-1);
//    Node *even = new Node(-1);
//
//    Node *oddNext = odd;
//    Node *evenNext = even;
//    Node *next = input;
//
//    int count = 1;
//    while( next != nullptr){
//        if (count % 2 != 0){
//            // odd
//            oddNext->next = next;
//        }
//        else{
//            // even
//            evenNext->next = next;
//        }
//
//        oddNext = oddNext->next;
//        evenNext = evenNext->next;
//        next = next->next;
//        count++;
//    }
//    oddNext ->next = even->next;
//    return odd->next;
//}

//void moveZeros(vector<int> &input){
//    int k = 0;
//    for (int i =0; i<input.size(); i++){
//        if(input[i]){
//            if(k != i){
//                swap(input[k], input[i]);
//            }
//            k++;
//        }
//    }
//}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution19 {
public:

    int getLength(ListNode* head){
        ListNode* curr = head;
        int num = 0;
        while(curr != nullptr){
            curr = curr->next;
            num++;
        }
        return num;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = getLength(head);
        int pos = length - n;

        ListNode* sentinel = new ListNode(-1);
        ListNode* pre = sentinel;
        pre->next = head;
        ListNode* curr = head;

        while(pos >= 0){
            if(pos == n){
                pre->next = curr->next;
            }

            pre = curr;
            curr = curr->next;
            pos--;
        }

        return sentinel->next;

    }
};


#include <stack>
#include <inttypes.h>


#include<numeric>
class Solution1013 {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum % 3 != 0) {
            return false;
        }
        int count = 0, subSum = 0;
        for (int i = 0; i < A.size(); i ++) {
            subSum += A[i];
            if (subSum == sum / 3) {
                count ++;
                subSum = 0;
            }
            if (count == 3) {
                return true;
            }
        }
        return false;
    }
};

#include <algorithm>
class Solution581 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>::iterator iter_begin = nums.begin();
        vector<int>::iterator iter_end = nums.end();
        int i;
        for(i = 0; i < nums.size();i++){
            vector<int>::iterator min_right = min_element(iter_begin + i + 1, iter_end);
            if(nums[i] > *min_right){
                break;
            }
        }
        cout<< "i "<< i << endl;
        if (i == nums.size() - 1){
            return 0;
        }

        int j;
        for(j = nums.size()-1; j > 0;j--){
            vector<int>::iterator max_left = max_element(iter_begin, iter_begin + j);
            if(nums[j] < *max_left){
                break;
            }
        }
        cout<<"j " <<  j << endl;
        return j- i+1;

    }
};


class Solution523 {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        size_t len = nums.size();

        int sum =0;
        for(int r=0;r<len;r++){
            for(int l=0;l<r;l++){
                sum = accumulate(nums.begin() + l,nums.begin() + r+1,0);

                cout<< "L= " << l << " R= "<< r<< " sum=" <<sum << endl;
                if(0 == k && k == sum && r-l >=1){
                    return true;
                }
                else if( 0 !=k && sum % k == 0 && r-l >=1){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
//    uint32_t b = 1;
//
//    cout<< (1 & b) << endl;
//
//    printf("%" PRIu32 "\n",b);

//    ListNode* curr = new ListNode(9);
//    ListNode* temp = curr;
//    temp->val = 10;
//    cout<< curr->val<<endl;

    vector<int> input;
    input.push_back(0);
    input.push_back(1);
    input.push_back(0);
//    input.push_back(6);
//    input.push_back(7);
//    input.push_back(18);
//    input.push_back(-19);
//    input.push_back(-1);
//    input.push_back(10);
//    input.push_back(10);

    Solution523 s;
    cout<< s.checkSubarraySum(input, 0) << endl;

    return 0;

}
