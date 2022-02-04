#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    vector<int> compare;
    /*
    // 0 1 2 3 4
    // 0 1 3 5 6 
    // 3 4 5 6 7 

    //  i    cnt
        0 이상 5 citations.size - i = 5 citations[i] = 0 
        1 이상 4 citations.size - i = 4 citations[i] = 1 
        2 이상 3 citations.size - i = 3 citations[i] = 3 
        3 이상 3 citations.size - i = 2 citations[i] = 5 
        4 이상 2 citations.size - i = 1 citations[i] = 6
        
              

    
    */
    double t;
    int cnt = 0;
    // 0 1 3 5 6 9
    
    
    
    sort(citations.begin(),citations.end());
    int avg = 0;
    
//     for(int i=0;i<citations.size();i++){
//         compare.push_back(i+1);
//     }
    
    for(int i=0;i<citations.size();i++){
        if(citations[i]>=citations.size()-i){
            return citations.size()-i;
        }
    }
    
    return answer;
}

int main(){
    vector<int> num = {3, 4, 6, 7, 5};
    cout << solution(num); 
}