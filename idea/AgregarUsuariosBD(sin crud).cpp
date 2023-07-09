#include <iostream>
#include <memory>
#include <vector>
#include <windows.h>
#include <string>

using namespace std;

int i,j;



class Usuarios 
{
    public:
        wstring contraseñas;
        wstring Usuarios1;

        Usuarios(const wstring& Usuarios1, const wstring& contraseñas) 
            : Usuarios1(Usuarios1),contraseñas(contraseñas)
        {    
        }   
        
};

unique_ptr<Usuarios> ReturnUsuarios(const wstring& Usuarios1, const wstring& contraseñas)
{
    return make_unique<Usuarios>(Usuarios1,contraseñas);
}

void AgregarUsuarios(int num)
{
    wstring Usuario2;
    wstring Contraseñañ;
    vector<unique_ptr<Usuarios>> AgreUsuarios;

    for ( i = 0; i < num; i++)
    {
        system("cls");

        wcout << L"Deme usuario: " << L"(" << i+1 << L")" << endl;
        wcin >> Usuario2;
        wcout << L"Contraseña del usuario... " << L"(" << i+1 << L")" << endl;
        wcin >> Contraseñañ;
        AgreUsuarios.push_back(make_unique<Usuarios>(Usuario2,Contraseñañ));
    }
    
    system("cls");

    //mostrar
    for ( const auto& Usuarios : AgreUsuarios )
    {
        wcout << L"Usuario: " << Usuarios->Usuarios1 << L" | "; wcout << L"Contraseña: " << Usuarios->contraseñas << endl;
    }  

}


int main()
{
    while (true)
    {
        int num;

        wcout << L"Cuantos usuarios agregara?: "; wcin >> num;
        AgregarUsuarios(num);

        string close;
        wcout << L"Quiere operar denuevo? s/n " << endl;
        cin >> close;
        if (close != "s"){break;}else{system("cls");}
        
    }
    
}