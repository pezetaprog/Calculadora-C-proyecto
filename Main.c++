#include <iostream>
#include <limits>
using namespace std;

// transporte de datos de nuestro programa
struct DatosOperacion
{
    int opcion = 0;
    int opcion_ope = 0;
    
};

// clase menu para mostrar menus
class Menu
{
public:
    void mostrar_menu() const // Le dice al compilador que esa variable no puede cambiar después de ser inicializada
    {
        cout << "\n===== Menu Calculadora =====\n";
        cout << "1: Operaciones\n";
        cout << "2: Historial\n";
        cout << "3: Exportar resultados\n";
        cout << "4: Salir\n";
        cout << "Selecciona lo que deseas hacer: ";
    }

    void mostrar_menu_operaciones() const
    {
        cout << "\n===== Menu Operaciones =====\n";
        cout << "1: Suma\n";
        cout << "2: Resta\n";
        cout << "3: Multiplicacion\n";
        cout << "4: Division\n";
        cout << "5: Agregar nueva operacion\n";
        cout << "Selecciona la operacion: ";
    }
};



class Operacion
{
int n;
};
class Resta 
{

   
};
class Multiplicacion 
{

    
};
class Division 
{
public:
    
};

class EjecucionMenu
{
    Menu muestra;

private:
    int opcion = 0;

public:
    EjecucionMenu(int o) : opcion(o) {}
    EjecucionMenu() : opcion(0) {}

    int getOpcion() const { return opcion; }
    void setOpcion(int o) { opcion = o; }

    bool ejecucion()
    {

       
        muestra.mostrar_menu();
        

        switch (Seleccion_calc.opcion)
        {
        case 1:
        {
            DatosOperacion seleccion_oper;

            while (seleccion_oper.opcion != 5)
            {
                muestra.mostrar_menu_operaciones();

                seleccion_oper.opcion = ValidadorEntero::leer_entero();

                if (seleccion_oper.opcion >= 1 && seleccion_oper.opcion <= 4)
                {
                    ValidadorOperandos::leer_operandos(seleccion_oper);
                }

                switch (seleccion_oper.opcion)
                {
                case 1:
                {
                    Suma suma_res(seleccion_oper);
                    cout << " Resultado: " << suma_res.calcular() << endl;
                    break;
                }
                case 2:
                {
                    Resta resta_res(seleccion_oper);
                    cout << " Resultado: " << resta_res.calcular() << endl;
                    break;
                }
                case 3:
                {
                    Multiplicacion mult_res(seleccion_oper);
                    cout << " Resultado: " << mult_res.calcular() << endl;
                    break;
                }
                case 4:
                {
                    Division div_res(seleccion_oper);
                    cout << " Resultado: " << div_res.calcular() << endl;
                    break;
                }
                case 5:
                {
                    cout << ">> Volviendo al menu principal...\n";
                    break;
                }
                default:
                {
                    cout << ">> Opcion no valida.\n";
                    break;
                }
                }
            }
            break;
        }
        case 2:
            break;

        case 3:
            cout << ">> Exportar resultados\n";
            break;

        case 4:
            cout << ">> Saliendo...\n";
            return false;

        default:
            break;
        }

        return true;
    }
};

int main()
{
    EjecucionMenu ejecucionMenu;

    while (ejecucionMenu.ejecucion())
    {
    }
}
