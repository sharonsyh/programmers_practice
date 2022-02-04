// 기본적인 사용자 컨테이너 만들기
//forward_list 와 유사하지만 더 많은 기능을 제공하는 컨테이너

#include<iostream>
#include <algorithm>

using namespace std;

struct single_ll_node
{
	int data;
	single_ll_node* next;
};

class single_ll
{
	public:
		using node = single_ll_node;
		using node_ptr = node*;

	private:
		node_ptr head;
	
	public:
		void push_front (int val)
		{
			auto new_node = new node{val,NULL};

			if(head!=NULL)new_node->next = head;
			head = new_node;

		}

		void pop_front()
		{
			auto first = head;
			if(head)
			{	
				head = head->next;
				delete first;
			}
		}

	struct single_ll_iterator
	{

	private:
		node_ptr ptr;
	public:
		single_ll_iterator(node_ptr p):ptr(p){}

		int& operator*() {return ptr->data;}
		node_ptr get(){return ptr;}

		single_ll_iterator &operator++()
		{
			ptr = ptr->next;
			return *this;
		}

		single_ll_iterator &operator++(int)
		{	
			single_ll_iterator result = *this;
			++(*this);
			return result;
		}

		friend bool operator == (const single_ll_iterator& left,const single_ll_iterator& right)
		{	
			return left.ptr == right.ptr;
		}

		friend bool operator != (const single_ll_iterator& left,const single_ll_iterator& right)
        {
            return left.ptr != right.ptr;
        }
	};

	single_ll_iterator begin() {return singe_ll_iterator(head);}
	single_ll_iterator end() {return singe_ll_iterator(NULL);}
	single_ll_iterator begin() const {return singe_ll_iterator(head);}
	single_ll_iterator end() const {return singe_ll_iterator(NULL);}

	single_ll() = default;

	single_ll(const std::initializer_list<int>&ilist):head(NULL)
	{
		for(auto it = rbegin(ilist);it!= rend(ilist);it++) push_front(*it);
	}

};

int main()
{
	single_ll sll = {1,2,3};
	sll.push_front(0);

	cout<<"첫번째 리스트";

	for(auto i : sll) cout<<i<<" ";

	cout<<endl;

	auto sll2 = sll ;

	sll2.push_front(-1);
	cout<<"첫 번째 리스트를 복사한 후, 맨 앞에 -1을 추가:";

	for(auto i : sll2) cout<<i<<' ';

	cout<<endl;

	cout<<"깊은 복사 후 첫 번째 리스트";

	for(auto i :sll) cout<<i<<' ';

	cout<<endl;
}

