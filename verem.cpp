#include "verem.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

verem::verem()
{
    legujabb = NULL;
    kartyaszam = 0;
}

verem::verem(int* number, string* symobl, int size)
{
    if(sizeof(number)==sizeof(symobl)==size)//elofeltetel, hogy ugyanannyi szam legyen mint szimbolum
    {
        legujabb=NULL;//ennek a beallitasara azert van szukseg, hogy a for ciklus elso futasa eseten is helyesen legyen beallitva a kovetkezoLap adat
        kartyaszam=0;
        for(int i=0;i<size;i++)
        {
            tarolo* temp = new tarolo;
            temp->ertek = number[i];
            temp->szimbolum = symobl[i];
            temp->elfedettLap = legujabb;
            legujabb = temp;
            kartyaszam++;
        }
    }
}

verem::~verem()
{
    tarolo* temp = legujabb;
    while(temp != NULL)
    {
        legujabb = legujabb->elfedettLap;
        delete temp;
        temp = legujabb;
    }
    kartyaszam= 0;
}

void verem::push(int ertek, string jel)
{
    tarolo* temp=new tarolo;
    temp->ertek=ertek;
    temp->szimbolum=jel;
    temp->elfedettLap=legujabb;
    legujabb=temp;
    kartyaszam++;
}

void verem::pusha(int mennyiseg, vector<int> ertek, vector<string> jel)
{
    for(int i=0;i<mennyiseg;i++)
    {
        tarolo* temp=new tarolo;
        temp->ertek=ertek[i];
        temp->szimbolum=jel[i];
        temp->elfedettLap=legujabb;
        legujabb=temp;
        kartyaszam++;
    }
}

void verem::pop(int &ertek, string &jel)
{
    tarolo* temp = legujabb;
    ertek=temp->ertek;
    jel=temp->szimbolum;
    legujabb=legujabb->elfedettLap;
    delete temp;
    kartyaszam-=1;
}

void verem::print()
{
    tarolo* temp = legujabb;
    while(temp != NULL)
    {
        cout << temp->ertek << " "<< temp->szimbolum<<endl;
        temp = temp->elfedettLap;
    }
}

bool verem::isEmpty()
{
    tarolo* temp = legujabb;
    if(temp==NULL)
        return true;
    else return false;
}

int verem::size()
{
    return kartyaszam;
}

void verem::clear()
{
    int szam;
    string szimbolum;
    while(!isEmpty())
    {
        pop(szam, szimbolum);
    }
}
