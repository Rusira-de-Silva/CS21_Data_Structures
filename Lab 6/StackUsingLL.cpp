#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Node{
    int data;
    Node * next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

class Stack{
    private:
        Node * top;

    public:
        Stack(){
            top = nullptr;
        }

        void push(int value){
            Node * temp = new Node(value);
            temp->next = top;
            top = temp;
        }

        int pop(){
            if (top == nullptr){
                throw underflow_error("Stack Underflow");
            }
            else{
                int popValue = top->data;
                Node * temp = top;
                top = top->next;
                delete temp;
                return popValue;
            }
        }

        bool isEmpty(){
            if (top == nullptr){
                return true;
            }
            else{
                return false;
            }
        }

        int stackTop(){
            if (top == nullptr){
                throw underflow_error("Stack Underflow");
            }
            else{
                return top->data;
            }
        }

        void display(){
            if (top == nullptr){
                cout << "Stack Underflow" << endl;
            }
            Node * current = top;
            while(current != nullptr){
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
};

int main()
{
    auto startTime = high_resolution_clock::now();
    Stack stack;
    stack.push(8);
    stack.push(10);
    stack.push(5);
    stack.push(11);
    stack.push(15);
    stack.push(23);
    stack.push(6);
    stack.push(18);
    stack.push(20);
    stack.push(17);
    stack.display();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();
    stack.push(4);
    stack.push(30);
    stack.push(3);
    stack.push(1);
    stack.display();
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime- startTime);
    cout << "Execution time: " << duration.count() << " microseconds" << endl;
    return 0;
}
