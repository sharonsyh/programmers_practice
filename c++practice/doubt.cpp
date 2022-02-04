#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

int main(){

    int T;
    cin >> T ;

    while(T--){
 
        int num,N,M;
        cin >> N ;
        vector<int> order;
        vector<int> answer;
        map<int,int> m;

        for(int i=0;i<N;i++){
            cin >> num ;
            m[num]+=1;
        }

        cin >> M ;

        for(int i=0;i<M;i++){
            cin >> num ;
            order.push_back(num);
            m[num]-=1;
        }

        for(auto j:order){

            if(m[j]==0){
                answer.push_back(1);
            }
            else{
                answer.push_back(0);
            }
        }

        for(auto j:answer){
            cout << j<<endl;
        }
    }
    return 0;
}