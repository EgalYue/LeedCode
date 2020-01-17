#include <vector>
#include <string>
using namespace std;

vector<string> res;

void helper(string cur, string S){
    if(0 == S.size()){
        res.push_back(cur);
        return;
    }
    char s = S[0];
    helper(cur+s, S.substr(1));
    if (s >= 'a' && s <= 'z'){
        helper(cur+char(toupper(s)), S.substr(1));
    } else if (s >= 'A' && s<= 'Z'){
        helper(cur+char(tolower(s)), S.substr(1));
    }
}

vector<string> letterCasePermutation(string S) {
    helper("", S);
    return res;

}

//=======================================================================

vector<string> res ;

vector<string> readBinaryWatch(int num) {
    if (8 < num){

    }

}

//====================================================================
#include<algorithm>
vector<vector<int>> res3;

void helper(vector<int> & nums, vector<int>& cur){
    if(cur.size() == nums.size()){
        res3.push_back(cur);
        return;
    }
    for(int i=0;i<nums.size();i++){
        vector<int>::iterator ret = std::find(cur.begin(),cur.end(), nums[i]);
        if(ret == cur.end()){
            cur.push_back(nums[i]);
            helper(nums, cur);
            cur.pop_back();

        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<int> cur;
    helper(nums, cur);
    return res3;
}

//====================================================================
vector<vector<int>> res4;

void helper4(vector<int> & nums, vector<int>& cur, vector<int>& visited){
    if(nums.size() == cur.size()){
        res4.push_back(cur);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(visited[i]) continue;
        if(i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) continue;
        cur.push_back(nums[i]);
        visited[i] = 1;
        helper4(nums, cur, visited);
        cur.pop_back();
        visited[i] = 0;

    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<int> cur;
    vector<int> visited(nums.size(),0);
    sort(nums.begin(),nums.end());
    helper4(nums, cur, visited);
    return res4;

}

//========================================================================

class Solution {
private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start;
             i < candidates.size() && target - candidates[i] >= 0; i++) {
            path.push_back(candidates[i]);
            DFS(i, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);

        return res;
    }

};

//========================================================================
vector<vector<int>> res5;
void helper(vector<int>& candidates, int target, vector<int>& curr, int n){
    if(0 == target){
        res5.push_back(curr);
        return;
    }
    for(int i =n;i< candidates.size();i++){
        int this_v = candidates[i];
        if (i > n && candidates[i] == candidates[i - 1])
            continue;
        if(this_v <= target){
            curr.push_back(this_v);
            helper(candidates, target - this_v, curr, i+1);
            curr.pop_back();
        }
    }

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> curr;
    helper(candidates, target, curr, 0);
    return res5;
}

class Solution6 {
public:
    vector<vector<int>> res;
    void helper(int n, int k, vector<int>& curr, int pos){
        if(0 == k){
            res.push_back(curr);
            return;
        }

        for(int i = pos; i<=n; i++){
            curr.push_back(i);
            helper(n, k-1, curr, i+1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        helper(n, k, curr, 1);
        return res;
    }
};

//===========================================================================

class Solution7 {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums, vector<int>& curr, int k, int pos){
        if(0 == k){
            res.push_back(curr);
            return;
        }

        for(int i = pos; i<nums.size();i++){
            int this_v = nums[i];
            curr.push_back(this_v);
            helper(nums, curr, k -1 , i+1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        for(int i =0;i<=nums.size();i++){
            helper(nums, curr, i, 0);
        }
        return res;

    }
};

//===========================================================================
class Solution8 {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums, vector<int>& curr, int k, int pos){
        if(0 > k){
            return;
        }

        for(int i = pos; i<nums.size();i++){
            int this_v = nums[i];
            curr.push_back(this_v);
            res.push_back(curr);
            helper(nums, curr, k -1 , i+1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        helper(nums, curr, nums.size(), 0);

        return res;

    }
};

class Solution9 {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums, vector<int>& curr, int k, int pos){
        if(0 > k){
            return;
        }

        for(int i = pos; i<nums.size();i++){
            if(i > pos && nums[i] == nums[i-1]){
                continue;
            }
            int this_v = nums[i];
            curr.push_back(this_v);
            res.push_back(curr);
            helper(nums, curr, k -1 , i+1);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        res.push_back(curr);
        helper(nums, curr, nums.size(), 0);
        return res;
    }
};

class Solution10 {
public:

    vector<vector<int>> res;
    void helper(int k, int n, vector<int>& curr, int index){
        if (0 == k && 0 == n){
            res.push_back(curr);
            return;
        }

        for(int i = index; i <= 9; i++){
            if(n >= i){
                curr.push_back(i);
                helper(k-1, n-i, curr, i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        helper(k, n, curr, 1);
        return res;
    }
};

class Solution11 {
public:
    vector<vector<string>> res;

    /* 是否可以在 board[row][col] 放置皇后？ */
    bool isValid(vector<string>& board, int row, int col) {
        int n = board.size();
        // 检查列是否有皇后互相冲突
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        // 检查右上方是否有皇后互相冲突
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        // 检查左上方是否有皇后互相冲突
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }


// 路径：board 中小于 row 的那些行都已经成功放置了皇后
// 选择列表：第 row 行的所有列都是放置皇后的选择
// 结束条件：row 超过 board 的最后一行
    void backtrack(vector<string>& board, int row) {
        // 触发结束条件
        if (row == board.size()) {
            res.push_back(board);
            return;
        }

        int n = board[row].size();
        for (int col = 0; col < n; col++) {
            // 排除不合法选择
            if (!isValid(board, row, col))
                continue;
            // 做选择
            board[row][col] = 'Q';
            // 进入下一行决策
            backtrack(board, row + 1);
            // 撤销选择
            board[row][col] = '.';
        }
    }

/* 输入棋盘边长 n，返回所有合法的放置 */
    vector<vector<string>> solveNQueens(int n) {
        // '.' 表示空，'Q' 表示皇后，初始化空棋盘。
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }

};