//
// Created by yuehu on 2020/4/28.
//

#include <vector>
#include <unordered_map>

using namespace std;

class Solution01 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> record;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int tmp=target-nums[i];
            if(record.find(tmp)!=record.end()){
                res.push_back(i);
                res.push_back(record[tmp]);
                break;
            }else
                record[nums[i]]=i;
        }
        return res;
    }
};

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
class Solution561 {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0;i< nums.size();i++){
            if(i % 2 == 0){
                sum = sum + nums[i];
            }
        }
        return sum;
    }
};


class Solution88 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        while(i< n){
            nums1[m+i] = nums2[i];
        }
        std::sort(nums1.begin(), nums1.end());

    }
};


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

        return j- i+1;

    }
};

#include <set>
class Solution217 {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        if(nums.size() != st.size()){
            return true;
        } else{
            return false;
        }
    }
};


class Solution1089 {
public:
    void duplicateZeros(vector<int>& arr) {

        int size = arr.size();
        int offset = 0;

        // 第一次遍历，计算数组中0的个数
        for (int i=0; i<size; i++) {
            if (!arr[i]) offset++;
        }

        // 第二次遍历，从后向前按偏移量移动元素
        for (int i=size-1; i>-1; i--) {
            if (!arr[i]) {
                offset--;
                if (i+offset < size) arr[i+offset] = 0;
                if (i+offset+1 < size) arr[i+offset+1] = 0;
            }
            else if (i+offset < size) arr[i+offset] = arr[i];
        }
    }
};

