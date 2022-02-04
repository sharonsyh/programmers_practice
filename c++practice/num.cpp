#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std; 

int solution(vector<int> A) {
  cerr << "Tip: Use cerr to write debug messages on the output tab.";
  string temp;

  for(int i=0;i<A.size();i++){
    int count_num = count(A.begin(), A.end(),A[i]);

    if(count_num>1){

      temp = to_string(A[i]);
      reverse(temp.begin(), temp.end());
      auto find_num = find(A.begin(), A.end(), atoi(temp.c_str()));

      if(find_num==A.end()){
        A.push_back(atoi(temp.c_str()));
        A[i] = atoi(temp.c_str());
      }

    }
  }

  set<int> s;
  for(int i=0;i<A.size();i++){
    s.insert(A[i]);
  }

  return s.size();
}
