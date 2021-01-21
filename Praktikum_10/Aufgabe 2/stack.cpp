#include "stack.h"

using namespace std;

Stack::Stack(int n) : size{n}, top(-1)
{
    stack = new int[size];
}

int Stack::push(int key){
   if(top < size-1){
       stack[++top] = key;
       return 1;
   } else {
       return 0;
   }
}

int Stack::pop(){
    if(top > -1){
        return stack[top--];
    } else {
        //Konvention
        throw empty_stack_error("Der Stack ist Leer");
    }
}

empty_stack_error::empty_stack_error(string info) : range_error(info){};