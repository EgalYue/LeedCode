//
// Created by yuehu on 2020/1/14.
//
#include<vector>
#include<string>

using namespace std;

class Solution01 {
public:

    int findLeft(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size();

        while(left < right){
            int middle = (left + right) / 2 ;

            if(nums[middle] == target){
                right = middle;
            } else if(nums[middle] > target){
                right = middle;
            } else if (nums[middle] < target){
                left = middle + 1;
            }
        }

        if(left == nums.size()){
            return -1;
        }
        return nums[left] == target? left: -1;

    }

    int findRight(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size();

        while(left < right){
            int middle = (left + right) / 2 ;

            if(nums[middle] == target){
                left = middle + 1;
            } else if(nums[middle] > target){
                right = middle;
            } else if (nums[middle] < target){
                left = middle + 1;
            }
        }

        if(left == 0){
            return -1;
        }
        return nums[left - 1] == target? left - 1: -1;
        }



    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findLeft(nums, target);
        int right = findRight(nums, target);

        vector<int> res;
        res.push_back(left);
        res.push_back(right);
        return res;
    }
};

//=========================================================================

class Solution02 {
// TODO: Problem
public:

    int findRotationIndex(vector<int>& nums, int left, int right){
        if(nums[left] < nums[right-1]){
            return 0;
        }

        while(left < right){
            int middle = (left + right) / 2;


            if(nums[middle] > nums[middle + 1]){
                return middle + 1;

            } else if(nums[middle] > nums[left]){
                left = middle + 1;
            } else if(nums[middle] < nums[left]){
                right = middle;
            }
        }
        return 0;
    }

    int findTarget(vector<int>& nums, int target, int left, int right){

        while(left < right){

            int middle = (left + right) / 2;

            if(target == nums[middle]){
                return middle;
            } else if(nums[middle] > target){
                right = middle;
            } else if(nums[middle] < target){
                left = middle + 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if(nums.empty()){
            return -1;
        }
        int left = 0;
        int right = nums.size();
        int index = findRotationIndex(nums, left, right);
        if(index == 0){
            return findTarget(nums, target, left, right);

        } else{
            if(target > nums[right - 1]){
                return findTarget(nums, target, left, index);
            } else{
                return findTarget(nums, target, index, right);
            }
        }
    }
};


/*
 *
 * public class Solution {

    public int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        // 注意：针对特殊测试用例，例如 2147395599
        // 要把搜索的范围设置成长整型
        long left = 1;
        long right = x / 2;
        while (left < right) {
            // 注意：这里一定取右中位数，如果取左中位数，代码会进入死循环
            // long mid = left + (right - left + 1) / 2;
            long mid = (left + right + 1) >>> 1;
            long square = mid * mid;
            if (square > x) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        // 因为一定存在，因此无需后处理
        return (int) left;
    }

}

作者：liweiwei1419
链接：https://leetcode-cn.com/problems/sqrtx/solution/er-fen-cha-zhao-niu-dun-fa-python-dai-ma-by-liweiw/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

class Solution69 {
public:
    int mySqrt(int x) {
        if (x == 0){
            return 0;
        }

        long left = 1;
        long right = x / 2;
        while(left < right){
            long mid = (left + right + 1)/2;
            long square = mid * mid;
            if(square > x){
                right = mid -1;
            } else{
                left = mid;
            }
        }
        return (int)left;

    }
};
//=======================================================================
class Solution33 {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()){
            return -1;
        }
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                return mid;
            }

            if(nums[mid] < nums[right]){ // right side
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                } else{
                    right = mid - 1;
                }
            } else{ // left side
                if(nums[left] <= target && target < nums[mid]){
                    right = mid -1;
                } else{
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};

//==============================================================================

class Solution35 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while(left < right){
            int mid = (left + right)/2;

            if(nums[mid] == target){
                return mid;
            } else if (nums[mid] < target){
                left = mid + 1;
            } else if (nums[mid] > target){
                right = mid;
            }
        }

        return left;

    }
};

#include <map>
class Solution167 { // Brute-force search
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int numSize = numbers.size();
        for(int i = 0;i<numSize;i++){
            for(int j = i+1;j<numSize;j++){
                if(numbers[i] + numbers[j] == target){
                    res.push_back(i);
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};

class Solution167_2 { // Double pointer
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left = 0;
        int right = numbers.size()-1;
        while(left < right){
            if(numbers[left] + numbers[right] > target){
                --right;
            } else if (numbers[left] + numbers[right] < target){
                ++left;
            } else{
                res.push_back(left);
                res.push_back(right);
            }

        }
        return res;
    }
};

class Solution167_3 { // Binary search
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int tmp,left,right,mid;
        for(int i=0;i<numbers.size()-1;i++){
            tmp=target-numbers[i];
            left=i+1,right=numbers.size()-1;
            while(left<=right){
                mid=left+(right-left)/2;
                if(numbers[mid]==tmp){
                    res.emplace_back(i+1);
                    res.emplace_back(mid+1);
                    break;
                }
                else if(numbers[mid]<tmp) left=mid+1;
                else right=mid-1;
            }
        }
        return res;
    }
};

#include <unordered_map>
class Solution167_4 { // Map
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mp;
        vector<int> res;
        int tmp=target-numbers[0],i=0;
        if(tmp<0) return res;
        for(;i<numbers.size();i++){
            if(numbers[i]>tmp) break;
            mp[numbers[i]]=i;
        }
        for(int j=0;j<i;j++){
            if(mp.count(target-numbers[j])&&mp[target-numbers[j]]!=j){
                res.emplace_back(j+1);
                res.emplace_back(mp[target-numbers[j]]+1);
                break;
            }
        }
        return res;
    }
};

//===============================================================================
#include <algorithm>
class Solution349 {
public:

    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while(left < right){
            int mid = (left + right)/2;

            if(nums[mid] == target){
                return true;
            } else if (nums[mid] < target){
                left = mid + 1;
            } else if (nums[mid] > target){
                right = mid;
            }
        }

        return false;

    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(),nums1.end());
        vector<int> res;
        for (auto x:nums2){
            vector<int>::iterator iter=std::find(res.begin(),res.end(),x);
            if (searchInsert(nums1, x) && iter ==res.end()){
                res.push_back(x);
            }
        }
        return res;
    }
};

//===========================================================
using namespace std;

#include <algorithm>
#include<limits.h>
class Solution04 {
public:

    int findKth(vector<int>& nums1, vector<int>& nums2, int k){
//        if( k <= 1 || k > nums1.size() + nums2.size()){
//            return NULL;
//        }
          int ri = std::min(k, (int)nums1.size());
          int le = std::max(0, (int)(k - nums2.size()));
          while(le < ri){
              int mid = (le + ri)/2;
              if(nums2[k-mid-1] > nums1[mid]){
                  le = mid + 1;
              } else{
                  ri = mid;
              }
          }

        int nums1LeftMax=le==0?INT_MIN:nums1[le-1];
        int nums2LeftMax=le==k?INT_MIN:nums2[k-le-1];
        return max(nums1LeftMax,nums2LeftMax);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int lengthSum = nums1.size() + nums2.size();
        if (lengthSum % 2 == 1){
            return findKth(nums1, nums2, (lengthSum >> 1) + 1);
        } else{
            int Kth = findKth(nums1, nums2, (lengthSum >> 1));
            int Kth_next = findKth(nums1, nums2, (lengthSum >> 1) + 1);
            return (double)(Kth + Kth_next)/2;
        }
    }
};

//===============================================================

class Solution50 {
public:
    double myPow(double x, int n) {
        if (0 == n){
            return 1;
        }
        if(1 == n){
            return x;
        }
        if(-1 == n){
            return 1/x;
        }

        double half = myPow(x, n/2);
        double rest = myPow(x, n % 2);
        return rest * half * half;
    }
};

//===============================================================

class Solution74 {
public:
    int search(vector<int> nums, int target){
        if(nums.empty()){
            return -1;
        }

        int left = 0;
        int right = nums.size();

        while(left < right){
            int mid = (left + right)/2;

            if(nums[mid] == target){
                return mid;
            } else if (nums[mid] < target){
                left = mid + 1;
            } else if (nums[mid] > target){
                right = mid;
            }
        }

        return left-1;

    }

    bool searchInsert(vector<int>& nums, int target) {

        if(nums.empty()){
            return false;
        }

        int left = 0;
        int right = nums.size();

        while(left < right){
            int mid = (left + right)/2;

            if(nums[mid] == target){
                return true;
            } else if (nums[mid] < target){
                left = mid + 1;
            } else if (nums[mid] > target){
                right = mid;
            }
        }

        return false;

    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }

        int row =  matrix.size();
        int col = matrix[0].size();
        vector<int> firstCol;
        for(int i=0;i<row;i++){
            firstCol.push_back(matrix[i][0]);
        }
        int row_pos = search(firstCol, target);
        if(row_pos == -1){
            return false;
        } else{
            return searchInsert(matrix[row_pos], target);
        }
    }
};