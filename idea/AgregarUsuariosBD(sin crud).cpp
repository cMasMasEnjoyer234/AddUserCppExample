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

        Usuarios(const wstring& Usuarios1, const wstring& contraseñas)  // here its gonna create a constructor with users and passwrd
            : Usuarios1(Usuarios1),contraseñas(contraseñas) // double dots for initiate first
        {    
        }   
        
};

unique_ptr<Usuarios> ReturnUsuarios(const wstring& Usuarios1, const wstring& contraseñas)
{
    return make_unique<Usuarios>(Usuarios1,contraseñas);
}

void AgregarUsuarios(int num)
{
    string opcion;
    string * ptrOP;
    ptrOP = &opcion;
    //.................
    wstring  Usuario2;
    wstring  Contraseñañ;
    vector<unique_ptr<Usuarios>> AgreUsuarios;

    for ( i = 0; i < num; i++)
    {
        system("cls");

        while (true)
        {
            wcout << L"Deme usuario: " << L"(" << i+1 << L")" << endl;
            wcin >> Usuario2;
            
            system("cls");

            wcout << L"Usuario: " << Usuario2 << endl;
            wcout << L"Esta bien escrito? s/n " << endl;
            cin >> *ptrOP;

            if (opcion == "s")
            {
                break;
            }
            
        }
        
        system("cls");

        while (true)
        {
            wcout << L"Contraseña del usuario... " << L"(" << i+1 << L")" << endl;
            wcin >> Contraseñañ;

            system("cls");

            wcout << L"Contraseña: " <<Contraseñañ << endl;
            wcout << L"La contraseña esta bien escrita? s/n " << endl;
            cin >> *ptrOP;

            if (opcion == "s")
            {
                break;
            }

        }
        
        

        AgreUsuarios.push_back(make_unique<Usuarios>(Usuario2,Contraseñañ)); // create various owners adding in a vector
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

        while (true)
        {
            system("cls");

            try
            {
                wcout << L"Cuantos usuarios agregara?: "; wcin >> num;
                if (num != 0 && num <= 20)
                {
                    system("cls");
                    break;
                }
                else
                {
                    throw num;
                }
            }
            catch(...)
            {
                cout << "No ponga caracteres." << endl;
                Sleep(3000);
            }
            
        }
        
        AgregarUsuarios(num);

        string close;
        wcout << L"Quiere operar denuevo? s/n " << endl;
        cin >> close;
        if (close != "s"){break;}else{system("cls");}
        
    }
    
}
