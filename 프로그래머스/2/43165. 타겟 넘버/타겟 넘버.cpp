#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int start, int K, int target){
    if(K + numbers[start] == target && start == (numbers.size()-1)){
        answer++;
    }
    else if(K - numbers[start] == target && start == (numbers.size()-1)){
        answer++;
    }
    if(start+1 < numbers.size() ){
        dfs(numbers,start+1, K+numbers[start], target);
        dfs(numbers,start+1, K-numbers[start], target);
    }
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers,0,0,target);
    
    return answer;
}