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


#include <stack>
class Solution20 {
public:
    bool isValid(string s) {
        stack<char> record;

        for(int i=0;i<s.size();i++){
            if(record.empty()){
                record.push(s[i]);
            }
            else{
                char top_char = record.top();
                if(top_char == '(' && s[i] == ')'){
                    record.pop();
                } else if(top_char == '[' && s[i] == ']'){
                    record.pop();
                } else if (top_char == '{' && s[i] == '}'){
                    record.pop();
                } else{
                    record.push(s[i]);
                }
            }
        }
        if(record.empty()){
            return true;
        }else{
            return false;
        }
    }
};

class Solution58 {
public:
    int lengthOfLastWord(string s) {
        int result = 0, i = s.size() - 1;
        while(i >= 0 && s[i] == ' ') i--;
        while(i >= 0){
            if(s[i] == ' ') return result;
            else    result++;
            i--;
        }
        return result;
    }
};