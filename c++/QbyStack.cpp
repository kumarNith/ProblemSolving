#include<iostream>
#include<stack>


using namespace std;

class Q{
	public:
		stack<int> mypop;
		stack<int> mypush;

		void enQueue(int data);
		int deQueue();


};
void Q::enQueue(int data){
	mypush.push(data);

}

int Q::deQueue(){
	if(mypop.empty()){
		while(!mypush.empty()){
			mypop.push(mypush.top());
			mypush.pop();
		}
	}
	int data = mypop.top();
	mypop.pop();
	return data;


}

int main(){
	Q q;
	q.enQueue(1);q.enQueue(10);q.enQueue(100);
	cout<<" "<<q.deQueue();cout<<" "<<q.deQueue();cout<<" "<<q.deQueue();
	cout<<endl;
	q.enQueue(2);q.enQueue(20);q.enQueue(200);
	cout<<" "<<q.deQueue();cout<<" "<<q.deQueue();cout<<" "<<q.deQueue();
	cout<<endl;
}