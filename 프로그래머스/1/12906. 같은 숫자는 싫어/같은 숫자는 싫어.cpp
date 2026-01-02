#include <iostream>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> brr;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    for(int i=0; i<arr.size(); i++){
        if(brr.empty()){
            brr.push(arr[i]);
        }
        else if(brr.top() == arr[i]){
            continue;
        }
        else{
            brr.push(arr[i]);
        }
    }
    while(!brr.empty()){
        int k = brr.top();
        brr.pop();
        answer.push_back(k);
    }
    reverse(answer.begin(), answer.end());

    return answer;
}