#include <iostream>

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
    for(size_t i=0; i < Cont; i++){
        Computadora &c = arreglo[i];
        cout << "Sistema Operativo: " << c.getSistemaOp()<<endl;
        cout << "Nombre del equipo: " << c.getNombreEquipo()<<endl;
        cout << "Cantida de memoria RAM: " << c.getMemoriaR()<<endl;
        cout << "Cantida de Memoria de almacenamiento(gigabytes): " << c.getCantidadMemoria()<<endl;
        cout << endl;
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

    Computadora c04;
    c04.setSistemaOp("Windows");
    c04.setNombreEquipo("Ivan");
    c04.setMemoriaR(10);
    c04.setCantidadMemoria(2500);

    Computadora c05;
    c05.setSistemaOp("Linux");
    c05.setNombreEquipo("Fernanda");
    c05.setMemoriaR(4);
    c05.setCantidadMemoria(1000);

    Computadora c06;
    c06.setSistemaOp("Linux");
    c06.setNombreEquipo("Jahaira");
    c06.setMemoriaR(8);
    c06.setCantidadMemoria(3000);

    Laboratorio Lab;

    Lab.AgregarComputadora(c02);
    Lab.AgregarComputadora(c03);
    Lab.AgregarComputadora(c04);
    Lab.AgregarComputadora(c05);
    Lab.AgregarComputadora(c06);

    Lab.mostrar();

    return 0;
}

