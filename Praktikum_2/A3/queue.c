#include <stdio.h>
#define iSize 2

int array[iSize];
int iRead=0;
int iWrite=0;

// 0 = ist leer
// 1 = ist weder leer noch voll 
// 2 = ist voll
int iStatus=0;

void enqueue(int i)
{
    //Wenn die Que voll ist
    if((iWrite+1) % iSize ==iRead%iSize) 
    {
        array[iWrite%iSize] = i;
    }
    else
    {
        array[iWrite%iSize] = i;
        printf("\nWrite to %d wert %d \n",iWrite%iSize,i);
        iWrite++;
    }
}

int dequeue()
{
    //Wenn die Que nicht leer ist 
    if(iWrite%iSize==(iRead+1)%iSize) 
    {
        return -1;
    }
    else
    {
        int iRet;
        iRet = array[(iRead) % iSize];
        iRead++;
        return iRead;
    }
}



int main(int argc, char const *argv[])
{
    enqueue(1);
    enqueue(2);
    enqueue(2);
    printf("%i ", dequeue());
    enqueue(3);
    printf("%i ", dequeue());
    printf("%i ", dequeue());
    printf("%i ", dequeue());
    enqueue(4);
    enqueue(5);
    printf("%i ", dequeue());
    printf("%i \n", dequeue());

    return 0;
}