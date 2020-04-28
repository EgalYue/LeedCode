//
// Created by yuehu on 2020/2/28.
//
#include <vector>
#include <string>
using namespace std;

#include <map>
class Solution169 {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        map<int, int> record;
        for(auto one:nums){
            if(record.find(one) != record.end()){
                record[one]++;
            }else{
                record[one] = 1;
            }
        }

        map<int,int>::iterator record_iter = record.begin();
        int res = 0;
        while(record_iter != record.end()) {
            if (record_iter->second > len / 2) {
                res = record_iter->first;
                break;
            }
            record_iter++;
        }
        return res;
    }
};


class Solution191 {
public:
    int hammingWeight(uint32_t n) {
            int count = 0;

            while(n > 0)
            {
                n &= (n - 1);
                ++count;
            }

            return count;
    }
};


class Solution190 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i=0;i<32;i++){
            res = res<<1 | (n & 1);
            n = n>>1;
        }
        return res;
    }
};


class Solution231 {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0){
            return false;
        }

        while(n!=0){
            if(n == 1){
                return true;
            }
            int rest = n % 2;
            if(rest != 0){
                return false;
            }
            n = n / 2;
        }
        return true;
    }
};


class Solution342 {
public:
    bool isPowerOfFour(int n) {
        if(n == 0){
            return false;
        }

        while(n!=0){
            if(n == 1){
                return true;
            }
            int rest = n % 4;
            if(rest != 0){
                return false;
            }
            n = n / 4;
        }
        return true;

    }
};