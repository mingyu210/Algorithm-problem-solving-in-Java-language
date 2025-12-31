#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> arr;
    
    for(int i=0; i<s.size();i++){
        if(arr.empty()){
            arr.push(s[i]);
        }
        else if(arr.top() == '(' && s[i] == ')'){
            arr.pop();
        }
        else{
            arr.push(s[i]);
        }
    }
    if(!arr.empty()){
        answer = false;
    }
    
    return answer;
}