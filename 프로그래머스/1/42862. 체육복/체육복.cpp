#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    vector<int> real_lost, real_reserve;

for (int l : lost) {
    if (find(reserve.begin(), reserve.end(), l) == reserve.end())
        real_lost.push_back(l);
}

for (int r : reserve) {
    if (find(lost.begin(), lost.end(), r) == lost.end())
        real_reserve.push_back(r);
}
    
    int i = 0;
    int j = 0;
    answer = n - real_lost.size();

sort(real_lost.begin(), real_lost.end());
sort(real_reserve.begin(), real_reserve.end());

while (i < real_lost.size() && j < real_reserve.size()) {
    if (abs(real_lost[i] - real_reserve[j]) == 1) {
        answer++;
        i++;
        j++;
    }
    else if (real_lost[i] > real_reserve[j]) j++;
    else i++;
}
   
    return answer;
}