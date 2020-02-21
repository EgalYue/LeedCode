//
// Created by yuehu on 2020/2/18.
//
#include<vector>
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


class Solution136 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> record;
        for(auto num : nums){
            if (record.find(num) != record.end()){
                record.erase(num);
            } else{
                record[num] = 1;
            }
        }
        unordered_map<int,int>::iterator it = record.begin();
        return it->first;
    }
};

class Solution136_2 {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto num:nums){
            res = num ^ res;
        }
        return res;
    }
};


class Solution202 {
public:
    int cal_square(int input){
        int rest = 0;
        int temp = input;
        int sum = 0;
        while (temp != 0){
            rest = temp % 10;
            temp = temp / 10;
            sum = sum + rest*rest;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_map<int, int> record;
        int temp = 0;
        record[n] = 1;
        while(true){
            temp = cal_square(n);
            if (temp == 1){
                return true;
            }
            if(record.find(temp) != record.end()){
                return false;
            } else{
                record[temp] = 1;
            }
        }
    }
};


class Solution204 {
public:

int countPrimes(int n) {
    int count = 0;
    //初始默认所有数为质数
    vector<bool> signs(n, true);
    for (int i = 2; i < n; i++) {
        if (signs[i]) {
            count++;
            for (int j = i + i; j < n; j += i) {
                //排除不是质数的数
                signs[j] = false;
            }
        }
    }
    return count;
}
};

#include <string>
class Solution205 {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> record_st;
        unordered_map<char, char> record_ts;

        int len = s.size();
        for(int i=0;i<len;i++){
            char s_one = s[i];
            char t_one = t[i];
            if(record_ts.find(t_one) == record_ts.end()){
                record_ts[t_one] = s_one;
            }else{
                if(record_ts[t_one] != s_one){
                    return false;
                }
            }

            if(record_st.find(s_one) == record_st.end()){
                record_st[s_one] = t_one;
            }else{
                if(record_st[s_one] != t_one){
                    return false;
                }
            }

        }
        return true;
    }
};


