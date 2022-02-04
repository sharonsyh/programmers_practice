#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int N) {
  cerr << "Tip: Use cerr to write debug messages on the output tab.";
  /*
  seperate the number of every digit
  use next permutation to find all permutations
  make it string and put digits together
  turn it into integer to fing the biggest num
  */
  
  vector <int> digits;
  vector <int> biggest;
  
  while(N != 0){
    
    digits.push_back(N%10);
    N /= 10;
    
  }
  
  sort(digits.begin(),digits.end());
  
  do{
    
    string find_num;
    
    for(int i=0;i<digits.size();i++){
      find_num+=to_string(digits[i]);
    }
    
    biggest.push_back(stoi(find_num));
    
  }while(next_permutation(digits.begin(),digits.end()));
  
  int biggest_number = 0;
  
  for(int i=0;i<biggest.size();i++){
    if(biggest[i]>biggest_number){
      biggest_number = biggest[i];
    }
  }
  
  return biggest_number;
  
  
  return 0;
}

int main(){
    cout<<solution(1356)<<endl;
}