#include <iostream>
#include "verem.h"
#include "jatekfunkciok.h"
#include <string>
#include <time.h>
using namespace std;

Pakli Kartyapakli;
jatekos jatekos1, jatekos2;//player2 -nek soha nem lesz neve vagy penze (bot)

void CLS()
{
    cout << "\033[2J\033[1;1H";
}
bool getyn()
{
    char x;
    while(true)
    {
        x=getchar();
        if(x=='y')
            return true;
        else if(x=='Y')
            return true;
        else if(x=='n')
            return false;
        else if(x=='N')
            return false;
    }
}

void sleep(float masodpercek)
{
    time_t kezdes = clock();
    float varakozasi = masodpercek * CLOCKS_PER_SEC;
    while (clock() < kezdes + varakozasi)
    {
        ;
    }
}

void visszaszamlalas()
{
    for(int i=3;i>=1;i--)
    {
        cout<<i<<"...."<<endl;
        sleep(1);
        CLS();
    }
}

void kezdes()
{
    inti();//init random
    cout<<"Udvozollek a BlackJack jatekban"<<endl;
    sleep(1.5);
    cout<<"Kezdeshez add meg a neved: ";
    jatekos1.jatekKezdet();
    CLS();
    letrehozPakli(Kartyapakli, 1);
    jatekos2.kartyaKeveres(Kartyapakli, 52);
    visszaszamlalas();
}

void twohandgame()
{
    jatekos jatekos3;
    jatekos1.kartyatadas(jatekos3);
    CLS();
    cout<<endl<<endl<<endl<<"   ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼"<<endl;
    jatekos1.splitShow();//showcard aztan jatek es kartyaatadas es jatek ujra
    jatekos3.splitShow();
    sleep(7);
    CLS();
    jatekos1.kartyaHuzas(Kartyapakli);
    jatekos2.hideCard();
    sleep(1);
    cout<<endl<<endl<<endl<<endl;
    jatekos1.showCard();
    char ker;
    if(jatekos1.bjEllenorzes()==21)
    {
        CLS();
        jatekos2.hideCard();
        sleep(1);
        cout<<endl<<endl<<endl<<endl;
        jatekos1.showCard();
        sleep(3);
        if(jatekos2.bjEllenorzes()==21)
            jatekos1.penzkezeles(1);
        else
            jatekos1.penzkezeles(2.5);
    }
    else
    {
        while(jatekos1.bjEllenorzes()<21)
        {
            cin>>ker;
            if(ker=='w');
            else if(ker=='s')
                break;
            else
            {
                CLS();
                cout<<"Ismetelje meg kereset: ";
                sleep(0.5);
                continue;
            }
            CLS();
            jatekos2.hideCard();
            sleep(1);
            cout<<endl<<endl<<endl<<endl;
            jatekos1.kartyaHuzas(Kartyapakli);
            jatekos1.showCard();
        }
    }
    CLS();
    jatekos2.hideCard();
    sleep(1);
    cout<<endl<<endl<<endl<<endl;
    jatekos1.showCard();
    sleep(5);
    CLS();
    cout<<endl<<endl<<endl<<endl;
    jatekos1.splitShow();//showcard aztan jatek es kartyaatadas es jatek ujra
    cout<<"   ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼"<<endl;
    jatekos3.splitShow();
    sleep(7);
    CLS();
    jatekos3.kartyaHuzas(Kartyapakli);
    jatekos2.hideCard();
    sleep(1);
    cout<<endl<<endl<<endl<<endl;
    jatekos3.showCard();
    //bj ellenorzes
    if(jatekos3.bjEllenorzes()==21)
    {
        CLS();
        jatekos2.showHidden();
        sleep(1);
        cout<<endl<<endl<<endl<<endl;
        jatekos1.showCard();
        sleep(3);
        if(jatekos2.bjEllenorzes()==21)
            jatekos3.penzkezeles(1);
        else
            jatekos3.penzkezeles(2.5);
    }
    else
    {
        while(jatekos3.bjEllenorzes()<21)
        {
            cin>>ker;
            if(ker=='w');
            else if(ker=='s')
                break;
            else
            {
                CLS();
                cout<<"Ismetelje meg kereset: ";
                sleep(0.5);
                continue;
            }
            CLS();
            jatekos2.hideCard();
            sleep(1);
            cout<<endl<<endl<<endl<<endl;
            jatekos3.kartyaHuzas(Kartyapakli);
            jatekos3.showCard();
        }
    }
    while(jatekos2.bjEllenorzes()<17)
    {
        CLS();
        jatekos2.showHidden();
        sleep(1);
        cout<<endl<<endl<<endl<<endl;
        jatekos3.showCard();
        jatekos2.kartyaHuzas(Kartyapakli);
        sleep(1.5);
    }
    CLS();
    jatekos2.showHidden();
    sleep(1);
    cout<<endl<<endl<<endl<<endl;
    jatekos3.showCard();
    sleep(5);
    if((jatekos3.bjEllenorzes()<21 and jatekos3.bjEllenorzes()>jatekos2.bjEllenorzes()) or (jatekos3.bjEllenorzes()<21 and jatekos2.bjEllenorzes()>21))
        jatekos3.penzkezeles(2);
    if(jatekos3.bjEllenorzes()==jatekos2.bjEllenorzes())
        jatekos3.penzkezeles(1);
    if(jatekos3.bjEllenorzes()==21 and jatekos2.bjEllenorzes()!=21)
        jatekos3.penzkezeles(2);
    jatekos1.nyeremenyVisszaadas(jatekos3);
    CLS();
    cout<<endl<<endl<<endl<<endl;
    jatekos1.splitShow();
    jatekos3.splitShow();
    sleep(7);
    if((jatekos1.bjEllenorzes()<21 and jatekos1.bjEllenorzes()>jatekos2.bjEllenorzes()) or (jatekos1.bjEllenorzes()<21 and jatekos2.bjEllenorzes()>21))
        throw "win";
    if(jatekos1.bjEllenorzes()==jatekos2.bjEllenorzes())
        throw "draw";
    if(jatekos1.bjEllenorzes()==21 and jatekos2.bjEllenorzes()!=21)
        throw "win";
    throw "loose";
}

void jatek()
{
    jatekos2.kartyaHuzas(Kartyapakli);
    jatekos2.hideCard();
    sleep(1);
    cout<<endl<<endl<<endl<<endl;
    jatekos1.kartyaHuzas(Kartyapakli);
    jatekos1.showCard();
    
    sleep(1);
    CLS();
    jatekos2.kartyaHuzas(Kartyapakli);
    jatekos2.hideCard();
    sleep(1);
    cout<<endl<<endl<<endl<<endl;
    jatekos1.kartyaHuzas(Kartyapakli);
    jatekos1.showCard();
    if(jatekos1.bjEllenorzes()==21)
    {
        CLS();
        jatekos2.showHidden();
        sleep(1);
        cout<<endl<<endl<<endl<<endl;
        jatekos1.showCard();
        sleep(3);
        if(jatekos2.bjEllenorzes()==21)
            throw "draw";
        else
            throw "bj";
    }
    if(jatekos2.biztositas())
    {
        CLS();
        cout<<"Szeretne biztositani a feltett osszeg feleert? (y/n) ";
        if(getyn())
        {
            //cout<<"igent nyomtal"<<endl;
            try {
                CLS();
                jatekos1.biztositas();//ez fog throw-olni ha fog
                jatekos2.hideCard();
                sleep(1);
                cout<<endl<<endl<<endl<<endl;
                jatekos1.showCard();
                //itt pedig tortenik a csoda csak idk mi az XD
            } catch (const char* nemlehet) {//ha throwol egy hibauzenetet akkor tudjuk, hogy a valasz nem ezert ugyanaz tortenik mint a nem eseten
                CLS();
                cout<<nemlehet;
                sleep(2);
                if(jatekos2.rosszdontes())
                {
                    jatekos2.showHidden();
                    cout<<endl<<endl<<endl<<endl;
                    jatekos1.showCard();
                    sleep(3);
                    throw "loose";
                }
            }
            //ezen kivul idk mit csinal ha biztositasz megint
        }
        else
        {
            CLS();
            //cout<<"nemet nyomtal"<<endl;
            if(jatekos2.rosszdontes())
            {
                jatekos2.showHidden();
                cout<<endl<<endl<<endl<<endl;
                jatekos1.showCard();
                sleep(3);
                throw "loose";
            }
        }
    }
    if(jatekos1.twoHand())
    {
        cout<<"Szeretnel 2 hand-el jatszani? (y/n) ";
        if(getyn())
        {
            CLS();
            twohandgame();
        }
    }
    char ker;
    while(jatekos1.bjEllenorzes()<21){
        cin>>ker;
        if(ker=='w');
        else if(ker=='d')
        {
            try {
                jatekos1.tetduplazas();
            } catch (const char* hibauzenet) {
                cout<<hibauzenet;
                sleep(3);
                continue;
            }
            CLS();
            jatekos2.hideCard();
            sleep(1);
            cout<<endl<<endl<<endl<<endl;
            jatekos1.kartyaHuzas(Kartyapakli);
            jatekos1.showCard();
            break;
            //ide kell egy menetet leszimulalni es befejezni is
        }
        else if(ker=='s')
            break;
        else
        {
            CLS();
            cout<<"Ismetelje meg kereset: ";
            sleep(0.5);
            continue;
        }
        //itt huzhat a jatekos kartyat
        CLS();
        jatekos2.hideCard();
        sleep(1);
        cout<<endl<<endl<<endl<<endl;
        jatekos1.kartyaHuzas(Kartyapakli);
        jatekos1.showCard();
    }
    if(jatekos1.bjEllenorzes()>21)
    {
        sleep(3);
        CLS();
        jatekos2.showHidden();
        sleep(1);
        cout<<endl<<endl<<endl<<endl;
        jatekos1.showCard();
        throw "loose";
    }
    while(jatekos2.bjEllenorzes()<17)
    {
        CLS();
        jatekos2.showHidden();
        sleep(1);
        cout<<endl<<endl<<endl<<endl;
        jatekos1.showCard();
        jatekos2.kartyaHuzas(Kartyapakli);
        sleep(1.5);
    }
    CLS();
    jatekos2.showHidden();
    sleep(1);
    cout<<endl<<endl<<endl<<endl;
    jatekos1.showCard();
    if((jatekos1.bjEllenorzes()<21 and jatekos1.bjEllenorzes()>jatekos2.bjEllenorzes()) or (jatekos1.bjEllenorzes()<21 and jatekos2.bjEllenorzes()>21))
        throw "win";
    if(jatekos1.bjEllenorzes()>21)
        throw "loose";
    if(jatekos1.bjEllenorzes()<21 and jatekos2.bjEllenorzes()<=21 and jatekos1.bjEllenorzes()<jatekos2.bjEllenorzes())
        throw "loose";
    if(jatekos1.bjEllenorzes()==jatekos2.bjEllenorzes())
        throw "draw";
    if(jatekos1.bjEllenorzes()==21 and jatekos2.bjEllenorzes()!=21)
        throw "win";
}

void jatekmenet()
{
    while(true)
    for(int i=0;i<1;i++)
    {
        CLS();
        cout<<jatekos1.listazPenz()<<"$"<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"Add meg a tetet: ";
        int feltettPenz=0;
        while(true)//vegtelen ciklus ami addig keri be a tetet ameddig helyes erteket nem irunk be
        {
            cin>>feltettPenz;
            CLS();
            if(jatekos1.listazPenz()<feltettPenz)
            {
                feltettPenz=0;
                cout<<"Helytelen mennyiseg.. nincs ennyi penzed :/"<<endl<<"Add meg ujra: ";
            }
            else
            {
                jatekos1.tet(feltettPenz);
                try {
                    jatek();
                } catch (const char* jatekKimenetel) {
                    CLS();
                    cout<<jatekKimenetel;
                    sleep(4);
                    if(strcmp(jatekKimenetel,"win")==0)
                    {
                        jatekos1.penzkezeles(2);
                    }
                    else if(strcmp(jatekKimenetel,"draw")==0)
                    {
                        jatekos1.penzkezeles(1);
                    }
                    else if(strcmp(jatekKimenetel,"bj")==0)
                    {
                        jatekos1.penzkezeles(2.5);
                    }
                }
                jatekos1.kezUrites();
                jatekos2.kezUrites();
                break;
            }
        }
        if(jatekos1.listazPenz()==0)
        {
            CLS();
            cout<<":("<<endl;
            exit(1);
        }
        if(Kartyapakli.size()<=10)
        {
            CLS();
            cout<<"A kartyapaklit ujra kell keverni.."<<endl;
            sleep(10);
            jatekos2.ujrakeveres(Kartyapakli);
        }
    }
}

int main() {
    CLS();
    kezdes();
    jatekmenet();
    return 0;
}
