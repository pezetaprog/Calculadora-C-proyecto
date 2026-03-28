#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// transporte de datos de nuestro programa
struct DatosOperacion
{
    int opcion = 0;
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

class ValidadorEntero
{
public:
    static int leer_entero()
    {
        int valor = 0;
        while (true)
        {
            if (cin >> valor)
                return valor;
            cout << "  [!] Entrada invalida. Ingresa un numero entero: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
};
;

class ValidadorDecimal
{
    static double leer_decimal()
    {
        double valor = 0;
        while (true)
        {
            if (cin >> valor)
                return valor;
            cout << "  [!] Entrada invalida. Ingresa un numero: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
};

class EjecucionMenu
{
    Menu muestra;
private:
    int opcion = 0;
    //RegistroOperaciones registro;
    //Historial           historial;

public:
    EjecucionMenu(int o) : opcion(o) {}
    EjecucionMenu() : opcion(0) {}

    int  getOpcion() const  { return opcion; }
    void setOpcion(int o)   { opcion = o; }

    bool ejecucion()
    {
       DatosOperacion SeleccionOpc;
       muestra.mostrar_menu();
        SeleccionOpc.opcion = ValidadorEntero::leer_entero();

        switch (SeleccionOpc.opcion)
        {
        case 1:
        {
            //SelectorEjecucion selector(registro, historial);
            //selector.ejecutar();
            break;
        }
        case 2:
            //Visualizador::mostrar_historial(historial);
            break;

        case 3:
            cout << ">> Exportar resultados\n";
            break;

        case 4:
            cout << ">> Saliendo...\n";
            return false;

        default:
            //Visualizador::mostrar_error("Opcion no valida.");
            break;
        }

        return true;
    }
};

class Operacion
{
};

int main()
{
    Menu menu;
    EjecucionMenu ejecucionMenu;

    while (ejecucionMenu.ejecucion())  
    {
        menu.mostrar_menu();
    }
}