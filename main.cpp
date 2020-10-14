#include <iostream>
#include <iomanip>

using namespace std;


class Computadora
{
    public:
    string SistemaOp;
    string NombreEquipo;
    int MemoriaR;
    int CantidadMemoria;
        
    public:
    Computadora(){};
    Computadora(const string &SistemaOp, const string &NombreEquipo, int MemoriaR, int CantidadMemoria);
    void setSistemaOp(const string &v);
    string getSistemaOp();
    
    void setNombreEquipo(const string &v);
    string getNombreEquipo();
    void setMemoriaR(int);
    int getMemoriaR();
    void setCantidadMemoria(int);
    int getCantidadMemoria();

    friend ostream& operator<<(ostream &out, const Computadora &c){
        out << left;
        out << setw(13) << c.SistemaOp;
        out << setw(13) << c.NombreEquipo;
        out << setw(10)  << c.MemoriaR;
        out << setw(10)  << c.CantidadMemoria;
        out << endl;

        return out;
    }

    friend istream& operator>>(istream &in, Computadora &c){
        // string temp;
        // string temp2;
        // int ram;
        // int mem;  
        
        cout << "Sistema Operativo: ";
        getline(cin, c.SistemaOp);

        cout << "Nombre Del Usuario: ";
        getline(cin, c.NombreEquipo);

        cout << "Memoria Ram: ";
        cin >> c.MemoriaR;

        cout << "Memoria De Almacenamiento: ";
        cin >> c.CantidadMemoria;

        return in;
    }


};

Computadora::Computadora(const string &SistemaOp, const string &NombreEquipo, int MemoriaR, int CantidadMemoria)
{
this->SistemaOp = SistemaOp;
this->NombreEquipo = NombreEquipo;
this->MemoriaR = MemoriaR;
this->CantidadMemoria = CantidadMemoria;
}

void Computadora::setSistemaOp(const string &v){
    this->SistemaOp = v;
}

string Computadora::getSistemaOp(){
    return SistemaOp;
}

void Computadora::setNombreEquipo(const string &v){
    this->NombreEquipo = v;
}

string Computadora::getNombreEquipo(){
    return NombreEquipo;
}

void Computadora::setMemoriaR(int v){
    this->MemoriaR = v;
}

int Computadora::getMemoriaR(){
    return MemoriaR;
}

void Computadora::setCantidadMemoria(int v){
    this->CantidadMemoria = v;
}

int Computadora::getCantidadMemoria(){
     return CantidadMemoria;
}

class Laboratorio{
    Computadora arreglo [5];
    size_t Cont;

public:
    Laboratorio();
    void AgregarComputadora(const Computadora &c);   //AgregarFinal
    void mostrar();

    friend Laboratorio& operator<<(Laboratorio &L, const Computadora &c){
    
    L.AgregarComputadora(c);
    return L;
    }
};

Laboratorio::Laboratorio(){
    Cont = 0;
}

void Laboratorio::AgregarComputadora(const Computadora &c){
    if (Cont<5){
        arreglo[Cont] = c;
        Cont++;
    }
    else{
        cout<<"arreglo lleno"<<endl;
    }

}

void Laboratorio::mostrar(){
    cout << left;
    cout << setw(13) << "SisOp"; 
    cout << setw(13) << "NomSist";
    cout << setw(10) << "Ram(GB)";
    cout << setw(10) << "Memoria(GB)";
    cout << endl;
    for(size_t i=0; i < Cont; i++){
        Computadora &c = arreglo[i];
       
       cout << c;

       // cout << "Sistema Operativo: " << c.getSistemaOp()<<endl;
       // cout << "Nombre del equipo: " << c.getNombreEquipo()<<endl;
       // cout << "Cantida de memoria RAM: " << c.getMemoriaR()<<endl;
       // cout << "Cantida de Memoria de almacenamiento(gigabytes): " << c.getCantidadMemoria()<<endl;
       // cout << endl;
    }
}



int main()
{
  
    Computadora c02 = Computadora("Windows", "Mauricio", 12, 2000); 
    Computadora c03;
    c03.setSistemaOp("Linux");
    c03.setNombreEquipo("Mauro");
    c03.setMemoriaR(8);
    c03.setCantidadMemoria(3000);

    Laboratorio Lab;

    Lab.AgregarComputadora(c02);
    Lab.AgregarComputadora(c03);

    Computadora c04;
    cin>> c04;
    Lab << c04;

    Computadora c05;
    cin>> c05;
    Lab << c05;

    Computadora c06;
    cin>> c06;
    Lab << c06;

    Lab.mostrar();

    return 0;
}

