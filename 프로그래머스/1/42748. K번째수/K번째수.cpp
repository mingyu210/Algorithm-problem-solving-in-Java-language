#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0; i<commands.size(); i++){
        int a = commands[i][0];
        int b = commands[i][1];
        int c = commands[i][2];
        vector<int> line;
        for(int j=a-1; j<b; j++){
            line.push_back(array[j]);
        }
        sort(line.begin(),line.end());
        answer.push_back(line[c-1]);
    }
    return answer;
}