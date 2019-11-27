#include <iostream>
#include <string>
#include <fstream>
#define NULL 0
using namespace std;
ifstream f("lista_cumparaturi");
std::ofstream out;

class Produse{
protected:
    float pret;
    float cost;
    int stoc;
    char raspuns;
public:
    Produse();
    Produse(const Produse &a);
    ~Produse();
    friend istream & operator >> (istream &, Produse &);
    friend ostream & operator << (ostream &, Produse &);
    Produse& operator = (const Produse &ob);
    virtual int calcul_cost(){return cost;}
};

istream & operator >> (istream &in, Produse &ob){
    in>>ob.pret;
    in>>ob.cost;
    in>>ob.stoc;
    return in;
}
ostream & operator << (ostream &out, Produse &ob){
    out<<ob.pret;
    out<<ob.cost;
    out<<ob.stoc;}
Produse& Produse::operator = (const Produse &ob){
    this->cost = ob.cost;
    this->pret = ob.pret;
    this->stoc = ob.stoc;
}
Produse::~Produse(){
    this->pret = 0;
    this-> cost = 0;
    this ->stoc = 0;
}
Produse::Produse(const Produse &a){   //constructor de copiere
    this->pret = a.pret;
    this->cost = a.cost;
    this->stoc = a.stoc;
}
Produse::Produse(){          //constructor de initializare cu 0
    this->pret = 0;
    this->cost = 0;
    this->stoc = 0;
}
class Varza: public Produse{
    int nr_bucati;
public:
    Varza();
    Varza(cost Varza &v);
    int calcul_cost();
};
class Faina: public Produse{
    int nr_kg;
    int calitate;
public:
    int calcul_cost();
};
class Bere: public Produse{
    int nr_bucati;
    string brand;
public:
    int calcul_cost();
};
class Cartofi: public Produse{
    int nr_kg;
    string tip;
public:
    int calcul_cost();

};
class Vin_varsat: public Produse{
    int litri;
    string tip;
public:
    int calcul_cost();
};
class vin_soi: public Produse{
    int buc;
    string soi;
    int an_culegere;
    string tara_origine;
public:
    int calcul_cost();
};
class Jucarii: public Produse{
    int nr_bucati;
    string nume;
public:
    int calcul_cost();
};
int Jucarii::calcul_cost(){
    f>>nume;
    f>>nr_bucati;
    if(nume == "Lego")
       {
           pret = 50;
           stoc = 10;}
    else if(nume == "Masinuta")
        {pret = 30;
        stoc = 20;}
    else if(nume == "Papusa Barbie")
        {pret == 60;
        stoc = 15;}
    else if(nume == "Trenulet")
        {pret == 100;
        stoc = 30;}
    else
        cout<<"Produsul nu este in stoc."<<endl;
    if(nr_bucati > stoc)
        {cout<<"In stoc exista doar "<<stoc<<" de bucati de"<<nume<<". Doriti sa cumparati "<< stoc << " de bucati?"<<endl;
            cin>>raspuns;
        if(raspuns == 'd')
            cost = pret * stoc;
        else if (raspuns == 'n')
            cost = 0;}
    else
        for(int i=0; i<nr_bucati; i++)
        cost = pret * nr_bucati;
    cout<<cost;
    return cost;


}
int Cartofi::calcul_cost(){
    f>>nr_kg;
    f>>tip;
    if(tip == "rosii")
        {pret = 2;
        stoc = 50;}
    else if(tip == "albi")
        {pret == 3;
        stoc = 100;}
    else if(tip.empty())
        tip = "rosii";
    if(nr_kg > stoc)
        {cout<<"In stoc exista doar "<<stoc<<" de kilograme de cartofi "<<tip<<". Doriti sa cumparati "<< stoc << " de kilograme?"<<endl;
            cin>>raspuns;
        if(raspuns == 'd')
            cost = pret * stoc;
        else if (raspuns == 'n')
            cost = 0;}
    else
        for(int i=0; i<nr_kg; i++)
        cost = nr_kg * pret;
    cout<<cost<<endl;
    return cost;
}
int Bere::calcul_cost(){
    f>>nr_bucati;
    f>>brand;
    if(brand == "peroni")
        {pret = 5;
        stoc = 100;}
    else if(brand == "tuborg")
        {pret = 3;
        stoc = 200;}
    else if(brand.empty())
        brand = "tuborg";
    else cout<<"Produsul nu este in stoc."<<endl;
     if(nr_bucati > stoc)
        {cout<<"In stoc exista doar "<<stoc<<" de bucati de bere "<<brand<<". Doriti sa cumparati "<< stoc << " de bucati?"<<endl;
            cin>>raspuns;
        if(raspuns == 'd')
            cost = pret * stoc;
        else if (raspuns == 'n')
            cost = 0;}
    else
        for(int i=0; i<nr_bucati; i++)
            cost = pret * nr_bucati;
    cout<<"Costul pentru bere este: "<<cost<<endl;
    return cost;
}
int Faina::calcul_cost(){
    f>>nr_kg;
    f>>calitate;
    if(calitate == 1)
        {pret = 5;
        stoc =20;}
    else if(calitate == 2)
        {pret = 3;
        stoc = 30;}
    else if(calitate == 3)
        {pret = 2;
        stoc = 40;}
    else if(calitate ==NULL)
        calitate = 1;
    if(nr_kg > stoc)
        {cout<<"In stoc exista doar "<<stoc<<" de kilograme de faina, calitatea "<<calitate<<". Doriti sa cumparati "<< stoc << " de kilograme?"<<endl;
            cin>>raspuns;
        if(raspuns == 'd')
            cost = pret * stoc;
        else if (raspuns == 'n')
            cost = 0;}
    else
        for(int i=0; i<nr_kg; i++)
            cost = pret * nr_kg;
    cout<<"Costul pentru faina este: "<<cost<<endl;
    return cost;
}
int Varza::calcul_cost(){
    f>>nr_bucati;
    pret = 5;
    stoc = 50;
    if(nr_bucati <= stoc)
    for(int i=1; i<=nr_bucati; i++)
            cost = nr_bucati * pret;
    if(nr_bucati > stoc)
        {cout<<"In stoc exista doar "<<stoc<<" de bucati de varza. Doriti sa cumparati "<< stoc << " de bucati?"<<endl;
            cin>>raspuns;
        if(raspuns == 'd')
            cost = pret * stoc;
        else if (raspuns == 'n')
            cost = 0;
        }
    else
        for(int i=0; i<nr_bucati; i++)
            cost = pret *nr_bucati;

    cout<<"Costul pentru toate bucatile de varza este: "<<cost<<endl;
    return cost;
}
int Vin_varsat::calcul_cost(){
    f>>tip;
    f>>litri;
    if(tip == "rosu_sec")
        {pret = 10;
        stoc = 50;}
    else if(tip == "alb_sec")
       {pret = 12;
       stoc = 100;}
    else if(tip.empty())
        tip = "rosu_sec";
   if(litri > stoc)
        {cout<<"In stoc exista doar "<<stoc<<" de litri de vin "<<tip<<". Doriti sa cumparati "<< stoc << " de bucati?"<<endl;
            cin>>raspuns;
        if(raspuns == 'd')
            cost = pret * stoc;
        else if (raspuns == 'n')
            cost = 0;}
    else
        for(int i=0; i<litri; i++)
        cost = pret * litri;
    cout<<cost;
    return cost;
}
int vin_soi::calcul_cost(){
    f>>buc;
    f>>soi;
    f>>an_culegere;
    f>>tara_origine;

    if(soi == "Cabernet Savignon")
       {
           stoc = 100;
           if(an_culegere<1950)
            {
                if(tara_origine == "Franta")
                    pret = 100;
                else if(tara_origine == "Argentina")
                    pret = 120;
                else if(tara_origine == "Chile")
                    pret == 150;
                else if(tara_origine == "Australia")
                    pret == 200;
                else
                    cout<<"Produsul nu este in stoc."<<endl;
            }

        else if(an_culegere>=1950)
                {if(tara_origine == "Franta")
                    pret = 50;
                else if(tara_origine == "Argentina")
                    pret = 60;
                else if(tara_origine == "Chile")
                    pret == 70;
                else if(tara_origine == "Australia")
                    pret == 80;
                else
                    cout<<"Produsul nu este in stoc."<<endl;
                    }
       }
    else if(soi == "Merlot")
        {   stoc = 70;
            if(an_culegere<1950)
            {
                if(tara_origine == "Franta")
                    pret = 200;
                else if(tara_origine == "Argentina")
                    pret = 220;
                else if(tara_origine == "Chile")
                    pret == 250;
                else if(tara_origine == "Australia")
                    pret == 300;
                else
                    cout<<"Produsul nu este in stoc."<<endl;
            }
        else if(an_culegere>=1950)
                {if(tara_origine == "Franta")
                    pret = 150;
                else if(tara_origine == "Argentina")
                    pret = 160;
                else if(tara_origine == "Chile")
                    pret == 170;
                else if(tara_origine == "Australia")
                    pret == 180;}
                else
                    cout<<"Produsul nu este in stoc."<<endl;
                    }
    else if(soi == "Savignon Blanc")
       {    stoc = 40;
           if(an_culegere<1950)
            {
                if(tara_origine == "Franta")
                    pret = 300;
                else if(tara_origine == "Argentina")
                    pret = 320;
                else if(tara_origine == "Chile")
                    pret == 350;
                else if(tara_origine == "Australia")
                    pret == 300;
                else
                    cout<<"Produsul nu este in stoc."<<endl;
            }
        else if(an_culegere>=1950)
                {if(tara_origine == "Franta")
                    pret = 250;
                else if(tara_origine == "Argentina")
                    pret = 260;
                else if(tara_origine == "Chile")
                    pret == 270;
                else if(tara_origine == "Australia")
                    pret == 280;}
                else
                    cout<<"Produsul nu este in stoc."<<endl;
                    }
    else if(soi == "Chardonnay")
       {    stoc = 30;
           if(an_culegere<1950)
            {
                if(tara_origine == "Franta")
                    pret = 400;
                else if(tara_origine == "Argentina")
                    pret = 420;
                else if(tara_origine == "Chile")
                    pret == 450;
                else if(tara_origine == "Australia")
                    pret == 500;
                else
                    cout<<"Produsul nu este in stoc."<<endl;
            }
        else if(an_culegere>=1950)
                {if(tara_origine == "Franta")
                    pret = 350;
                else if(tara_origine == "Argentina")
                    pret = 360;
                else if(tara_origine == "Chile")
                    pret == 370;
                else if(tara_origine == "Australia")
                    pret == 380;
                else
                    cout<<"Produsul nu este in stoc."<<endl;}}

        else
            {soi = "Cabernet Savignon";
               an_culegere = 1960;
               tara_origine = "Franta";
               pret = 50;}

    if(buc > stoc)
        {cout<<"In stoc exista doar "<<stoc<<" de bucati de vin. Doriti sa cumparati "<< stoc << " de bucati?"<<endl;
            cin>>raspuns;
        if(raspuns == 'd')
            cost = pret * stoc;
        else if (raspuns == 'n')
            cost = 0;}
    else
        for(int i=0; i<buc; i++)
        cost = pret * buc;
        cout<<"Costul pentru vinul de soi este "<<cost<<endl;
        return cost;
}

int main()
{
    int buget_magazin = 0;
    int i, n=4, s=0,total = 0,vec[100]= {0};
    string a[100];
    Produse p;
    Varza varza;
    Faina faina;
    Bere bere;
    Cartofi cartofi;
    Jucarii jucarii;
    Vin_varsat varsat;
    vin_soi soi;
    for(i=0; i<n; i++)
    {f>>a[i];
    //cout<<a[i]<<" "<<endl;
    if(a[i] == "varza")
        vec[i] = varza.calcul_cost();
    if(a[i] == "faina")
        vec[i] = faina.calcul_cost();
    if(a[i] == "vin_soi")
        vec[i] = soi.calcul_cost();
    if(a[i]=="bere")
        vec[i] = bere.calcul_cost();
    if(a[i]=="vin_varsat")
        vec[i] = varsat.calcul_cost();
    if(a[i]=="jucarie")
        vec[i] = jucarii.calcul_cost();
    if(a[i]=="cartofi")
        vec[i] = cartofi.calcul_cost();
    total = total + vec[i];
        }
        cout<<"Totalul pentru cumparaturile efectuate este: " <<total << "lei"<<endl;
        cout<<"Doriti sa cumparati?"<<endl;
        char rasp;
        cin>>rasp;
        if(rasp == 'd')
            buget_magazin = buget_magazin + total;
        cout<<"Bugetul magazinului este: "<<buget_magazin;
        out.open("inventar",std::ios::app);
        out<<buget_magazin;
        out<<"\n";


    return 0;
}
