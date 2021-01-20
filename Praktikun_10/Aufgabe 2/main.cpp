#include <iostream>
#include "stack.h"

int text_laenge(char text[]){
   int c = 0;
   while(text[c]!='\0'){
       c++;
   }
   return c;
}

int main(){
    Stack stack(100);
    int i;
    for(i=1; i<= 100; i++ ){
        stack.push(i);
    }
    for(i=0; i < 103; i++){
        try {
            printf("%d\n", stack.pop());
        }
        catch (const empty_stack_error& e) {
            std::cout << "Fehler aufgetreten" << std::endl;
        }

    }

    return 0;
}