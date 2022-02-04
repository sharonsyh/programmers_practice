#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

/*
주어진 숫자들을 next_permutation 돌리며 조합 만듬
string 으로 바꿔서 붙이고 int 로 다시 바꾼 후 vector 에 집어넣음
그 중 가장 큰 수
*/

string solution(vector<int> numbers) {
    string answer = "";
    vector<int> biggest;

    sort(numbers.begin(), numbers.end());

    do{

        string biggest_num;
        int biggest_number;

        for(int i=0; i< numbers.size(); i++){
            biggest_num+=to_string(numbers[i]);
		}
        
        biggest_number = stoi(biggest_num) ;
        biggest.push_back(biggest_number);

    }while(next_permutation(numbers.begin(),numbers.end()));

    int max = 0;

    for(int i=0;i<biggest.size();i++){
        // cout << biggest[i]<<endl;
        if(biggest[i]>max){
            max = biggest[i];
        }
    }

    stringstream ss;
    ss<<max;

    return ss.str();
}

int main(){
    vector<int> num = {6,10,2};
    cout << solution(num); 
}