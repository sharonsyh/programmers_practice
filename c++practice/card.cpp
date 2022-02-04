#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int N,K;
vector <string> num;
// int num;

// int permutation(int k){

//     if(k == K){

//     }
//     else{

//     }

//     return 0;
// }

int main(){
    
    cin >> N >> K;

    string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		num.push_back(s);
	}

    cout << s ;
    // do {
    //     for (auto it = s.begin(); it != s.end(); ++it)
    //         cout << *it << ' ';
    //     cout << endl;
    // } while (next_permutation(s.begin(), s.end()));

    return 0;
}