#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
        sort(people.begin(),people.end(),compare);
        vector<pair<int,int> > res;
        for(int i = 0; i < people.size(); i++){
            res.insert(res.begin()+people[i].second,people[i]);
        }
        return res;
    }
    
    static bool compare(const pair<int,int> &a, const pair<int,int> &b){
        if(a.first == b.first)
            return a.second < b.second;
        else
            return a.first > b.first;
    }
};