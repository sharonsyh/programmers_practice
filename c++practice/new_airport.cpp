#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

//Binary Search
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

//     vector <int> remaining ;
//     int time_spent = 0;
//     int num_of_remaining_people = n;
    
//     sort(times.begin(),times.end());

//     if( times.size() >= n ){
//         time_spent = times[times.size()-1];
//         answer = time_spent;
//     }
//     else{
        
//         for(int i=0;i<times.size();i++){
//             remaining.push_back(times[i]); 
//         }
//         num_of_remaining_people = num_of_remaining_people - times.size(); //6-2=4
//         int min_index,min,sec_min_index,sec_min ;
        
//         while(num_of_remaining_people!=0){
            
//             min_index = min_element(remaining.begin(), remaining.end()) - remaining.begin();
//             min = remaining[min_index];

//             for(int i=0;i<remaining.size();i++){
//                 remaining[i] = remaining[i]-min; // 7-7 10-7 // 7-3 3-3 // 1 0
//             }
//             time_spent += min;

//             remaining[min_index] = 1000000000;
//             sec_min_index = min_element(remaining.begin(), remaining.end()) - remaining.begin();
//             sec_min = remaining[sec_min_index];
//             remaining[min_index]=min;

//             if(times[min_index] > sec_min + times[sec_min_index]){
//                 remaining[sec_min_index]+=times[sec_min_index];
//             }

//             else{
//             // 남은 사람 중 한명 입국심사
//                 remaining[min_index] = times[min_index]; //7 3 // 4 0 
//             }

//             num_of_remaining_people-=1; //1 0
//         }
        
//         int max = *max_element(remaining.begin(), remaining.end()); //20
//         time_spent+=max;
//         answer = time_spent;
//     }
    
    /*
    
    * 모든 과정을 최소시간 <= 최대시간 인경우 반복
    
    - 시간을 최소시간 1분 최대시간 (가장오래걸리는창구시간)*n 으로 설정한 후
    - 평균 시간(mid) (최소+최대)/2 로 설정
    
    - 평균 시간동안 각 창구에서 심사할 수 있는 사람 수 구해서 people_sum 에 더함
    - people_sum < n 이면 시간이 추가적으로 걸리는 것 이므로 최소시간 = mid+1
    - people_sum >=n 이면 mid 보다 적게 걸리는 것이므로 최대시간 = mid-1
    - answer = mid
    
    */
    
    long mid,max,min = 1;
    long people_sum = 0;
    
    sort(times.begin(),times.end());
    
    max = *max_element(times.begin(), times.end()) * (long long)n;
    
    while( min <= max){
        
        mid = ((min+max)/2);
        
        for(auto t : times){
            people_sum += mid/t;
        }
        
        if(people_sum < n){
            min = mid+1;
        }
        else{
            max = mid-1;
            answer = mid;
        }
        
        people_sum = 0;
    }

    return answer;
}
