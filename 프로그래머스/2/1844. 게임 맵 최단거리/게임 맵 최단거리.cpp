#include <vector>
#include <queue>
#include <tuple>
using namespace std;

bool visited[101][101];
queue<tuple<int,int,int>> q;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    while(!q.empty()){
        q.pop();
    }
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            visited[i][j] = 0;
        }
    }
    visited[0][0] = true;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    q.push({0,0,1});
    
    while(!q.empty()){
        int x, y, cost;
        tie(x, y, cost) = q.front();
        
        if(x == maps.size()-1 && y == maps[maps.size()-1].size()-1){
            answer = cost;
            break;
        }
        q.pop();
        
        for(int i=0; i<4; i++){
            int newX = x+dx[i];
            int newY = y+dy[i];
            if(newX>=0 && newX < maps.size() && newY>=0 && newY < maps[newX].size() && !visited[newX][newY]
              && maps[newX][newY] == 1){
                visited[newX][newY] = true;
                q.push({newX,newY,cost+1});
            }
        }
    }
    
    if(answer == 0){
        answer = -1;
    }
    return answer;
}