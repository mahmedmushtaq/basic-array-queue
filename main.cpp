#include <iostream>
using namespace std;



#define MAX_SIZE 100

class Queue{
  int front,rear;
  string items[MAX_SIZE];
  public:
  Queue(){
    front = -1;
    rear = -1;
  }
  bool isEmpty(){
    return front == -1 && rear == -1;
  }
  bool isFull(){
    return (rear+1) % MAX_SIZE == front;
  }

  void enqueue(string item){
    if(isFull()){
      cout << "Queue is overflow";
      return;
    }else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    
    items[rear] = item;

     
  }

  string dequeue(){
    string dataToReturn = "";
    
    if (isEmpty()) {
        cout << "Queue is underflow " << endl;
    } else if (front == rear) {
        // only one element.
        dataToReturn = items[front];
        front = rear = -1;
    } else {
        dataToReturn = items[front];
        front = (front + 1) % MAX_SIZE;
    }
    
    return dataToReturn;

  }

  void clear(){
    front = rear = -1;
  }

  void firstElement(){
    if(front == -1) return;
    cout << items[front] << endl;
  }
  
  void Print()
	{
		// Finding number of elements in queue  
    // divided by max to tackle last when rear=front=0
		int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
		cout<<"Queue       : ";
		for(int i = 0; i <count; i++)
		{
			int index = (front+i) % MAX_SIZE; // Index of element while travesing circularly from front
			cout<<items[index]<<" ";
		}
		cout<<"\n\n";
	}

 
};

int main() {


}
