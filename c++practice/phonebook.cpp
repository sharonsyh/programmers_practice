#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int c;
    
    for(int i=0;i<phone_book.size();i++){
        for(int k=i+1;k<phone_book.size();k++){
            for(int j=0;j<phone_book[i].size();j++){
                
                if(phone_book[i].size() > phone_book[k].size()) break;
                
                if(phone_book[i][j]==phone_book[k][j]){
                    c+=1;
                }
            }
            if(c == phone_book[i].size()) return false;
            c = 0;
        }
    }
    return answer;
}

int main(){
    int result = solution({"119", "97674223", "1195524421"});
    
}