#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include "hashtable.h"

using namespace std;

//Hashtable
list<int> hashtable[TABLE_SIZE];

int main(int argc, char const *argv[])
{
    /*
    int i;
    for (i = 1; i <= 2 * TABLE_SIZE; i++)
    {
        printf("%d", insert(i));
    }
    for (i = 1; i <= TABLE_SIZE; i++)
    {
        printf("%d", member(i));
    }
    for (i = TABLE_SIZE + 1; i <= 2 * TABLE_SIZE; i++)
    {
        printf("%d", del(i));
    }
    for (i = 1; i <= 2 * TABLE_SIZE; i++)
    {
        printf("%d", member(i));
    }
    printf("\n");
    */

    for(int il=1 ; il<argc;il++)
    {
        //Auslesen des n-ten Argumentes in einen String
        string s = argv[il];
        //Umwandeln des Strings in einen Int
        int i = stoi(s,nullptr,0);
        //Hinzufügen zur Hashmap
        insert(i);
    }   

    int iInput = 0;
    while (1)
    {
        cin >> iInput;
        if(iInput == -1) break;
        cout << "member = " << member(iInput) << endl;
    }
    
    return 0;
}

int h(int a)
{
    return a % TABLE_SIZE;
}

int insert(int a)
{
    int iElementIndex = h(a);
    hashtable[iElementIndex].push_back(a);
    return 1;
}

void printTable()
{
    for (list<int> list : hashtable)
    {
        for (int i : list)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << "-----------------------------------" << endl;
}

int member(int a)
{
    int iElementIndex = h(a);
    for (int i : hashtable[iElementIndex])
    {
        if (i == a)
            return 1;
    }
    return 0;
}

int del(int a)
{
    int iElementIndex = h(a);
    for (int i : hashtable[iElementIndex])
    {
        if (i == a)
        {
            hashtable[iElementIndex].remove(a);
            return 1;
        }
    }
    return 0;
}
