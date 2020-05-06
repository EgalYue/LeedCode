//
// Created by yuehu on 2019/11/21.
//

#include <string>
#include <vector>
using namespace std;

class Solution5 {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len <=1){
            return s;
        }
        int longestPalindrome = 1;
        string longestPalindromeStr = s.substr(0,1);
        vector<bool> tmp(len, false);
        vector<vector<bool>> dp(len, tmp);

        for(int r=1;r<len;r++){
            for(int l=0;l<r;l++){
                if(s.at(l) == s.at(r) && (r - l <= 2 || dp[l + 1][r - 1])){
                    dp[l][r] = true;
                    if (r - l + 1 > longestPalindrome) {
                        longestPalindrome = r - l + 1;
                        longestPalindromeStr = s.substr(l, r - l + 1);
                    }
                }
            }
        }

        return longestPalindromeStr;
    }
};
//========================================================================
class Solution53 {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int max_ending_here = nums[0];
        int res = nums[0];
        for (int i = 1;i<len;i++){
            max_ending_here = max(max_ending_here + nums[i], nums[i]);
            res = max(res, max_ending_here);
        }
        return res;

    }
};

int maxSubArray2(vector<int> &nums){
    int len = nums.size();
    int max_ending_here = nums[0];
    int res = nums[0];
    for (int i = 1;i<len;i++){
        max_ending_here = max(max_ending_here + nums[i], nums[i]);
        res = max(res, max_ending_here);
    }
    return res;
}

//========================================================================

class Solution70 {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
//        vector<int> dp(n,0);
//        dp[0] = 1;
//        dp[1] = 2;
        int pre1 = 2;
        int pre2 = 1;
//        int len = dp.size();
        int res = 0;
        for(int i = 3; i <= n;i++){
//            dp[i] = dp[i - 1] + dp[i - 2];
              res = pre1 + pre2;
              pre2 = pre1;
              pre1 = res;
        }
//        return dp[len-1];
        return res;
    }
};


class Solution08_01 {
public:
    int waysToStep(int n) {
        if(1 == n){
            return 1;
        } else if(2 == n){
            return 2;
        } else if(3 == n){
            return 4;
        }

        long pre3 = 1;
        long pre2 = 2;
        long pre1 = 4;

        long res = 0;
        for(int i = 4; i <= n;i++){
            res = (pre1 + pre2 + pre3) %1000000007;
            pre3 = pre2 %1000000007;
            pre2 = pre1 %1000000007;
            pre1 = res %1000000007;
        }
        return res;
    }
};


//============================================================================

int uniquePaths(int m, int n) {
    vector<int> dp_row(m,0);
    vector<vector<int>> dp(n, dp_row);
    for (int i=0;i<m;i++){
        dp[0][i] = 1;
    }
    for (int j=0;j<n;j++){
        dp[j][0] = 1;
    }
    if (m >=2 && n>=2){
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    return dp[n-1][m-1];
}

int uniquePaths2(int m, int n) {
    vector<int> dp(m,1);
    int tmp = 0;

    if (m <2 || n<2){
        return 1;
    }
    else{
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                tmp = dp[j] + dp[j-1];
                dp[j] = tmp;
            }
        }

    }

    return dp[m-1];
}
//================================================================================

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid.empty()||obstacleGrid[0][0]==1)
        return 0;
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    long ans[m][n];
    ans[0][0]=1;
    for(int i=1;i<n;i++)
    {
        if(obstacleGrid[0][i]!=1&&ans[0][i-1]==1)
            ans[0][i]=1;
        else
            ans[0][i]=0;
    }
    for(int i=1;i<m;i++)
    {
        if(obstacleGrid[i][0]!=1&&ans[i-1][0]==1)
            ans[i][0]=1;
        else
            ans[i][0]=0;
    }
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
        {
            if(obstacleGrid[i][j]!=1)
                ans[i][j]=ans[i-1][j]+ans[i][j-1];
            else
                ans[i][j]=0;
        }
    return ans[m-1][n-1];
}

//=====================================================================================
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans[m][n];
    ans[0][0] = grid[0][0];

    for (int i = 1;i<n;i++){
        ans[0][i] = ans[0][i-1] + grid[0][i];
    }
    for(int i=0;i<m;i++){
        ans[i][0] = ans[i-1][0] + grid[i][0];
    }

    for(int i =1;i<m;i++){
        for(int j =1;j<n;j++){
            int left = ans[i-1][j];
            int top = ans[i][j-1];
            if(left < top){
                ans[i][j] = left + grid[i][j];
            }
            else{
                ans[i][j] = top + grid[i][j];
            }
        }
    }
    return ans[m-1][n-1];

}

//=======================================================================================
int maxProfit(vector<int>& prices) {
    int min_v = prices[0];
    int len = prices.size();
    vector<int> dp(len, 0);
    dp[0] = 0;
    for(int i =1;i<len;i++){
        min_v = min(min_v, prices[i]);
        int tmp = prices[i] - min_v;
        if(dp[i-1] > tmp){
            dp[i] = dp[i-1];
        }else {
            dp[i] = tmp;
        }
    }
    return dp[len-1];
}

//=========================================================================================

#include <algorithm>
int minimumTotal(vector<vector<int>>& triangle) {
    int m = triangle.size();
    vector<vector<int>> dp;

    if(triangle.empty()){
        return 0;
    }
    if(1==m){
        return triangle[0][0];
    }

    for(int i=1;i<m;i++){
        for(int j=0;j<i+1;j++){
            if(0 == j){
                dp[i][j] = dp[i-1][j]+triangle[i][j];
            }
            else if (i == j){
                dp[i][j] = dp[i-1][j-1]+triangle[i][j];
            } else{
                dp[i][j] = min(dp[i-1][j-1]+triangle[i][j], dp[i-1][j]+triangle[i][j]);
            }
        }
    }


    auto smallest = std::min_element(std::begin(dp[m-1]), std::end(dp[m-1]));
    return *smallest;

}

//============================================================================================
bool wordBreak(string s, vector<string>& wordDict)
{
    vector<bool> dp(s.size() + 1);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

//=============================================================================================
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<TreeNode*> generateTrees(int n) {

}

int rob(vector<int>& nums) {
    if (nums.empty()){
        return 0;
    }
    int len = nums.size();
    if(1 == len){
        return nums[0];
    }
    if(2 == len){
        return max(nums[0], nums[1]);
    }

    vector<int> dp(len,0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i =2;i<len;i++){
        int pre1 = dp[i-1];
        int pre2 = dp[i-2] + nums[i];
        if(pre2 > pre1){
            dp[i] = dp[i-2] + nums[i];
        } else{
            dp[i] = dp[i-1];
        }

    }
    vector<int>::iterator p = max_element(dp.begin(), dp.end());
    return *p;
}


#include <limits.h>

int maxProduct(vector<int>& nums) {
    int max_value = INT_MIN, imax = 1, imin = 1;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] < 0){
            int tmp = imax;
            imax = imin;
            imin = tmp;
        }
        imax = max(imax*nums[i], nums[i]);
        imin = min(imin*nums[i], nums[i]);

        max_value = max(max_value, imax);
    }
    return max_value;

}

int rob2(vector<int>& nums) {
    if (nums.empty()){
        return 0;
    }
    int len = nums.size();
    if(1 == len){
        return nums[0];
    }
    if(2 == len){
        return max(nums[0], nums[1]);
    }

    vector<int> dp_no_first(len-1,0);
    vector<int> dp_no_last(len-1,0);

    dp_no_last[0] = nums[0];
    dp_no_last[1] = max(nums[0], nums[1]);
    for(int i =2;i<len-1;i++){
        int pre1 = dp_no_last[i-1];
        int pre2 = dp_no_last[i-2] + nums[i];
        if(pre2 > pre1){
            dp_no_last[i] = dp_no_last[i-2] + nums[i];
        } else{
            dp_no_last[i] = dp_no_last[i-1];
        }

    }

    dp_no_first[0] = nums[1];
    dp_no_first[1] = max(nums[1], nums[2]);
    for(int i =2;i<len-1;i++){
        int pre1 = dp_no_first[i-1];
        int pre2 = dp_no_first[i-2] + nums[i+1];
        if(pre2 > pre1){
            dp_no_first[i] = dp_no_first[i-2] + nums[i+1];
        } else{
            dp_no_first[i] = dp_no_first[i-1];
        }

    }

    vector<int>::iterator p_no_last = max_element(dp_no_last.begin(), dp_no_last.end());
    vector<int>::iterator p_no_first = max_element(dp_no_first.begin(), dp_no_first.end());
    return max(*p_no_last, *p_no_first);
}



class Solution42 {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int currMax = nums[0];

        for(int i = 1;i< nums.size();i++){
            if(currMax + nums[i] > nums[i]){
                currMax = currMax + nums[i];
            }else{
                currMax = nums[i];
            }

            if(currMax > res){
                res = currMax;
            }
        }

        return res;
    }
};

#include <algorithm>
#include <numeric>
class NumArray {
private:
    vector<int> _sum;
public:
    NumArray(vector<int>& nums) {
        _sum.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            _sum[i+1] = _sum[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return _sum[j+1] - _sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */


class Solution05 {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len <=1){
            return s;
        }
        int longestPalindrome = 1;
        string longestPalindromeStr = s.substr(0,1);
        vector<bool> tmp(len, false);
        vector<vector<bool>> dp(len, tmp);

        for(int r=1;r<len;r++){
            for(int l=0;l<r;l++){
                if(s.at(l) == s.at(r) && (r - l <= 2 || dp[l + 1][r - 1])){
                    dp[l][r] = true;
                    if (r - l + 1 > longestPalindrome) {
                        longestPalindrome = r - l + 1;
                        longestPalindromeStr = s.substr(l, r - l + 1);
                    }
                }
            }
        }

        return longestPalindromeStr;
    }
};


class Solution523 {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> sum(nums.size());
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            sum[i] = sum[i - 1] + nums[i];
        for (int start = 0; start < nums.size() - 1; start++) {
            for (int end = start + 1; end < nums.size(); end++) {
                int summ = sum[end] - sum[start] + nums[start];
                if (summ == k || (k != 0 && summ % k == 0))
                    return true;
            }
        }
        return false;
    }
};

