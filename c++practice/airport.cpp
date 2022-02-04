#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*

times 정렬

만약 심사관 개수 >= n 이면 times[0] - times[n] 까지 더한 수 리턴
만약 심사관 개수 < n 이면
    우선 심사관 개수만큼 사람이 들어감 
    남은 사람 수 = n - 심사관 개수
    남은 시간 vector 를 만들어 times[0] - times[n] 까지 넣고
    
    while (남은 사람 수 !=0) {
    
        남은 시간 vector 에서 가장 작은 수를 찾고 전체에서 뺌
        소요 시간에 가장 작은 수 더함
        가장 작은 수의 index 에 기다리고 있던 새로운 사람 추가 --> 남은 시간에 times[i] 다시 더함, 남은 사람 수-=1;
    
    }
    
    남은 사람 수가 더이상 없다면 남은 시간 vector 중 가장 큰 값을 소요시간에 더함
    return 소요시간 

*/

long long solution(int n, vector<int> times) {
    
    long long answer = 0;

    vector <int> remaining ;
    int time_spent = 0;
    int num_of_remaining_people = n;
    
    sort(times.begin(),times.end());

   
    
    if( times.size() >= n ){
        time_spent = times[times.size()-1];
        answer = time_spent;
       // cout<<time_spent<<endl;
        //return time_spent;
    }
    else{
        
        //time_spent = *max_element(times.begin(), times.end()); //10

        for(int i=0;i<times.size();i++){
            remaining.push_back(times[i]); 
        }
        num_of_remaining_people = num_of_remaining_people - times.size(); //6-2=4
        int min_index,min,sec_min_index,sec_min ;
        
        while(num_of_remaining_people!=0){
            
            min_index = min_element(remaining.begin(), remaining.end()) - remaining.begin();
            min = remaining[min_index];

            for(int i=0;i<remaining.size();i++){
                //cout <<remaining[i]<<endl;

                remaining[i] = remaining[i]-min; // 7-7 10-7 // 7-3 3-3 // 1 0
                //cout <<"remaining[min_index] = "<<min<<endl;
                //cout << "remaining["<<i<<"] = " <<remaining[i] <<endl;

            }
            time_spent += min;

            remaining[min_index] = 1000000000;
            sec_min_index = min_element(remaining.begin(), remaining.end()) - remaining.begin();
            sec_min = remaining[sec_min_index];
            remaining[min_index]=min;

            //cout <<"sec_min = "<<sec_min<<", min = "<<min<<endl; //1 6
            //cout <<" 0 time_spent = "<<time_spent<<endl;

            if(times[min_index] > sec_min + times[sec_min_index]){
                //cout <<"here"<<endl;
                //time_spent+=sec_min;
                remaining[sec_min_index]+=times[sec_min_index];
                //min = times[sec_min_index];
                 
            }

            else{
            
            // 남은 사람 중 한명 입국심사
                remaining[min_index] = times[min_index]; //7 3 // 4 0 
            }

            //time_spent += min;//+7 = 7 +3 = 10
            //cout << "time_spent = "<<time_spent<<endl; 
            num_of_remaining_people-=1; //1 0
        }
        
        int max = *max_element(remaining.begin(), remaining.end()); //20
        time_spent+=max;
        answer = time_spent;
    }
     

    return answer;
} 

int main(){
    vector<int> num = {1,2,3};
    cout << solution(3,num); 
    /*
    7 10 2 10
    0  3 2 10
    7  3 1  10
    7 3  1 24
    4 10 0 27
    
    4 0 4+7 10

    가장 첫 두 사람은 바로 심사를 받으러 갑니다.

    7분이 되었을 때, 첫 번째 심사대가 비고 3번째 사람이 심사를 받습니다.

    10분이 되었을 때, 두 번째 심사대가 비고 4번째 사람이 심사를 받습니다.

    14분이 되었을 때, 첫 번째 심사대가 비고 5번째 사람이 심사를 받습니다.

    20분이 되었을 때, 두 번째 심사대가 비지만 6번째 사람이 그곳에서 심사를 받지 않고 1분을 더 기다린 후에 첫 번째 심사대에서 심사를 받으면 28분에 모든 사람의 심사가 끝납니다.


    */ 
}