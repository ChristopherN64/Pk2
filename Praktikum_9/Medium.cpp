#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "Medium.h"

//Medium
int Medium::iObjectCount = 0;
Medium::Medium(std::string tlt, int j) : id{iObjectCount++},titel{tlt},jahr{j}
{}

Medium::~Medium()
{
    iObjectCount--;
}
void Medium::druckeDaten(){};

int Medium::alter()
{
    return 2020 - jahr;
}


int  Medium::getId() {return id;}
int  Medium::getJahr() {return jahr;}
std::string  Medium::getTitel(){return titel;}



//-------------------------------------------------------------------------------------------------
//Audio
Audio::Audio(std::string t,int j, std::string i, int d) :  Medium(t,j),interpret{i},dauer{d} 
{}

void Audio::druckeDaten()
{
    std::cout << "ID = " << getId() << " " <<  getTitel() << " von " << interpret << " aus " << getJahr() << " spieldauer: " << dauer << std:: endl;
}




//-------------------------------------------------------------------------------------------------
//Bild
Bild::Bild(std::string t,int j,std::string o) : Medium(t,j),ort{o}
{}


void Bild::druckeDaten()
{
    std::cout << "ID = " << getId() << " "<< getTitel() << " aufgenommen im ahr " << getJahr() << " in " << ort << std:: endl;
}
