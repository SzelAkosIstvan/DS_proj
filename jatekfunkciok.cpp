#include "jatekfunkciok.h"
#include "verem.h"
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

void inti()
{
    srand(time(NULL));
}

void letrehozPakli(Pakli &kartyak, const int pakliszam)
{
    verem();//meg kell hivni a verem konstruktorat, hogy letrehozzuk a tarhelyet a kartyaknak
    string lehetosegek[] = {"♥", "♣", "♦", "♠"};
    for(int pakli=0;pakli<pakliszam;pakli++)
    {
        for(int i=1;i<=4;i++)
        {
            for(int j=2;j<=14;j++)
            {
                switch (i) {
                    case 1:
                        kartyak.push(j, lehetosegek[0]);
                        break;
                    case 2:
                        kartyak.push(j, lehetosegek[1]);
                        break;
                    case 3:
                        kartyak.push(j, lehetosegek[2]);
                        break;
                    case 4:
                        kartyak.push(j, lehetosegek[3]);
                        break;
                }
            }
        }
    }
    //kartyak.print();
}

void jatekos::kartyaHuzas(Pakli &kartyak)
{
    int szam;
    string jel;
    kartyak.pop(szam, jel);
    //cout<<szam<<" "<<jel<<endl;
    kartyaSzam.push_back(szam);
    kartyaSzimbolum.push_back(jel);
    kartyakSzama+=1;
}

void jatekos::kartyaKeveres(Pakli &kartyak, int maxKartyak)  //♥, ♣, ♦, ♠
{
    //a kartyakat at kell tenni eloszor az oszto kezebe es ott osszkeverni oket majd visszarakni a taroloba
    for(int i=0;i<maxKartyak;i++)
    {
        kartyaHuzas(kartyak);
    }
//    for(int i=0;i<maxKartyak;i++)
//    {
//        cout<<kartyaSzam[i]<<" "<<kartyaSzimbolum[i]<<endl;
//    }
    //int index=maxKartyak;
    for (int i=kartyakSzama-1;i>0;i--)
    {
        int rand_index = rand()%i;
        int tempSzam;
        string tempJel;
        tempSzam=kartyaSzam[i];
        tempJel=kartyaSzimbolum[i];
        kartyaSzam[i]=kartyaSzam[rand_index];
        kartyaSzimbolum[i]=kartyaSzimbolum[rand_index];
        kartyaSzam[rand_index]=tempSzam;
        kartyaSzimbolum[rand_index]=tempJel;
    }
//    for(int i=0;i<maxKartyak;i++)
//    {
//        cout<<kartyaSzam[i]<<" "<<kartyaSzimbolum[i]<<endl;
//    }
    //most pedig vissza kell tegye az oszto az osszes kartyat a helyere
    //void pusha();             //jatekos::pusha(); talan
    kartyak.pusha(maxKartyak, kartyaSzam, kartyaSzimbolum);
    kartyaSzam.clear();
    kartyaSzimbolum.clear();
    kartyakSzama=0;
    //kartyak.print();
}

void jatekos::jatekKezdet()
{
    nev = new char[200];
    cin.getline(nev, 200);
    penz=1000;
}

int jatekos::listazPenz()
{
    return penz;
}

int jatekos::kartyamennyiseg()
{
    return kartyakSzama;
}

bool jatekos::isHidden()
{
    return !mutatja;
}

void jatekos::tet(int feltettPenz)//ezt atalakithatom, hogy itt nezze meg ha ervenyes e vagy sem
{
    jatekban=feltettPenz;
    penz-=feltettPenz;
}

void jatekos::hideCard()
{
    if(kartyakSzama==1)
    {
        for(int j=0;j<=4;j++)
            cout<<"                     |                   |"<<endl;
        cout<<"                     | ";
        if(kartyaSzam[0]<10)
            cout<<kartyaSzam[0]<<"  ";
        else if(kartyaSzam[0]==10)
            cout<<"10 ";
        else if(kartyaSzam[0]==11)
            cout<<"A  ";
        else if(kartyaSzam[0]==12)
            cout<<"J  ";
        else if(kartyaSzam[0]==13)
            cout<<"Q  ";
        else if(kartyaSzam[0]==14)
            cout<<"K  ";
        cout<<"               |"<<endl;
            cout<<"                     | "<<kartyaSzimbolum[0]<<"                 |"<<endl;
            cout<<"                     --------------------"<<endl;
    }
    else
    {
        for(int j=0;j<=4;j++)
            cout<<"                     |    |                 |"<<endl;
        cout<<"                     | ";
        if(kartyaSzam[0]<10)
            cout<<kartyaSzam[0]<<"  ";
        else if(kartyaSzam[0]==10)
            cout<<"10 ";
        else if(kartyaSzam[0]==11)
            cout<<"A  ";
        else if(kartyaSzam[0]==12)
            cout<<"J  ";
        else if(kartyaSzam[0]==13)
            cout<<"Q  ";
        else if(kartyaSzam[0]==14)
            cout<<"K  ";
        cout<<"|                 |"<<endl;
            cout<<"                     | "<<kartyaSzimbolum[0]<<"  |                 |"<<endl;
            cout<<"                     -----------------------"<<endl;
    }
}

void jatekos::showHidden()
{
    for(int i=0;i<=4;i++)
    {
        cout<<"                     |    ";
        for(int j=1;j<=kartyakSzama-1;j++)
        {
            cout<<"|    ";
        }
        cout<<"                 |"<<endl;
    }
    cout<<"                     | ";
    if(kartyaSzam[0]<10)
        cout<<kartyaSzam[0]<<"  ";
    else if(kartyaSzam[0]==10)
        cout<<"10 ";
    else if(kartyaSzam[0]==11)
        cout<<"A  ";
    else if(kartyaSzam[0]==12)
        cout<<"J  ";
    else if(kartyaSzam[0]==13)
        cout<<"Q  ";
    else if(kartyaSzam[0]==14)
        cout<<"K  ";
    for(int j=1;j<=kartyakSzama-1;j++)
    {
        cout<<"| ";
        if(kartyaSzam[j]<10)
            cout<<kartyaSzam[j]<<"  ";
        else if(kartyaSzam[j]==10)
            cout<<"10 ";
        else if(kartyaSzam[j]==11)
            cout<<"A  ";
        else if(kartyaSzam[j]==12)
            cout<<"J  ";
        else if(kartyaSzam[j]==13)
            cout<<"Q  ";
        else if(kartyaSzam[j]==14)
            cout<<"K  ";
    }
    cout<<"                 |"<<endl;
    cout<<"                     | "<<kartyaSzimbolum[0]<<"  ";
    for(int j=1;j<=kartyakSzama-1;j++)
    {
        cout<<"| "<<kartyaSzimbolum[j]<<"  ";
    }
    cout<<"                 |"<<endl;
    cout<<"                     ----------------------";
    for(int i=1;i<kartyakSzama;i++)
        cout<<"-----";
    cout<<endl;
}

void jatekos::showCard()
{
    cout<<"                     ----------------------";
    for(int i=1;i<kartyakSzama;i++)
        cout<<"-----";
    cout<<endl;
    cout<<"                     | ";
    if(kartyaSzam[0]<10)
        cout<<kartyaSzam[0]<<"  ";
    else if(kartyaSzam[0]==10)
        cout<<"10 ";
    else if(kartyaSzam[0]==11)
        cout<<"A  ";
    else if(kartyaSzam[0]==12)
        cout<<"J  ";
    else if(kartyaSzam[0]==13)
        cout<<"Q  ";
    else if(kartyaSzam[0]==14)
        cout<<"K  ";
    for(int j=1;j<=kartyakSzama-1;j++)
    {
        cout<<"| ";
        if(kartyaSzam[j]<10)
            cout<<kartyaSzam[j]<<"  ";
        else if(kartyaSzam[j]==10)
            cout<<"10 ";
        else if(kartyaSzam[j]==11)
            cout<<"A  ";
        else if(kartyaSzam[j]==12)
            cout<<"J  ";
        else if(kartyaSzam[j]==13)
            cout<<"Q  ";
        else if(kartyaSzam[j]==14)
            cout<<"K  ";
    }
    cout<<"                 |"<<endl;
    cout<<"                     | "<<kartyaSzimbolum[0]<<"  ";
    for(int j=1;j<=kartyakSzama-1;j++)
    {
        cout<<"| "<<kartyaSzimbolum[j]<<"  ";
    }
    cout<<"                 |"<<endl;
    for(int i=0;i<=4;i++)
    {
        cout<<"                     |    ";
        for(int j=1;j<=kartyakSzama-1;j++)
        {
            cout<<"|    ";
        }
        cout<<"                 |"<<endl;
    }
}

void jatekos::splitShow()
{
    cout<<"   ----------------------";
    for(int i=1;i<kartyakSzama;i++)
        cout<<"-----";
    cout<<endl;
    cout<<"   | ";
    if(kartyaSzam[0]<10)
        cout<<kartyaSzam[0]<<"  ";
    else if(kartyaSzam[0]==10)
        cout<<"10 ";
    else if(kartyaSzam[0]==11)
        cout<<"A  ";
    else if(kartyaSzam[0]==12)
        cout<<"J  ";
    else if(kartyaSzam[0]==13)
        cout<<"Q  ";
    else if(kartyaSzam[0]==14)
        cout<<"K  ";
    for(int j=1;j<=kartyakSzama-1;j++)
    {
        cout<<"| ";
        if(kartyaSzam[j]<10)
            cout<<kartyaSzam[j]<<"  ";
        else if(kartyaSzam[j]==10)
            cout<<"10 ";
        else if(kartyaSzam[j]==11)
            cout<<"A  ";
        else if(kartyaSzam[j]==12)
            cout<<"J  ";
        else if(kartyaSzam[j]==13)
            cout<<"Q  ";
        else if(kartyaSzam[j]==14)
            cout<<"K  ";
    }
    cout<<"                 |"<<endl;
    cout<<"   | "<<kartyaSzimbolum[0]<<"  ";
    for(int j=1;j<=kartyakSzama-1;j++)
    {
        cout<<"| "<<kartyaSzimbolum[j]<<"  ";
    }
    cout<<"                 |"<<endl;
    for(int i=0;i<=4;i++)
    {
        cout<<"   |    ";
        for(int j=1;j<=kartyakSzama-1;j++)
        {
            cout<<"|    ";
        }
        cout<<"                 |"<<endl;
    }
}

int jatekos::bjEllenorzes()
{
    int ertek=0,aszSzamlalo=0;
    for(int i=0;i<kartyakSzama;i++)
    {
        if(kartyaSzam[i]<11)
            ertek+=kartyaSzam[i];
        else if(kartyaSzam[i]==11)
        {
            aszSzamlalo+=1;
        }
        else
            ertek+=10;
    }
    for(int i=0;i<aszSzamlalo;i++)
    {
        if(ertek<=10)
            ertek+=11;
        else
            ertek+=1;
    }
    return ertek;
}

void jatekos::kezUrites()
{
    kartyaSzam.clear();
    kartyaSzimbolum.clear();
    kartyakSzama=0;
}

void jatekos::penzkezeles(double valasz)
{
    if(valasz==2)
    {
        jatekban*=2;
        penz+=jatekban;
        jatekban=0;
    }
    else if(valasz==2.5)
    {
        jatekban*=2.5;
        penz+=jatekban;
        jatekban=0;
    }
    else if(valasz==1)
    {
        penz+=jatekban;
        jatekban=0;
    }
}

void jatekos::ujrakeveres(Pakli &kartyak)
{
    while(!kartyak.isEmpty())
    {
        kartyaHuzas(kartyak);
    }
    letrehozPakli(kartyak, 1);
    kartyaKeveres(kartyak, 52);
}

bool jatekos::biztositas()
{
    if(kartyaSzam[0]==11)
        return true;
    return false;
}

bool jatekos::rosszdontes()
{
    if(bjEllenorzes()==21)
        return true;
    return false;
}

bool jatekos::twoHand()
{
    if(kartyaSzam[0]==kartyaSzam[1])
        return true;
    return false;
}

void jatekos::tetduplazas()
{
    if(penz>=jatekban)
    {
        penz-=jatekban;
        jatekban*=2;
    }
    else
        throw "Nincs elegendo penzed.. hit OR stand? ";
}

void jatekos::kartyatadas(jatekos &jatekos3)
{
    kartyakSzama-=1;
    jatekos3.kartyakSzama=1;
    int tempSzam=kartyaSzam[kartyaSzam.size()-1];
    kartyaSzam.pop_back();
    jatekos3.kartyaSzam.push_back(tempSzam);
    string tempJel=kartyaSzimbolum[kartyaSzimbolum.size()-1];
    kartyaSzimbolum.pop_back();
    jatekos3.kartyaSzimbolum.push_back(tempJel);
    jatekos3.jatekban=jatekban;
    penz-=jatekban;
    //jo lenne ha a penznel pedig tudnak csinalni egy mutatot ami a jatekos penzere mutat
}

void jatekos::nyeremenyVisszaadas(jatekos &jatekos3)
{
    penz+=jatekos3.penz;
}
