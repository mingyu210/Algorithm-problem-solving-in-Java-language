#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> arr[101];
bool visited[101][101];
int ans;
int row,col;

void dfs(int a, int b){
    visited[a][b] = true;
    ans += arr[a][b] - '0';
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    for(int i=0; i<4; i++){
        int x = a+dx[i];
        int y = b+dy[i];
        
        if(x >= 0 && y >= 0 && x < row && y < col && !visited[x][y] && arr[x][y] != 'X'){
            visited[x][y] = true;
            dfs(x,y);
        }
    }
}

vector<int> solution(vector<string> maps) {
    row = maps.size();
    col = maps[0].size();
    vector<int> answer;
    for(int i=0; i<101; i++){
        arr[i].clear();
        for(int j=0; j<101;j++){
            visited[i][j] = false;
        }
    }
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[i].size(); j++){
            arr[i].push_back(maps[i][j]);
        }
    }
    
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[i].size(); j++){
            ans = 0;
            if(!visited[i][j] && arr[i][j] != 'X'){
                dfs(i,j);   
                answer.push_back(ans);   
            }
        }
    }
    if(answer.empty()){
        answer.push_back(-1);
    }
    sort(answer.begin(),answer.end());
    return answer;
}