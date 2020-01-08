#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

class Produs
{
    int id_produs;
public:
    virtual float calcul_pret()=0;
    virtual void Afisare()=0;
};
class Pizza: public Produs
{
protected:
    int nr_ingrediente;
    string denumire[100];
    float cantitate[100];
    float pret[100];
    float cost = 0;
    const int manopera = 10;
public:
    Pizza();
    Pizza(int nr_ingr, string den[100], float cantit[100]);
    Pizza(const Pizza &);
    Pizza& operator = (const Pizza &);
    ~Pizza();
    friend void Citire(Pizza& ob);
    void Afisare();
    friend ostream & operator << (ostream &, Pizza &);
    friend istream & operator >> (istream &, Pizza &);
    float calcul_pret()
    {
        string tip_comanda;
        float distanta;
        cout<<"Online sau offline?"<<endl;
        cin>>tip_comanda;
        if(tip_comanda == "offline")
        {
            int s = 0;
            for(int i=0; i<nr_ingrediente; i++)
                s = s + pret[i] * cantitate[i];
            cost = s + manopera;
        }
        else if(tip_comanda == "online")
            {
                cout<<"Introduceti distanta: ";
                cin>>distanta;
                int s = 0;
                for(int i=0; i<nr_ingrediente; i++)
                    s = s + pret[i] * cantitate[i];
                cost = s + manopera;
                int dis;
                dis = 0.05 * cost * distanta;
                cost = cost + dis;
            }

        cout<< cost;
        return cost;
    }

};
Pizza::Pizza()
{
    this->nr_ingrediente = 0;
    for(int i=0; i>nr_ingrediente; i++)
    {
        denumire[i] = "";
        cantitate[i] = 0;
    }
}
Pizza::Pizza(int nr_ingr, string den[100], float cantit[100])
{
    this->nr_ingrediente = nr_ingr;
    for(int i=0; i<nr_ingr; i++)
    {
        this->denumire[i] = den[i];
        this->cantitate[i] = cantit[i];
    }
}
Pizza::Pizza(const Pizza &ob)
{
    this->nr_ingrediente = ob.nr_ingrediente;
    for(int i=0; i<nr_ingrediente; i++)
        {
            this->denumire[i] = ob.denumire[i];
            this->cantitate[i] = ob.cantitate[i];
        }

}
Pizza::~Pizza(){};
Pizza& Pizza::operator = (const Pizza &ob)
{
    if(this != &ob)
        {
            this->nr_ingrediente = ob.nr_ingrediente;
            for(int i=0; i<nr_ingrediente; i++)
            {
                this->denumire[i] = ob.denumire[i];
                this->cantitate[i] = ob.cantitate[i];
            }
        }
}
void Citire(Pizza& ob)
{
    {
        cout<<"Introduceti nr de ingrediente: ";
        cin>>ob.nr_ingrediente;
        cout<<"Ingredientele disponibile sunt: mozarella, sos, pui, ciuperci, sunca, ton."<<endl;
        cout<<"Introduceti denumirea si cantitatea fiecarui ingredient: ";
        for(int i=0; i < ob.nr_ingrediente ; i++)
        {
            cin>>ob.denumire[i];
            cin>>ob.cantitate[i];
            try
            {
                if(ob.denumire[i] == "mozarella")
                    ob.pret[i] = 5;
                else if(ob.denumire[i] == "sos")
                    ob.pret[i] = 0.2;
                else if(ob.denumire[i] == "pui")
                    ob.pret[i] = 10;
                else if(ob.denumire[i] == "ciuperci")
                    ob.pret[i] = 2;
                else if(ob.denumire[i] == "sunca")
                    ob.pret[i] = 7;
                else if(ob.denumire[i] == "ton")
                    ob.pret[i] = 10;
                else
                    throw ob.denumire[i];
            }
            catch(string excp)
            {
                while(ob.denumire[i] != "mozarella" || ob.denumire[i] != "sos" || ob.denumire[i] != "pui" || ob.denumire[i] != "ciuperci" || ob.denumire[i] != "sunca" || ob.denumire[i] != "ton")
                    {
                        cout<<"Ingredientul nu exista. Introduceti un ingredient existent: ";
                        cin>>ob.denumire[i];
                    }
                if(ob.denumire[i] == "mozarella")
                    ob.pret[i] = 5;
                else if(ob.denumire[i] == "sos")
                    ob.pret[i] = 0.2;
                else if(ob.denumire[i] == "pui")
                    ob.pret[i] = 10;
                else if(ob.denumire[i] == "ciuperci")
                    ob.pret[i] = 2;
                else if(ob.denumire[i] == "sunca")
                    ob.pret[i] = 7;
                else if(ob.denumire[i] == "ton")
                    ob.pret[i] = 10;

            }
        }
    }
}
void Pizza::Afisare(){
    cout<<"Numarul de ingrediente: "<<this->nr_ingrediente<<endl;
    for(int i=0; i<nr_ingrediente; i++)
    {
        cout<<"Denumirea ingredientului: "<<this->denumire[i]<< "\nCantitate: "<<this->cantitate[i]<<endl;
    }


}
istream & operator >> (istream &in, Pizza &ob)
{
    {
        cout<<"Introduceti nr de ingrediente: ";
        in>>ob.nr_ingrediente;
        cout<<"Ingredientele disponibile sunt: mozarella, sos, pui, ciuperci, sunca, ton."<<endl;
        cout<<"Introduceti denumirea si cantitatea fiecarui ingredient: ";
        for(int i=0; i<ob.nr_ingrediente; i++)
        {
            in>>ob.denumire[i];
            in>>ob.cantitate[i];
            try
            {
                if(ob.denumire[i] == "mozarella")
                    ob.pret[i] = 5;
                else if(ob.denumire[i] == "sos")
                    ob.pret[i] = 0.2;
                else if(ob.denumire[i] == "pui")
                    ob.pret[i] = 10;
                else if(ob.denumire[i] == "ciuperci")
                    ob.pret[i] = 2;
                else if(ob.denumire[i] == "sunca")
                    ob.pret[i] = 7;
                else if(ob.denumire[i] == "ton")
                    ob.pret[i] = 10;
                else
                    throw ob.denumire[i];
            }
            catch(string excp)
            {
                while(ob.denumire[i] != "mozarella" && ob.denumire[i] != "sos" && ob.denumire[i] != "pui" && ob.denumire[i] != "ciuperci" && ob.denumire[i] != "sunca" && ob.denumire[i] != "ton")
                    {
                        cout<<"Ingredientul nu exista. Introduceti un ingredient existent: ";
                        in>>ob.denumire[i];
                    }
                      if(ob.denumire[i] == "mozarella")
                            ob.pret[i] = 5;
                        else if(ob.denumire[i] == "sos")
                            ob.pret[i] = 0.2;
                        else if(ob.denumire[i] == "pui")
                            ob.pret[i] = 10;
                        else if(ob.denumire[i] == "ciuperci")
                            ob.pret[i] = 2;
                        else if(ob.denumire[i] == "sunca")
                            ob.pret[i] = 7;
                        else if(ob.denumire[i] == "ton")
                            ob.pret[i] = 10;

            }
        }
    }
}
ostream & operator << (ostream &out, Pizza &ob)
{
      out<<"Numarul de ingrediente: "<<ob.nr_ingrediente<<endl;
    for(int i=0; i<ob.nr_ingrediente; i++)
    {
        out<<"Denumirea ingredientului: "<<ob.denumire[i]<< "\nCantitate: "<<ob.cantitate[i]<<endl;
    }
    return out;
}
class Prajitura: public Produs{
protected:
    int nr_ingrediente;
    string denumire[100];
    float cantitate[100];
    float pret[100];
    float cost = 0;
    const int manopera = 10;
public:
    Prajitura();
    Prajitura(int nr_ingr, string den[100], float cantit[100]);
    Prajitura(const Prajitura &);
    //Prajitura& operator = (const Prajitura &);
    ~Prajitura();
    friend void Citire_prajituri(Prajitura& ob);
    void Afisare();
    friend ostream & operator << (ostream &, Prajitura &);
    friend istream & operator >> (istream &, Prajitura &);
    float calcul_pret()
    {
        string tip_comanda;
        float distanta;
        cout<<"Online sau offline?"<<endl;
        cin>>tip_comanda;
        if(tip_comanda == "offline")
        {
            int s = 0;
            for(int i=0; i<nr_ingrediente; i++)
                s = s + pret[i] * cantitate[i];
            cost = s + manopera;
        }
        else if(tip_comanda == "online")
            {
                cout<<"Introduceti distanta: ";
                cin>>distanta;
                int s = 0;
                for(int i=0; i<nr_ingrediente; i++)
                    s = s + pret[i] * cantitate[i];
                cost = s + manopera;
                int dis;
                dis = 0.05 * cost * distanta;
                cost = cost + dis;
            }

        cout<< cost;
        return cost;
    }
};
Prajitura::Prajitura()
{
    this->nr_ingrediente = 0;
    for(int i=0; i>nr_ingrediente; i++)
    {
        denumire[i] = "";
        cantitate[i] = 0;
    }
}
Prajitura::Prajitura(int nr_ingr, string den[100], float cantit[100])
{
    this->nr_ingrediente = nr_ingr;
    for(int i=0; i<nr_ingr; i++)
    {
        this->denumire[i] = den[i];
        this->cantitate[i] = cantit[i];
    }
}
Prajitura::Prajitura(const Prajitura &ob)
{
    this->nr_ingrediente = ob.nr_ingrediente;
    for(int i=0; i<nr_ingrediente; i++)
        {
            this->denumire[i] = ob.denumire[i];
            this->cantitate[i] = ob.cantitate[i];
        }
}
Prajitura::~Prajitura(){}
istream & operator >> (istream &in, Prajitura &ob)
{
    {
        cout<<"Introduceti nr de ingrediente: ";
        in>>ob.nr_ingrediente;
        cout<<"Ingredientele disponibile sunt: ciocolata, vanilie si fructe."<<endl;
        cout<<"Introduceti denumirea si cantitatea fiecarui ingredient: ";
        for(int i=0; i<ob.nr_ingrediente; i++)
        {
            in>>ob.denumire[i];
            in>>ob.cantitate[i];
            try
            {
                if(ob.denumire[i] == "ciocolata")
                    ob.pret[i] = 5;
                if(ob.denumire[i] == "vanilie")
                    ob.pret[i] = 6;
                if(ob.denumire[i] == "fructe")
                    ob.pret[i] = 10;
                else
                    throw ob.denumire[i];
            }
            catch(string excp)
            {
                while(ob.denumire[i] != "ciocolata" && ob.denumire[i] != "vanilie" && ob.denumire[i] != "fructe")
                    {
                        cout<<"Ingredientul nu exista. Introduceti un ingredient existent: ";
                        in>>ob.denumire[i];
                    }
                        if(ob.denumire[i] == "ciocolata")
                            ob.pret[i] = 5;
                        if(ob.denumire[i] == "vanilie")
                            ob.pret[i] = 6;
                        if(ob.denumire[i] == "fructe")
                            ob.pret[i] = 10;

            }
        }
    }
}
ostream & operator << (ostream &out, Prajitura &ob)
{
      out<<"Numarul de ingrediente: "<<ob.nr_ingrediente<<endl;
    for(int i=0; i<ob.nr_ingrediente; i++)
    {
        out<<"Denumirea ingredientului: "<<ob.denumire[i]<< "\nCantitate: "<<ob.cantitate[i]<<endl;
    }
    return out;
}
void Citire_prajituri(Prajitura &ob)
{
     {
        cout<<"Introduceti nr de ingrediente: ";
        cin>>ob.nr_ingrediente;
        cout<<"Ingredientele disponibile sunt: ciocolata, vanilie si fructe."<<endl;
        cout<<"Introduceti denumirea si cantitatea fiecarui ingredient: ";
        for(int i=0; i<ob.nr_ingrediente; i++)
        {
            cin>>ob.denumire[i];
            cin>>ob.cantitate[i];
            try
            {
                if(ob.denumire[i] == "ciocolata")
                    ob.pret[i] = 5;
                if(ob.denumire[i] == "vanilie")
                    ob.pret[i] = 6;
                if(ob.denumire[i] == "fructe")
                    ob.pret[i] = 10;
                else
                    throw ob.denumire[i];
            }
            catch(string excp)
            {
                while(ob.denumire[i] != "ciocolata" && ob.denumire[i] != "vanilie" && ob.denumire[i] != "fructe")
                    {
                        cout<<"Ingredientul nu exista. Introduceti un ingredient existent: ";
                        cin>>ob.denumire[i];
                    }
                        if(ob.denumire[i] == "ciocolata")
                            ob.pret[i] = 5;
                        if(ob.denumire[i] == "vanilie")
                            ob.pret[i] = 6;
                        if(ob.denumire[i] == "fructe")
                            ob.pret[i] = 10;

            }
        }
    }
}
void Prajitura::Afisare(){
    cout<<"Numarul de ingrediente: "<<this->nr_ingrediente<<endl;
    for(int i=0; i<nr_ingrediente; i++)
    {
        cout<<"Denumirea ingredientului: "<<this->denumire[i]<< "\nCantitate: "<<this->cantitate[i]<<endl;
    }
}

class Pizza_vegetariana: public Produs
{
protected:
    int nr_ingrediente;
    string denumire[100];
    float cantitate[100];
    float pret[100];
    float cost = 0;
    const int manopera = 10;
public:
    Pizza_vegetariana();
    Pizza_vegetariana(int nr_ingr, string den[100], float cantit[100]);
    Pizza_vegetariana(const Pizza_vegetariana &);
    Pizza_vegetariana& operator = (const Pizza_vegetariana &);
    ~Pizza_vegetariana();
    friend void Citire_vegetariana(Pizza_vegetariana& ob);
    void Afisare();
    friend ostream & operator << (ostream &, Pizza_vegetariana &);
    friend istream & operator >> (istream &, Pizza_vegetariana &);
    float calcul_pret()
    {
        string tip_comanda;
        float distanta;
        cout<<"Online sau offline?"<<endl;
        cin>>tip_comanda;
        if(tip_comanda == "offline")
        {
            int s = 0;
            for(int i=0; i<nr_ingrediente; i++)
                s = s + pret[i] * cantitate[i];
            cost = s + manopera;
        }
        else if(tip_comanda == "online")
            {
                cout<<"Introduceti distanta: ";
                cin>>distanta;
                int s = 0;
                for(int i=0; i<nr_ingrediente; i++)
                    s = s + pret[i] * cantitate[i];
                cost = s + manopera;
                int dis;
                dis = 0.05 * cost * distanta;
                cost = cost + dis;
            }

        cout<< cost;
    }
};
Pizza_vegetariana::Pizza_vegetariana()
{
    this->nr_ingrediente = 0;
    for(int i=0; i>nr_ingrediente; i++)
    {
        denumire[i] = "";
        cantitate[i] = 0;
    }
}
Pizza_vegetariana::Pizza_vegetariana(int nr_ingr, string den[100], float cantit[100])
{
    this->nr_ingrediente = nr_ingr;
    for(int i=0; i<nr_ingr; i++)
    {
        this->denumire[i] = den[i];
        this->cantitate[i] = cantit[i];
    }
}
Pizza_vegetariana::Pizza_vegetariana(const Pizza_vegetariana &ob)
{
    this->nr_ingrediente = ob.nr_ingrediente;
    for(int i=0; i<nr_ingrediente; i++)
        {
            this->denumire[i] = ob.denumire[i];
            this->cantitate[i] = ob.cantitate[i];
        }

}
Pizza_vegetariana::~Pizza_vegetariana(){};
Pizza_vegetariana& Pizza_vegetariana::operator = (const Pizza_vegetariana &ob)
{
    if(this != &ob)
        {
            this->nr_ingrediente = ob.nr_ingrediente;
            for(int i=0; i<nr_ingrediente; i++)
            {
                this->denumire[i] = ob.denumire[i];
                this->cantitate[i] = ob.cantitate[i];
            }
        }
}
void Citire_vegetariana(Pizza_vegetariana& ob)
{
   {
        cout<<"Introduceti nr de ingrediente: ";
        cin>>ob.nr_ingrediente;
        cout<<"Ingredientele disponibile sunt: sos, ciuperci, porumb, ananas."<<endl;
        cout<<"Introduceti denumirea si cantitatea fiecarui ingredient: ";
        for(int i=0; i<ob.nr_ingrediente; i++)
        {
            cin>>ob.denumire[i];
            cin>>ob.cantitate[i];
            try
            {
                if(ob.denumire[i] == "porumb")
                    ob.pret[i] = 5;
                else if(ob.denumire[i] == "sos")
                    ob.pret[i] = 0.2;
                else if(ob.denumire[i] == "ananas")
                    ob.pret[i] = 5;
                else if(ob.denumire[i] == "ciuperci")
                    ob.pret[i] = 3;
                else
                    throw ob.denumire[i];
            }
            catch(string excp)
            {
                while(ob.denumire[i] != "porumb" && ob.denumire[i] != "sos" && ob.denumire[i] != "ananas" && ob.denumire[i] != "ciuperci")
                    {
                        cout<<"Ingredientul nu exista. Introduceti un ingredient existent: ";
                        cin>>ob.denumire[i];
                    }
                    if(ob.denumire[i] == "porumb")
                        ob.pret[i] = 5;
                    else if(ob.denumire[i] == "sos")
                        ob.pret[i] = 0.2;
                    else if(ob.denumire[i] == "ananas")
                        ob.pret[i] = 5;
                    else if(ob.denumire[i] == "ciuperci")
                        ob.pret[i] = 3;
            }
        }
    }
}
void Pizza_vegetariana::Afisare(){
    cout<<"Numarul de ingrediente: "<<this->nr_ingrediente<<endl;
    for(int i=0; i<nr_ingrediente; i++)
    {
        cout<<"Denumirea ingredientului: "<<this->denumire[i]<< "\nCantitate: "<<this->cantitate[i]<<endl;
    }


}
istream & operator >> (istream &in, Pizza_vegetariana &ob)
{
    {
        cout<<"Introduceti nr de ingrediente: ";
        in>>ob.nr_ingrediente;
        cout<<"Ingredientele disponibile sunt: sos, ciuperci, porumb, ananas."<<endl;
        cout<<"Introduceti denumirea si cantitatea fiecarui ingredient: ";
        for(int i=0; i<ob.nr_ingrediente; i++)
        {
            in>>ob.denumire[i];
            in>>ob.cantitate[i];
            try
            {
                if(ob.denumire[i] == "porumb")
                    ob.pret[i] = 5;
                else if(ob.denumire[i] == "sos")
                    ob.pret[i] = 0.2;
                else if(ob.denumire[i] == "ananas")
                    ob.pret[i] = 5;
                else if(ob.denumire[i] == "ciuperci")
                    ob.pret[i] = 3;
                else
                    throw ob.denumire[i];
            }
            catch(string excp)
            {
                while(ob.denumire[i] != "porumb" && ob.denumire[i] != "sos" && ob.denumire[i] != "ananas" && ob.denumire[i] != "ciuperci")
                    {
                        cout<<"Ingredientul nu exista. Introduceti un ingredient existent: ";
                        in>>ob.denumire[i];
                    }
                    if(ob.denumire[i] == "porumb")
                        ob.pret[i] = 5;
                    else if(ob.denumire[i] == "sos")
                        ob.pret[i] = 0.2;
                    else if(ob.denumire[i] == "ananas")
                        ob.pret[i] = 5;
                    else if(ob.denumire[i] == "ciuperci")
                        ob.pret[i] = 3;
            }
        }
    }
}
ostream & operator << (ostream &out, Pizza_vegetariana &ob)
{
      out<<"Numarul de ingrediente: "<<ob.nr_ingrediente<<endl;
    for(int i=0; i<ob.nr_ingrediente; i++)
    {
        out<<"Denumirea ingredientului: "<<ob.denumire[i]<< "\nCantitate: "<<ob.cantitate[i]<<endl;
    }
    return out;
}
template<class T>
class Comanda_Online:public Pizza, public Prajitura
{
    string cumpar;
    static float s;
public:
    Comanda_Online()
    {
        T ob;
        cin>>ob;
        cout<<"Cumparati produsul?"<<endl;
        cin>>cumpar;
        if(cumpar == "da")
            s = s + ob.cost;

    }
};
template<>
class Comanda_Online<Pizza_vegetariana>: public Pizza_vegetariana
{
    string cumpar;
    static float s;
public:
    Comanda_Online()
    {
        Pizza_vegetariana ob;
        cin>>ob;
        cout<<"Cumparati produsul?"<<endl;
        cin>>cumpar;
        if(cumpar == "da")
            ob.calcul_pret();
    }

        };

template <typename T>
    class Meniu: public Pizza, public Pizza_vegetariana, public Prajitura
    {
        static int id_produs;
        T lista;
        int index;
        unordered_map<int, vector<string>> m;
        vector<string> v;
    public:
        void map(int id_pizza, T ob)
        {
            m[id_pizza] = ob.denumire;
            unordered_map<int,vector<string>>::iterator p;
            for(p = m.begin(); p!=m.end();p++)
               {
                   cout<<p->first<<"\n";
                   vector<string>::iterator it;
                   for(it = p->second.begin(); it!= p->second.end();it++)
                        cout<<*it<<" ";
               }
        }
    };
template<typename T>                        //citirea si afisarea a n obiecte
class Management
{
    int n;
    T *obiecte = new T[n];
public:
    Management()
    {
        cout<<"Introduceti nr de obiecte: ";
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>obiecte[i];
            cout<<obiecte[i];
        }
    }
};

int main()
{
    Management<Pizza> ob;
    return 0;
}
