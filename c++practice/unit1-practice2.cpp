// 다양한 타입의 데이터 여러개를 인자로 입력받아 공통 타입으로 변환하는 함수
// 모든 인자를 공통 타입으로 변환하여 저장, 전체 원소를 빠르게 순회

#include <array>
#include <iostream>
#include <type_traits>

using namespace std;

template<typename ... Args>
array<?,?> build_Array(Args&&... args) -> array<typename common_type <Args ...>::type,?>
{
	using CommonType = typename common_type<Args ...>::type;
	return {forward<commonType>((Args&&)args)...};
}

int main()
{
	auto data = build_array(1,0u,'a',3.2f,false);

	for(auto i:data) cout << i <<"";

	cout<<endl;
}


