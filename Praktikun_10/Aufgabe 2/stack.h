
#include <stdexcept>
#include <string>
using namespace std;



class empty_stack_error : private range_error
{
public:
    empty_stack_error(string info);
};


class Stack
{
private:
    int size;
    int top;
    int *stack;
public:
    Stack(int n);
    int push(int key);
    int pop();
};



