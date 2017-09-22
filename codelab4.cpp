#include <iostream>
#include <string>
using namespace std;
#define MAX_SIZE 101 

class ArrayStack
{
private:
    int Arr[MAX_SIZE]; 
    int top;   
public:
	// constructor
	ArrayStack()
	{
		top = -1; 
	}

	// Insert an element on top of stack 
	void Push(int x) 
	{
	  if(top == MAX_SIZE -1) { 
			cout << "Stack overflow!"<<  endl;
			return;
		}
		Arr[++top] = x;
	}
 
	// Remove an element from top of stack
	void Pop() 
	{
		if(top == -1) { 
			cout << "Error: No element to pop" << endl;
			return;
		}
		top--;
	}
 
	// Returns the top of the stack
	int Top() 
	{
		return Arr[top];
	}
 
	// Return whether Stack is empty or not
	int IsEmpty()
	{
		if(top == -1){
            return true;
        } else {
            return false;
        }
	}

	void Print() {
		cout << "Stack: ";
		for(int i = 0;i<=top;i++)
            cout << Arr[i] << " ";
            cout << endl;
    }
};

int main()
{
    // Code to test the implementation. 
    // calling Print() after each push or pop to see the state of stack. 
	ArrayStack S;
	S.Push(2);S.Print();
	S.Push(5);S.Print();
	S.Push(10);S.Print();
	S.Pop();S.Print();
	S.Push(12);S.Print();
}