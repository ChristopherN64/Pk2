int h(int a);
int getNextAusweichIndex(int iIndex);
int insert(int a);
void printTable();
int member(int a);
int del(int a);

typedef enum status_e
{
    LEER,
    BELEGT,
    GELOESCHT
} status;

typedef struct element_s
{
    int iValue;
    status eStatus;
} element;