#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int a, int b, vector<vector<string>> park){
    int t =1;
    while(1){
        for(int i=a; i<a+t; i++){
            for(int j=b; j<b+t; j++){
                if(i >= park.size() || j >= park[i].size()){
                    return t-1;
                }
                if(park[i][j] != "-1"){
                    return t-1;
                }
            }
        }
        t++;
    }
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    int ans = 0;
    sort(mats.begin(), mats.end(), greater<int>());
    for(int i=0; i<park.size(); i++){
        for(int j=0; j<park[i].size(); j++){
            int k = solve(i,j,park);
            if(k >ans){
                ans = k;
            }
        }
    }
    for(int i=0; i<mats.size(); i++){
        if(mats[i] <= ans){
            answer = mats[i];
            break;
        }
    }
    if(answer == 0){
        answer = -1;
    }
    return answer;
}