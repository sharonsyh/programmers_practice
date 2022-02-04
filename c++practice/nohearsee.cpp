#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

int main(){

    int N,M;
    cin >> N >> M ;
    string name;
    map<string,int> m;
    vector<string> answer;
    int cnt = 0;

    for(int i=0;i<N;i++){
        cin >> name ; 
        m[name]+=1;
    }

    for(int i=0;i<M;i++){
        cin >> name ; 
        m[name]-=1;

        if(m[name]==0) {
            answer.push_back(name);
            cnt +=1;
        }
    }

    // cout << cnt <<endl;
    printf("%d\n", cnt);

    for(auto j:answer){
        cout << j<<endl;
    }
    return 0;
}