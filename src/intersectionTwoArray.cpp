//
// Created by yuehu on 19-8-7.
//
#include <vector>
#include <set>

using namespace std;
vector<int> intersection(const vector<int> &v1, const vector<int> &v2){
    set<int> s1;
    for(int i=0;i<v1.size();i++){
        s1.insert(v1[i]);
    }
    set<int> resSet;
    for(int j=1;j<v2.size();j++){
        if(s1.find(v2[j]) != s1.end()){
            resSet.insert(v2[j]);
        }
    }
    vector<int> resVec;
    for(set<int>::iterator iter=resSet.begin(); iter != resSet.end(); iter++){
        resVec.push_back(*iter);
    }

    return resVec;
}


#include <vector>
#include <map>
using namespace std;

vector<int> intersection2(const vector<int> &v1, const vector<int> &v2){
    map<int, int> record;
    for(int i : v1){
        record[i] += 1;
    }
    vector<int> resVec;
    for(int j : v2){
        if(record[j] > 0){
            resVec.push_back(j);
            record[j] --;
        }
    }

    return resVec;
}