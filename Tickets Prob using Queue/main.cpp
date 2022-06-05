#include <iostream>

using namespace std;

class MyQueue{          //Queue class using Circular Array

public:
int front;
int rear,size;
int length;                    //actual num of elements inside the queue
int *arr=new int [size];

MyQueue(int mysize){
    size = mysize+1;
    front=0;
    rear=size-1;
    length=0;
}

bool IsEmpty(){
if( length == 0)
    return true;
else
    return false;
}

bool IsFull(){
if(length == size)
    return true;
else
    return false;
}

bool EnQueue(int num)
{
    if(IsFull())
       return false;
    else
    {
        rear = (rear + 1) % size;
        arr[rear]= num;
        length++;
        return true;
    }
}
bool DeQueue()
{   if(IsEmpty())
       return false;
     else
    {
    front = (front + 1) % size;
    length--;
    return true;
     }
}

void display()
{
    for (int i = front; i != rear+1; i=(i+1)%size)
{cout << arr[i]<<" ";
}
}


};


int tickets(int k, MyQueue a1)          //function to calculate the seconds for a specific position
{
    int seconds=0;

 while(a1.arr[k] != 0 ){

for (int i = a1.front; i != a1.rear+1; i=(i+1)% a1.size)
{
    a1.arr[i]--;

if( (a1.arr[i] >= 0) && (a1.arr[k] != 0  ))
    {  seconds++; }

}

 }
 return seconds+1;

}



int main()
{
//                                       Test Cases/*
MyQueue T1(3);
T1.EnQueue(2);
T1.EnQueue(3);
T1.EnQueue(2);

cout<<tickets(2 , T1)<<" seconds \n";


MyQueue T2(4);
T2.EnQueue(5);
T2.EnQueue(1);
T2.EnQueue(1);
T2.EnQueue(1);

cout<<tickets(0 , T2)<<" seconds \n";

MyQueue T3(4);
T3.EnQueue(2);
T3.EnQueue(2);
T3.EnQueue(2);
T3.EnQueue(1);
cout<<tickets(1 , T3)<<" seconds \n";

MyQueue T4(4);
T4.EnQueue(1);
T4.EnQueue(6);
T4.DeQueue();
T4.EnQueue(3);
T4.EnQueue(1);
cout<<tickets(3 , T4)<<" seconds \n";

}


