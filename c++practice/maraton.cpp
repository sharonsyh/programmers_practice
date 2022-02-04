#include <string>
#include <vector>
#include <cstring>
#include <algorithm> 
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int cnt;
    cout << completion.size() <<endl;
        
        for(auto i:participant){
            
            cnt = 0;
            cout <<"before [completion] ";
            for(auto t:completion){
                cout << t <<"/";
            } cout << endl;
            // for(auto t:participant) {
            //     cout << t <<".";
            // } cout << endl;
             
            for(auto j:completion){
                
                int res = i.compare(j);
                
                if(res == 0){
                    cout << i<<","<<j <<endl;
                    cout << completion.size() <<endl;
                    completion.erase(remove(completion.begin(), completion.end(), j), completion.end());
                    cout <<"after [completion] ";
                    for(auto t:completion) {
                        cout << t <<".";
                    }  cout <<endl;

                    cout << completion.size() <<endl;
                    cnt = 1;
                }
            }
            
            if(cnt !=1){
                answer = i;
                cout << "answer"<<answer<<endl;
                return answer;
            }
        }

            return answer;
        
    }

    int main(){
        cout << "answer = "<< solution(	{"marina", "josipa", "nikola", "nikola", "filipa"}, {"josipa", "filipa", "marina", "nikola"}) << endl;
        return 0 ;
    }