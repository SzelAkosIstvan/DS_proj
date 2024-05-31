#ifndef jatekfunkciok_h
#define jatekfunkciok_h
#include <iostream>
#include <string>
#include <vector>
#include "verem.h"

#define TRUE 1
#define FALSE 0

typedef verem Pakli;

class jatekos
{
    char* nev = NULL;
    
    vector<int> kartyaSzam;
    vector<string> kartyaSzimbolum;

    int kartyakSzama=0, jatekban=0, penz=0;
    bool mutatja = FALSE;
    
public:
    void jatekKezdet();
    
    void kartyaHuzas(Pakli&);
    
    void kartyaKeveres(Pakli&, int);
    
    void tet(int);
    void tetduplazas();
    
    void penzkezeles(double); // ha a bemenet 2.5 akkor annyival tobbet ad vissza, ha csak 1 akkor a tetet adja vissza, ha pedig 2 akkor annyit ad vissza a penzhez
    
    int listazPenz();
    
    int kartyamennyiseg();
    
    bool isHidden();
    
    
    void showCard();//, const char [][100], const char [][100]); //hany kartyat kell kiirjon, kinek a kartyaja [] <-elsoben es elso a kartya szine, masodik a karya szama
    void hideCard(); //ugyanaz mint a felso annyi kulonbseggel, hogy ezt csak az oszto hasznalja
    void showHidden(); //osztoe de ugyanaz mint a showCard
    void splitShow();
    
    int bjEllenorzes();//azert int tipusu mert vagy kevesebb vagy tobb vagy pont annyi (21)
    
    void kezUrites();
    
    void ujrakeveres(Pakli&);
    
    bool biztositas();
    bool rosszdontes();
    
    bool twoHand();
    void kartyatadas(jatekos&);
    void nyeremenyVisszaadas(jatekos&);
};

void inti();

void letrehozPakli(Pakli&, const int);



#endif /* jatekfunkciok_h */
