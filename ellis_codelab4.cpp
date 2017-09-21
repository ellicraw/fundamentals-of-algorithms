#include <iostream>
#include <string>

using namespace std;

public class ArrayStack {
private: 
    int Stackz[100]; // array to store stack
    int top; // marks the top index of the stack
public: 
    // constructor
    Stack() {
        top = -1;
    }
    // Insert an element on to the top of the stack
    push (int x) {
        if (top == 99) {
            cout << "Stack overflow!" << endl;
            return;
        }
        Stackz[++top] = x;
    }
    // Remove element from the top of the stack 
    void pop () {
        if (is_empty()) {
            cout << "No element to pop" << endl;
            return;
        }   
        Stackz[top--];
    } 
    // Returns the element at the top of the stack
    int top() {
        return Stackz[top];
    }
    // Returns whether stack is empty or not
    bool is_empty() {
        if(top == -1){
            return true;
        }
        else {
            return false;
        }
    }
    // Returns the number of items in the stack
    int len() {
        int amount;
        amount = Stackz.size();
        return amonut;
    }

}

int main() {
    
    }