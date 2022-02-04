#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef pair<int, int> pr;

// bool operator<(pr a, pr b){ return a.second > b.second; }

int solution(vector<vector<int>> jobs) {
    
    int answer = 0;
    int num_of_jobs = jobs.size();
    vector<pr> jobs_in_process;
    int start_time = 0;
    int end_time = 0;
    int time = 0;
    
    priority_queue<pr, vector<pr>, greater<pr>> minHeap;

    minHeap.push(make_pair(jobs[0][1],jobs[0][0]));
    minHeap.push(make_pair(jobs[1][1],jobs[1][0]));
    minHeap.push(make_pair(jobs[2][1],jobs[2][0]));
    minHeap.push(make_pair(jobs[3][1],jobs[3][0]));

    while(!minHeap.empty()){

        //cout << minHeap.top().first <<endl;
        cout << minHeap.top().first <<endl;

        minHeap.pop();
    }
    
   return 0;
}

int main(){
    int result = solution({{0, 3}, {1, 9}, {2, 6},{3, 5}});
    cout << "result = "<< result<<endl;
}