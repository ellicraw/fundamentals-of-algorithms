#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX_SIZE 101 

bool is_palindrome(string);
string Remove_punct(string);
bool IsOperator(char);
int PerformOperation(char, int, int);
bool IsDigit(char);
int EvaluatePostfix(string);

class ArrayStack {
private:
    char Arr[MAX_SIZE]; 
    int top;   
public:
	// constructor
	ArrayStack()
	{
		top = -1; 
	}
	// Insert an element on top of stack 
	void Push(char x) 
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
	// Return whether stack is empty or not
	int IsEmpty()
	{
		if(top == -1){
            return true;
        } else {
            return false;
        }
    }
    // Returns the amount of elements in the stack
    void Len() {
        cout << "Amount of elements in stack: " << top + 1 << endl;
    }
    // Print stack
	void Print() {
		cout << "Stack: ";
		for(int i = 0;i<=top;i++)
            cout << Arr[i] << " ";
            cout << endl;
    }
};

class QueueStack {
private:
	char Arr[MAX_SIZE];
	int front, rear; 
public:
    // construtor 
	QueueStack()
	{
		front = -1; 
		rear = -1;
	}

	// Check wheter Queue is empty or not
	bool IsEmpty()
	{
		return (front == -1 && rear == -1); 
	}

	// Check whether Queue is full or not
	bool IsFull()
	{
        if ((rear+1)%MAX_SIZE == front) {
            return true;
        } else {
            return false;
        }
	}

	// Inserts an element in queue at rear end
	void Enqueue(char x)
	{
		cout<<"Enqueuing " << x << endl;
		if(IsFull())
		{
			cout<<"Error: Queue is Full" << endl;
			return;
		}
		if (IsEmpty())
		{ 
			front = rear = 0; 
		}
		else
		{
		    rear = (rear+1)%MAX_SIZE;
		}
		Arr[rear] = x;
	}

	// Removes an element in Queue from front end. 
	void Dequeue()
	{
		cout<<"Dequeuing " << endl;
		if(IsEmpty())
		{
			cout<<"Error: Queue is Empty" << endl;
			return;
		}
		else if(front == rear ) 
		{
			rear = front = -1;
		}
		else
		{
			front = (front+1)%MAX_SIZE;
		}
	}
	// Returns element at front of queue. 
	int First()
	{
		if(front == -1)
		{
			cout<<"Error: cannot return front from empty queue" << endl;
			return -1; 
		}
		return Arr[front];
    }
    // Returns the amount of elements in the stack
    void Len() {
        int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
        cout << "Amount of elements in queue: " << count << endl;
    }
    // Print queue
	void Print()
	{
		// Finding number of elements in queue  
		int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
		cout<<"Queue: ";
		for(int i = 0; i <count; i++)
		{
			int index = (front+i) % MAX_SIZE; 
			cout<<Arr[index]<<" ";
		}
		cout<<"\n\n";
	}
};

int main()
{
	// for testing the stack 
	// ArrayStack S; // Create instance of ArrayStack
	// S.Push('o');S.Print();
	// S.Push('s');S.Print();
	// S.Push('k');S.Print();
	// S.Pop();S.Print();
    // S.Push('f');S.Print();
    // S.Len();
    // S.Pop(); 
    // S.Pop(); 
    // S.Pop(); 
    // S.Len();

	// For testing the queue
    // QueueStack Q; // creating an instance of QueueStack. 
    // Q.Enqueue('b');  Q.Print();  
    // Q.Enqueue('w');  Q.Print();  
    // Q.Enqueue('b');  Q.Print();
    // Q.Dequeue();	  Q.Print();
    // Q.Enqueue('a');  Q.Print();
    // Q.Len();

	// for testing the palindrome 
	// string word;
    // bool answer; 
    // cout << endl << "Input a word and I will tell you if it's a palindrome: ";
    // getline(cin,word);
    // answer = is_palindrome(word);
    // if (answer == true) {
    //     cout << word << " is a palindrome" << endl;
    // } else {
    //     cout << word << " is not a palindrome" << endl;
	// }
	
	// for testing the postfix notation
	string expression; 
	cout<<"Enter Postfix Expression: ";
	getline(cin,expression);
	int result = EvaluatePostfix(expression);
	cout<<"Output: "<< expression << ", " << result<< endl;

}

bool is_palindrome(string word)
{
	ArrayStack s;
	char c;
    int n = word.size();
    for(int i = 0; i < n/2; i++)
    {
		if (isalpha(word[i]) && !isblank(word[i])) { // if the character is a letter
			c = word[i];
			s.Push(tolower(c)); // if character is uppercase, make it lower case
		}
    }

    for(int i = (n+1)/2; i < n; i++)
    {
        if(s.Top() != word[i])
        {
            return false;
        }

        s.Pop();
    }

    return true;

}

bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}

int PerformOperation(char operation, int operand1, int operand2) {
	if(operation == '+') return operand1 +operand2;
	else if(operation == '-') return operand1 - operand2;
	else if(operation == '*') return operand1 * operand2;
	else if(operation == '/') return operand1 / operand2;

	else cout<<"Unexpected Error \n";
	return -1; 
}

bool IsDigit(char C) {
	if(C >= '0' && C <= '9') return true;
	return false;
}

int EvaluatePostfix(string expression)
{
	ArrayStack S;

	for(int i = 0;i< expression.length();i++) {
		if(expression[i] == ' ' || expression[i] == ',') continue; 
		else if(IsOperator(expression[i])) {
			int operand2 = S.Top(); 
			S.Pop();
			int operand1 = S.Top(); 
			S.Pop();
			int result = PerformOperation(expression[i], operand1, operand2);
			S.Push(result);
		}
		else if(IsDigit(expression[i])){
			int operand = 0; 
			while(i<expression.length() && IsDigit(expression[i])) {
				operand = (operand*10) + (expression[i] - '0'); 
				i++;
			}
			i--;
			S.Push(operand);
		}
	}
	return S.Top();
}