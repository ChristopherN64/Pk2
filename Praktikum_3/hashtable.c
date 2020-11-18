#include <stdio.h>
#include "hashtable.h"

#define TABLE_SIZE 2
#define C 1



//Hash Table
element hashTable[TABLE_SIZE];
int iElementCount = 0;


int main(int argc, char const *argv[])
{
    printf("%d\n", insert(1));
    printf("%d\n", insert(3));
    printf("%d\n", del(3));
    printf("%d\n", insert(5));
    printf("%d\n", member(5));
}


//Hashfuntion
int h(int a)
{
    return a % TABLE_SIZE;
}

//Fügt a wenn möglich in Tabelle ein
int insert(int a)
{
    if (iElementCount < TABLE_SIZE)
    {
        int iIndex = h(a);

        while(hashTable[iIndex].eStatus == BELEGT)
        {
            //Neuberechnung des indexes mittels linearem Sondieren
            iIndex = getNextAusweichIndex(iIndex);
        }

        if (hashTable[iIndex].eStatus != BELEGT)
        {
            //Erstellen eines neuen Elements mit value von a und einfügen in den Berechnete Stelle
            element e;
            e.eStatus = BELEGT;
            e.iValue = a;
            hashTable[iIndex] = e;
            iElementCount++;
            return 1;
        }
        else return 0;
    }
    else return 0;
}

//Löscht Element a wenn vorhanden aus Tabelle
int del(int a)
{
    if(!member(a)) return 0;
    else
    {
        //suchen des Elementes 
        int iSollIndex = h(a);
        element element = hashTable[iSollIndex];

        //Es wird das zu löschende Element gesucht und gelöscht 
        while(1)
        {
            //Wenn der Wert an dem errechneten Tabellenidex gleich dem Gesuchten ist, ist der Wert enthalten und es wird True zurück gegeben 
            if(element.eStatus == BELEGT && element.iValue == a) 
            {
                hashTable[iSollIndex].eStatus=GELOESCHT;
                iElementCount--;
                return 1;
            }
            //Ist der Wert nichte gleich dem zu löschenden wird der nächste Ausweichindex berechnet und geprüft 
            iSollIndex = getNextAusweichIndex(iSollIndex);
            element = hashTable[iSollIndex];
        }       
    }
}

//Gibt zurück ob element a in Hash Tabelle enthalten ist
int member(int a)
{
    int iSollIndex = h(a);
    element element = hashTable[iSollIndex];

    //Überprüfen des Berechneten Index sowie allen Ausweichelementen ob sie gleich dem gesucheten wert sind
    while(element.eStatus!=LEER)
    {
        element = hashTable[iSollIndex];
        //Wenn die Tabelle an dem Index an dem der Wert sein sollte Leer ist (also noch nie eine Wert bessessen hat) ist das Element nicht in der HashTable vorhanden und es wird False zurück gegeben
        if(element.eStatus == LEER) return 0;
        //Wenn der Wert an dem errechneten Tabellenidex gleich dem Gesuchten ist, ist der Wert enthalten und es wird True zurück gegeben 
        else if(element.eStatus == BELEGT && element.iValue == a) return 1;
        iSollIndex = getNextAusweichIndex(iSollIndex);
    }   

    //Wenn die Tabelle an dem Index an dem der Wert sein sollte Leer ist (also noch nie eine Wert bessessen hat) ist das Element nicht in der HashTable vorhanden und es wird False zurück gegeben
    return 0;
}

//Gibt den nächsten ausweichindex zu dem Übergebenen Zurück (Bestimmt also die Kollisionsbehandlung)
int getNextAusweichIndex(int iIndex)
{
    return (iIndex + C) % TABLE_SIZE;
}

void printTable()
{
    for (int il = 0; il < sizeof(hashTable) / sizeof(element); il++)
    {
        if (hashTable[il].eStatus == GELOESCHT)
            printf("%d: Geloescht\n", il);
        else if (hashTable[il].eStatus == LEER)
            printf("%d: Leer\n", il);
        else if (hashTable[il].eStatus == BELEGT)
            printf("%d:  %d\n", il, hashTable[il].iValue);
    }
}


