#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> arr[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i=0; i<20001; i++){
        arr[i].clear();
    }
    for(int i=0; i<edge.size(); i++){
        arr[edge[i][0]].push_back(edge[i][1]);
        arr[edge[i][1]].push_back(edge[i][0]);
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    vector<int> dist(n+1,1e9);
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int end = pq.top().second;
        pq.pop();
        
        if(dist[end] < cost){
            continue;
        }
        
        for(int u : arr[end]){
            if(dist[u] > cost+1){
                dist[u] = cost+1;
                pq.push({cost+1,u});
            }
        }
    }
    
    int ans = 0;
    
    for(int i=2; i<n+1; i++){
        if(ans < dist[i]){
            ans = dist[i];
            answer = 1;
        }
        else if(ans == dist[i]){
            answer++;
        }
    }
    
    return answer;
}