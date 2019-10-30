#include <iostream>

using namespace std;

class vec
{
    int *v;
    int n;
public:
    vec();
    vec(const vec &);
    vec(int sz,int x);
    ~vec();
    vec& operator = (const vec &ob);
    void reactualizare(int y,int dim);
    void suma();
    void maxim();
    void sortare();
    int operator * (vec const &ob);
    friend istream & operator >> (istream &, vec &);
    friend ostream & operator << (ostream &, vec &);
    static vec * cma();
};

istream & operator >> (istream &in, vec &ob){       //supraincarcarea operatorului ">>"
    cout<<"Introduceti numarul de elemente ";
    in>>ob.n;
    cout<<"Introduceti elementele ";
    for(int i=0;i<ob.n;i++)
    in>>ob.v[i];
    return in;
}
ostream & operator << (ostream &out, vec &ob){      //supraincarcarea operatorului "<<"
out<<"Vectorul are "<<ob.n<<" elemente."<<endl;
out<<"Elementele sunt ";
for(int i=0;i<ob.n;i++)
    out<<ob.v[i]<<" ";
    out<<endl;
return out;
}
vec::vec(){                                         //initializare ob cu 0
    this->v=new int[this->n];
    this->n=0;
for(int i=0;i<this->n;i++)
    this->v[i]=0;

}
vec& vec::operator = (const vec &ob){               //supraincarcarea op "="
    if(this!= &ob)
    {
        this->n = ob.n;
        this->v = ob.v;

    }
    cout<<"Apel supraincarcare =\n";
    return *this;
}
vec::vec(const vec &a){                             //constr de copiere

    this->n = a.n;
    this->v = new int[a.n];
    for(int i=0; i<a.n; i++)
        this->v[i]=a.v[i];

}
vec::vec(int sz, int x){                            //init cu un nr pe toate componentele
        this->n=sz;
        this->v = new int[sz];
        for(int i=0; i<sz; i++)
            v[i]=x;

    }
vec::~vec(){                                        //destructor pt dezalocare zona de mem
        for(int i=0; i<this->n; i++)
            delete []v;}
void vec::reactualizare(int y,int dim){             //reactualizarea nr de componente si initializarea cu y pe toate comp
        cout<<"Am reactualizat\n";
        this->v = new int[dim];
        for(int i=0; i<dim; i++)
            v[i]=y;
        n = dim;
    }
void vec::suma(){                                   //suma elementelor din vector
        int s=0;
        for(int i=0; i<this->n; i++)
            s=s+v[i];
        cout<<"Suma elementelor vectorului este "<<s<<endl;
    }
void vec::maxim(){                                  //elementul maxim din vector
        int max=0,poz;
        for(int i=0;i<this->n;i++)
            if(max<v[i]){
                max=v[i];
                poz=i;
            }
            cout<<"Maximul este "<<max<<" pe pozitia "<<poz<<endl;
    }
void vec::sortare(){                                //sortarea crescatoare a vectorului
    int aux;
    for(int i=0; i<this->n-1; i++)
        for(int j=0;j<this->n-i-1;j++)
        {
            if(this->v[j]>this->v[j+1])
            {
                aux=this->v[j];
                this->v[j]=this->v[j+1];
                this->v[j+1]=aux;

            }
        }

}
int vec::operator * (vec const &ob1){               //suprainarcarea op "*" = produs scalar
    int produs=0;
    if(this->n==ob1.n)                       //verificam daca vectorii au aceeasi lungime pt a putea fi inmultiti
    {for(int i=0;i<this->n;i++)
        produs = produs+(ob1.v[i])*this->v[i];}
        else
            cout<<"Vectorii nu se pot inmulti."<<endl;
    return produs;
}
vec* vec::cma(){                                    //citirea, memorarea si afisarea a n obiecte
    cout<<"Introduceti nr de obiecte pentru citit: ";
    int n;
    vec *obiecte=new vec[n];                            //vector de obiecte
    cin>>n;
    for(int i=0;i<n;i++)
          {cin>>obiecte[i];
            cout<<obiecte[i];}
    return obiecte;
}

int main()
{
    /*vec ob1(2,3);
    cin>>ob1;
    cout<<ob1;
    ob1.suma();
    ob1.maxim();
    cout<<"Dupa ordonare:"<<endl;
    ob1.sortare();
    cout<<ob1;
    vec ob2=ob1;
    cout<<ob2;
    if(ob1*ob2 != 0)    //daca e 0 inseamna ca vectorii nu au acelasi nr de elemente si va afisa mesaj
        cout<<"Produsul vectorial este: "<<ob1*ob2;
    return 0;*/
    vec * obiecte;
    obiecte = vec::cma();
}
