#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    /*
    commands 에 있는 vector i 부터 j 번째 array 를 새로운 vector 에 넣음
    새로운 vector 크기 준으로 정렬 후 k 번째 숫자를 answer vector 에 넣음
    */
    // cout<<commands.size()<<endl;

    for(int i=0;i<commands.size();i++){
        vector <int> list; //벡터 초기화
        // cout << "commands[i][0]-1 = "<<commands[i][0]-1<<endl;
        for(int j = commands[i][0]-1;j<=commands[i][1]-1;j++){
            // cout<<"array[j] = "<<array[j]<<endl;
            list.push_back(array[j]);
            // cout << array[j] <<endl;
        }
        // cout <<"\n";
        sort(list.begin(),list.end());
        answer.push_back(list[commands[i][2]-1]);
    
    }
    
    return answer;
}

int main(){
    vector<int> ans;
    ans = solution({1, 5, 2, 6, 3, 7, 4}, {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}});
    for(auto t:ans) cout<<t;
}