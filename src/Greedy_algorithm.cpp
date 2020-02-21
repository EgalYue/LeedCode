//
// Created by yuehu on 2020/1/17.
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution122 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty() || prices.size() == 1){
            return 0;
        }

        int numSize = prices.size();
        if(numSize == 2){
            if(prices[1] > prices[0]){
                return prices[1] - prices[0];
            } else{
                return 0;
            }
        }


        vector<int> res(numSize, 0);
        res[0] = 0;
        res[1] = (prices[1] > prices[0]) ? (prices[1] - prices[0]) : 0;
        for(int i=2;i<prices.size();i++){
            if(prices[i] > prices[i-1]){
                res[i] = max(res[i-1] + prices[i] - prices[i-1], res[i-2] + prices[i] - prices[i-2]);
            } else{
                res[i] = res[i-1];
            }
        }
        return res[numSize - 1];
    }
};

#include<string>

class Solution392 {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0){
            return true;
        }
        int sub_len = s.size();
        int sub_n = 0;
        int all_len = t.size();
        for(int i =0;i<all_len;i++){
            if(s[sub_n] == t[i]){
                sub_n++;
            }

            if(sub_n == sub_len){
                return true;
            }
        }

        return false;
    }
};

#include <algorithm>
class Solution455 {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(),s.end());

        int g_n = 0;
        int s_n = 0;
        while(g_n < g.size() && s_n < s.size()){
            if(g[g_n] <= s[s_n]){
                g_n++;
            }
            s_n++;
        }

        return g_n;
    }
};