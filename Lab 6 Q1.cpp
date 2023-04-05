#include <iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;

#define sizeMax 15 // Maximum size of the stack

int arr[sizeMax];
int top = -1;


void Push(int x) {

    top++;
    if (top == sizeMax) {
        cout << "Stack Overflow" << "\n";
        return;
    }
    else{
        arr[top] = x;

    }
}

int Pop() {

    if (top == -1) {
        cout << "Stack Underflow" << "\n";
        return -1;
    }
    else{
        top--;
        return arr[top];
    }
}

bool isEmpty() {

    if(top == -1){  //if empty top hasn't changed from initial
        cout << "Empty Stack" << "\n";
        return 1;
    }
    else {
        cout << "Stack not Empty" << "\n";
        return 0;  
    }

}

bool isFull() {
    
    if(top == sizeMax-1){
        cout << "Full Stack" << "\n";   
        return 1;
    }
    else {
        cout << "Stack not Full" << "\n";
        return 0;
    }
}

int StackTop() {

    if (top == -1) {
        cout << "Stack Empty" << "\n";
        return -1;
    }
    else{
        return arr[top];
    }
}

void Display() {

    if (top == -1) {
        cout << "Stack Empty" << "\n";
        return;
    }
    else{
        cout << "Stack: ";
        for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
        }
        cout << "\n";
    }
    
}


int main() {
    auto start = chrono::high_resolution_clock::now();  
    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by Stack (array) : "<< duration.count() << " microseconds\n";
}

