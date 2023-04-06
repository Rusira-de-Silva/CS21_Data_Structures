#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Stack{
    private : 
        int top;
        int arr[10];
    public:
        Stack(){
            top = -1;
        }

        void push(int value){
            int length = sizeof(arr)/sizeof(int); 
            if (top == length - 1){
                cout << "Stack Overflow" << endl;
            }
            else{
                top++;
                arr[top] = value;
            }
        }

        int pop(){
            if (top <= -1){
                throw underflow_error("Stack Underflow");
            }
            else{
                int temp = arr[top];
                top--;
                return temp;
            }
        }

        bool isEmpty(){
            if (top <= -1){
                return true;
            }
            else{
                return false;
            }
        }

        bool isFull(){
            int length = sizeof(arr)/sizeof(int);
            if (top == length - 1){
                return true;
            }
            else{
                return false;
            }
        }

        int stackTop(){
            if (top <= -1){
                throw underflow_error("Stack Underflow");
            }
            else{
                return arr[top];
            }
        }

        void display(){
            if (top <= -1){
                cout << "Stack Underflow" << endl;
            }
            else{
                for (int i = top; i >= 0; i--){
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
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
