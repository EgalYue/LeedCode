//
// Created by yuehu on 2020/2/25.
//

#include <string>
#include <iostream>
using namespace std;

#include<unordered_map>
class Solution13 {
public:
    int romanToInt(string s) {
        unordered_map<string, int> record;
        record["IV"] = 4;
        record["IX"] = 9;
        record["XL"] = 40;
        record["XC"] = 90;
        record["CD"] = 400;
        record["CM"] = 900;
        record["I"] = 1;
        record["V"] = 5;
        record["X"] = 10;
        record["L"] = 50;
        record["C"] = 100;
        record["D"] = 500;
        record["M"] = 1000;

        int i =0;
        int len = s.size();
        int sum = 0;
        while(i < len){
            if((i+1 < len) && (record.find(s.substr(i,2)) != record.end())){
                sum = sum + record[s.substr(i,2)];
                i = i + 2;
            }else{
                sum = sum + record[s.substr(i,1)];
                i++;
            }
        }
        return sum;
    }
};