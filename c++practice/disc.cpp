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

    // cout << "num_of_jobs = "<< num_of_jobs<<endl;
    
    priority_queue<pr, vector<pr>, greater<pr>> minHeap;

    // cout << "jobs[0][0] = " << jobs[0][0]<<", jobs[0][1] = " <<jobs[0][1] <<endl;

    jobs_in_process.push_back(make_pair(jobs[0][1],jobs[0][0])); // 첫번쨰 작업 시작
    start_time = 0; 
    end_time = jobs[0][1];
    jobs.erase(jobs.begin());

    // cout << "jobs[0][0] = " << jobs[0][0]<<", jobs[0][1] = " <<jobs[0][1];

    int i=0;
    
    while(1){

        cout<<"여긴?"<<endl;

        if(minHeap.empty()&&jobs_in_process.empty()){
            break;
        }

        pr in_process_;
        in_process_ = jobs_in_process.front();
        //1
        if(time < in_process_.second) { // 2초인 시점에 3초에 들어오는 요청을 처리할 필요 없음
            time+=1;
            // cout << "time = "<< time<<endl;
            continue;
        }

        int request;
        int timecost;
        

        if(!jobs.empty()){
        
            request = jobs[0][0];
            timecost = jobs[0][1];
            // jobs.erase(jobs.begin());
            
            // cout << "jobs size = "<< jobs.size()<<endl;
        }
        int i=0;
        if((!jobs_in_process.empty())||(!minHeap.empty())){ // 현재 대기 중인 요청이 있거나 진행 중인 요청이 있을 때
            
            cout << "push  ";
            minHeap.push(make_pair(timecost,request));
            if(!jobs.empty()) jobs.erase(jobs.begin());
            
        }
        else{ //현재 대기 중인 요청 혹은 진행 중인 요청이 없어서 바로 시작할 수 있을 때 또는 이미 진행중
            jobs_in_process.push_back(make_pair(timecost,request)); 
            if(!jobs.empty()) jobs.erase(jobs.begin());
            start_time = request; 
            end_time = request + timecost;
            answer += timecost ;
        }
        time+=1;
        cout<<"여기까진 ok"<<endl;
        pr in_process;
        in_process = jobs_in_process.front();
        
        if(time == end_time){
            
            answer += (start_time - in_process.second + in_process.first);
            jobs_in_process.erase(jobs_in_process.begin());
            
            if(!minHeap.empty()){

                cout << "현재 시간 = "<< time<<endl;
                
                pr process;
                process = minHeap.top();

                minHeap.pop();

                cout << "minHeap size = " <<minHeap.size()<<endl;

                cout << "process.first,process.second = " << process.first<<","<<process.second<<endl;
                
                jobs_in_process.push_back(make_pair(process.first,process.second)); //timecost , request
                
                start_time = end_time;
                end_time = start_time + in_process.first;
            
                // cout << "1start_time = "<< start_time<<endl;
                // cout << "1end_time = "<< end_time<<endl;
            }
            else{
                break;
                //cout << "answer = "<< answer<<endl;
                // return (answer/num_of_jobs);
            }
        }
    }    
    return (answer);
}

int main(){ // 3 + 6 + (3-2) + 8 + (9-3) + 9 + (17-1) --> 3 10 24 49
    int result = solution({{0, 3}, {1, 9}, {2, 6},{3, 8}}); //요청시간,소요시간
    cout << "result = "<< result<<endl;// 3 9 17 26
}