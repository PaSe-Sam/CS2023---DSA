#include<iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
    Node* head;

    public:
    Stack() {
        head = NULL;
    }

    void Push(int data){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    
    int Pop(){

        if (head == NULL) {
            cout << "Empty Stack" << "\n";
            return -1;
        }

        Node* temp = head;
        int val = head->data; //popped value
        head = head->next;
        delete temp;
        return val;

    }

    bool isEmpty(){

        if (head == NULL){
            cout << "Empty Stack" << "\n";
            return 1;
        }

        else{
            cout << "Stack not Empty" << "\n";
            return 0;  
        }
    }
    

    bool isFull(){
        cout << "Stack not Full" << "\n";  
        return false;   
    }

    int StackTop(){

        if (head == NULL) {
            cout << "Empty Stack" << "\n";
            return -1;
        }
        else{
            return head->data;
        }
        
    }

    void Display(){
        Node* temp = head;
        cout<< "Stack: ";
        while (temp != NULL) {  //list not empty
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    
    Stack stack;

	auto start = chrono::high_resolution_clock::now();  
    stack.Push(8);
	stack.Push(10);
	stack.Push(5);
	stack.Push(11);
    stack.Push(15);
	stack.Push(23);
	stack.Push(6);
	stack.Push(18);
    stack.Push(20);
	stack.Push(17);
    stack.Display();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();
	stack.Display();
    stack.Push(4);
	stack.Push(30);
	stack.Push(3);
	stack.Push(1);
	stack.Display();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by Stack (Linked list) : "<< duration.count() << " microseconds\n";
    
}
