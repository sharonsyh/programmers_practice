#include <iostream>
#include <forward_list>
#include<vector>

using namespace std;

int main(){
	vector<string> vec = {"AB","CD","EF","HI","JK","LM","NO","PQ","RS"};

	auto it = vec.begin();
	cout<<"가장 최근 우승자"<<*it<<endl;

	it+=8;
	cout<<"8년 전 우승자:"<<*it<<endl;

	advance(it,-3);
	cout<<"그 후 3년 뒤 우승자:"<<*it<<endl;

	//forward_list 를 이용하여 위와 같은 기능 수행

	forward_list<string> fwd(vec.begin(),vec.end());

	auto it1 = fwd.begin();

	cout<<"가장 최근 우승자:"<<*it1<<endl;

	advance(it,5);
	cout<<"5년전 우승자:"<<*it1<<endl;

	//forward_list 는 순방향으로만 이동 가능하기 때문에 advace(it,-3) 과 같이 역방향으로 가는 코드는 에러가 난다.
	//forward_list 에서는 +=1 과 같은 operator 가 없기 때문에 사용 시 에러가 난다.




}

