// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include <sstream>

using namespace std;
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

bool islarger(vector<int> row, int pivot)
{
    cout <<"ejejej";
  for(auto i:row){
    cout << "i = "<<i<<"pivot = "<<pivot <<endl;
    if(i<pivot) return false;
  }
 return true;
}

/*
i 번째 학생에 대하여, 열들 중 주어진 A[i] 원소보다 키가 전부 큰 열들이 있다면 그 열들 중 하나에 설 것
그런 열이 없다면 그 학생은 새로운 열을 만들것
리턴해야하는 것 --> 새로 만들어진 최소 열의 개수를 찾아라

이차원 배열 row vector 
A 의 원소들을 하나하나 돌면서 만약 해당 원소보다 row 마다 돌 때 작은 원소를 발견한다면 continue 큰 원소를 발견할 땐 count, 각 모든 row 에 해당 원소보다 작은 값이 존재한다면 새로 만들어야 하
세놓은 큰 원소들의 개수가 row[x].size 일 때 거기에 push
*/


int solution(vector<int> A)
{
  // Your solution goes here.
  vector < vector <int> > rows;
  vector <int> push_rows;
  int cnt = 0;
  int sig = 0;
  cout << "A.size() = "<<A.size() <<endl;
  for(int i=0;i<A.size();i++){
      cout<<"here\n";
    //rows[0] ~ rows[rows.size()-1] 각 원소들 중 A[i] 보다 작은 원소를 발견 시
    if(rows.size()!=0){
        for(int j=0;j<rows.size();j++){
            cout<<"here\n";
            if(!islarger(rows[j],A[i])) continue;
            else {
                rows.push_back(vector<int>());
                rows[j].push_back(A[i]);
                sig=1;
            }
        }
    }
    else{
        cnt+=1;
        rows.push_back(vector<int>());
        rows[0].push_back(A[i]);
    }

    if(sig == 0) cnt+=1;
    sig = 0;
  }
  return cnt; 
}

vector<int> toIntVector(string str)
{
  std::vector<int> out;
  std::string i;
  std::istringstream tokenStream(str);
  while (std::getline(tokenStream, i, ','))
  {
    out.push_back(atoi(i.c_str()));
  }
  return out;
}

int main()
{
  // Read in from stdin, solve the problem, and write answer to stdout.
  string AS;
  cin >> AS;
  vector<int> A = toIntVector(AS);
    // vector<int> test = {5,4,3,6,1};
    // cout<<"tt\n";
    cout << solution(A);
}