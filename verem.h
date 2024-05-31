#ifndef _DINAMIKUS_VEREM_H_
#define _DINAMIKUS_VEREM_H_
#include <string>
using namespace std;
class verem {
    struct tarolo//a verem tarolo egysegei/ verem tagjai
    {
        int ertek;
        string szimbolum;
        tarolo* elfedettLap;//veremben az elotte levo elemre mutato
    };
    
    tarolo* legujabb;
    int kartyaszam;
    
public:
    verem();// ez atirhato helyben megoldhatora is
    
    verem(int*, string*, int); //a kartyak minden ertekenek, szimbolumanak elofordulasa es a pakli merete
    
    ~verem();

    void push(int, string);//a ket valtozot beteszi a verembe

    void pop(int&, string&);//visszaadja a ket valtozoban a pop-olt elemet
    
    void pusha(int, vector<int>, vector<string>);//betesz a verembe egy kartyapaklit amit a ket vektor altal adunk meg
    
    void print();//kiirja a verem osszes tagjat a verem tetejetol indulva
    
    void clear();//kiuriti a vermet
    
    bool isEmpty();
    
    int size();
};
#endif
