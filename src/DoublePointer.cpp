//
// Created by yuehu on 2020/2/21.
//
#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Solution26 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int len = nums.size();
        int i=0;
        for(int j=1;j<len;j++) {
            if(nums[j] != nums[i]){
                i=i+1;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};

class Solution27 {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()){
            return 0;
        }
        int len = nums.size();
        int i=0;
        for(int j=0;j<len;j++){
            if(nums[j] != val){
                nums[i] = nums[j];
                ++i;
            }
        }
        return i;

    }
};

#include <algorithm>
class Solution365 {
public:
    int strStr(string haystack, string needle) {

    }
};


class Solution350 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int l1 = nums1.size();
        int l2 = nums2.size();
//        int short_len = (l1 <= l2 ? l1:l2);
        int i=0;
        int j=0;
        while(i< l1 && j < l2){
            if(nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                i++;
                j++;
            } else if(nums1[i] > nums2[j]){
                j++;
            } else{
                i++;
            }
        }

        return res;
    }
};

class Solution844 {
public:

    void stringOP(string& input, char oneChar,int flag){
        if(flag == -1){
            if(input.size()!=0){
                input = input.substr(0, input.size()-1);
            }
        }else if(flag == 1){
            input = input + oneChar;
        }
    }

    bool backspaceCompare(string S, string T) {
        string S_res = "";
        for(int i=0;i<S.size();i++){
            if(S[i] == '#'){
                // S_res --
                stringOP(S_res, 'a', -1);
            }else{
                // S_res ++
                stringOP(S_res, S[i], 1);
            }
        }

        string T_res = "";
        for(int j=0;j<T.size();j++){
            if(T[j] == '#'){
                // T_res --
                stringOP(T_res, 'a', -1);
            }else{
                // T_res ++
                stringOP(T_res, T[j], 1);
            }
        }

        if(S_res == T_res){
            return true;
        }else{
            return false;
        }
    }
};