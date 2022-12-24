#include<iostream>
using namespace std;

class Twostack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;

    Twostack(int s){
        this-> size=s;
        top1 =-1;
        top2 = size;
        arr = new int [s];
    }
    void push1(int num){
        if(top2-top1>1)
        {
            top1++;
            arr[top1]=num;
            cout<<arr[top1]<<" ";
        }
        else{
            cout<<"\nStack overflow";
        }
    }
    void push2(int num){
        if(top2 - top1>1){
            top2--;
            arr[top2]= num;
            cout<<arr[top2]<<" ";
        }
        else {
            cout<<"\nStack Overflow";
        }
    }
    int pop1(){
        if(top1 >0){
            int ans =arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }
    int pop2(){
        if(top2< size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }
    
};
int main(){
    Twostack  s(5);
    s.push1(2);
    s.push2(5);
    s.push1(3);
    return 0;
}