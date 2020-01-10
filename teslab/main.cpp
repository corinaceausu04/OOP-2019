#include <iostream>

using namespace std;
class candidati
{
protected:
    string *nume;
    float medie_bac;
    int nr_inregistrare = 0; //static int??
public:
    candidati();
    candidati(const candidati &);
    ~candidati();
    friend istream & operator >>(istream &, candidati &);
    friend ostream & operator <<(ostream &, candidati &);
    candidati & operator ++ ();
};

istream & operator >>(istream & in, candidati &ob)
{
    cout<<"Introduceti numele si prenumele: ";
    ob.nume = new string [3];
    for(int i=0; i<2; i++)
        in>>ob.nume[i];
    cout<<"Introduceti media bac: ";
    in>>ob.medie_bac;
    ob.nr_inregistrare ++;
    return in;

}
ostream & operator <<(ostream & out, candidati &ob)
{
    for(int i=0; i<2; i++)
        out<<ob.nume[i]<<" ";
    out<<"\n";
    out<<ob.medie_bac<<"\n";
    out<<"Numarul de inregistrare: "<<ob.nr_inregistrare<<"\n";
    return out;
}
candidati::candidati()
{
    nume = new string[3];
    for(int i=0; i<2; i++)
        nume[i] = " ";
    medie_bac = 0;
}
candidati::candidati(const candidati &a)
{
    nume = new string[3];
    for(int i=0; i<2; i++)
        nume = a.nume;
    medie_bac = a.medie_bac;
}

candidati::~candidati()
{
    for(int i=0; i<2; i++)
        delete []nume;
}

class ID:candidati
{
    float nota_mate_bac;
    float nota_proba_orala;
    float medie;
public:
    void citire(candidati &);
    float calcul_medie();
    void afisare(candidati &);
    void afisare_admisi(candidati &a);
};

void ID::citire(candidati &a)
{
    cin>>a;
    cout<<"Nota mate bac: ";
    cin>>nota_mate_bac;
    cout<<"Nota proba orala: ";
    cin>>nota_proba_orala;

}
float ID::calcul_medie()
{
    medie = 0.6*nota_proba_orala + 0.4*nota_mate_bac;
    return medie;
}
void ID::afisare(candidati &a)
{
    cout<<a;
    cout<<"Nota mate bac este: "<<nota_mate_bac<<endl;
    cout<<"Nota proba orala: "<<nota_proba_orala<<endl;
    cout<<"Media: "<<medie<<endl;
}
void ID::afisare_admisi(candidati &a)
{
    if(medie >= 5)
    cout<<a;
    cout<<"Nota mate bac este: "<<nota_mate_bac<<endl;
    cout<<"Nota proba orala: "<<nota_proba_orala<<endl;
    cout<<"Media: "<<medie<<endl;

}
class IF:candidati
{
    float nota_proba_scrisa;
    float bac;
    float medie;
public:
    float calcul_medie();
    void citire(candidati &a);
    void afisare(candidati &a);
    void afisare_admisi(candidati &a);
};
float IF::calcul_medie()
{
    medie = 0.8 * nota_proba_scrisa + 0.2*bac;
    return medie;
}
void IF::citire(candidati &a)
{
    cin>>a;
    cout<<"Nota proba scrisa: ";
    cin>>nota_proba_scrisa;
    cout<<"Nota bac: ";
    cin>>bac;
}
void IF::afisare(candidati &a)
{
    cout<<a<<endl;
    cout<<"Nota proba scrisa este: "<<nota_proba_scrisa<<endl;
    cout<<"Media este: "<<medie<<endl;
}
void IF::afisare_admisi(candidati &a)
{
    if(medie >= 5)
    {
        cout<<a;
    }

}

class ID2:candidati
{
    string domeniu_absolvit;
    float nota_proba_orala;
    float nota_absolvire_prima_facultate;
    float medie;
public:
    void citire(candidati &a);
    float calcul_medie();
    void afisare(candidati &a);
    void afisare_admisi(candidati &a);
};
void ID2::afisare_admisi(candidati &a)
{
    if(medie >= 5)
    {
        cout<<a;
    }
}
void ID2::citire(candidati &a)
{
    cin>>a;
    cout<<"Domeniul absolvit: ";
    cin>>domeniu_absolvit;
    cout<<"Nota proba orala: ";
    cin>>nota_proba_orala;
    cout<<"Nota absolvire prima facultate: ";
    cin>>nota_absolvire_prima_facultate;
}
void ID2::afisare(candidati &a)
{
    cout<<a;
    cout<<medie;
}
float ID2::calcul_medie()
{
    medie = 0.6 * nota_proba_orala + 0.4*nota_absolvire_prima_facultate;
    return medie;

}
class IF2:candidati
{
    string domeniu_absolvit;
    float nota_proba_orala;
    float nota_absolvire_prima_facultate;
    float medie;
public:
    void citire(candidati &a);
    float calcul_medie();
    void afisare(candidati &a);
    void afisare_admisi(candidati &a);
};
void IF2::citire(candidati &a)
{
    cin>>a;
    cout<<"Domeniul absolvit: ";
    cin>>domeniu_absolvit;
    cout<<"Nota proba orala: ";
    cin>>nota_proba_orala;
    cout<<"Nota absolvire prima facultate: ";
    cin>>nota_absolvire_prima_facultate;
}
void IF2::afisare(candidati &a)
{
    cout<<a;
    cout<<medie;
}
float IF2::calcul_medie()
{
    medie = 0.6 * nota_proba_orala + 0.4*nota_absolvire_prima_facultate;
    return medie;

}
void IF2::afisare_admisi(candidati &a)
{
    if(medie >= 5)
    {
        cout<<a;
    }

}

void lista_IF()
{
    int m;
    cout<<"Introduceti nr de candidati la IF: ";
    cin>>m;
    candidati *obiecte = new candidati[m];
    IF *candid_if = new IF[m];
    for(int i=0; i<m; i++)
    {candid_if[i].citire(obiecte[i]);
    candid_if[i].calcul_medie();}
    cout<<"Lista candidati inscrisi la IF: "<<endl;
    for(int i=0; i<m; i++)
   {
    candid_if[i].afisare(obiecte[i]);
    }
    cout<<"Candidatii admisi sunt: ";
    for(int i=0; i<m; i++)
   {
    candid_if[i].afisare_admisi(obiecte[i]);
    }
}
void lista_ID()
{
    int m;
    cout<<"Introduceti nr de candidati la ID: ";
    cin>>m;
    candidati *obiecte = new candidati[m];
    ID *candid_id = new ID[m];
    for(int i=0; i<m; i++)
    {candid_id[i].citire(obiecte[i]);
    candid_id[i].calcul_medie();}
    cout<<"Lista candidati inscrisi la ID: "<<endl;
    for(int i=0; i<m; i++)
   {
    candid_id[i].afisare(obiecte[i]);
    }
    cout<<"Candidatii admisi sunt: ";
    for(int i=0; i<m; i++)
   {
    candid_id[i].afisare_admisi(obiecte[i]);
    }
}
void lista_candidati()
{
    int n;
    cout<<"Introduceti nr de candidati: ";
    cin>>n;
    candidati *obiecte = new candidati[n];
    for(int i=0; i<n ;i++)
            cin>>obiecte[i];
        for(int i=0; i<n; i++)
            cout<<obiecte[i];
}
int main()
{
    ///Ceausu Corina-Georgiana, grupa 253, Codeblocks
    int opt =5;
    while(opt != 4)
     {
        cout<<"1.Introducere si afisare candidati.\n2.Introducere si afisare candidati ID + admisi ID.\n3.Introducere si afisare candidati IF +admisi IF\n";
        cout<<"Introduceti optiunea: ";
        cin>>opt;
    switch(opt)
    {
    case 1:
        lista_candidati();
        break;
    case 2:
        lista_ID();
        break;
    case 3:
        lista_IF();
        break;
    }
    }

    return 0;
}
