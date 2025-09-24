/***********************************************
 * 2025-09-15
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

class Stack{
private:
    vector<int> arr;
public:
    Stack(){}

    int size(){
        return arr.size();
    }

    void push(int value){
        arr.push_back(value);
    }

    int pop(){
        if(arr.empty()){
            return -1;
        }
        int top_element = arr.back();
        arr.pop_back();
        return top_element;
    }

    int peek(){
        if(arr.empty()){
            return -1;
        }
        return arr.back();
    }

    bool isEmpty(){
        return arr.empty();
    }
};

int main() {
    Stack myStack;
    fastio;
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        int cmd, num;
        cin >> cmd;
        switch(cmd){
            case 1 :
                cin >> num;
                myStack.push(num);
                break;
            case 2 :
                cout << myStack.pop() << endl;
                break;
            case 3 :
                cout << myStack.size() << endl;
                break;
            case 4 :
                if(myStack.isEmpty()){
                    cout << 1 << endl; 
                    break;                   
                }
                cout << 0 << endl;
                break;
            case 5 :
                cout << myStack.peek() << endl;
                break;
        }
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}