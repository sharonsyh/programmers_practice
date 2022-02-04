#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){

    set <string> m;
    vector<string> names;
    vector<string> answer;
    int cnt = 0;
    int N;

    string name;
    string entrance;

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> name >> entrance;
        if(entrance == "enter") m.insert(name);
        else if(entrance == "leave") m.erase(name);
        else {}
    }

    for( set< string >::reverse_iterator r = m.rbegin(); r != m.rend(); ++r )
	{
		cout << *r << "\n";
	}

    return 0;
}