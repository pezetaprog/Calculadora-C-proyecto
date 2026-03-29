#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// transporte de datos de nuestro programa
struct DatosOperacion
{
    int opcion = 0;
    int opcion_ope = 0;
    vector<double> operandos;
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

class ValidadorDecimal
{
public:
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

class ValidadorOperandos
{
public:
    static void leer_operandos(DatosOperacion &datos)
    {
        int cantidad;
        cout << "Cuantos numeros quieres operar? ";
        cantidad = ValidadorEntero::leer_entero();

        datos.operandos.clear();
        for (int i = 0; i < cantidad; i++)
        {
            cout << "Numero " << i + 1 << ": ";
            datos.operandos.push_back(ValidadorDecimal::leer_decimal());
        }
    }
};

class Operacion
{
protected:
    vector<double> operandos;
    double resultado = 0;

public:
    Operacion(const DatosOperacion &datos)
        : operandos(datos.operandos)
    {
    }

    virtual double calcular() = 0;

    double getResultado() const { return resultado; }
    virtual ~Operacion() {}
};
class Suma : public Operacion
{
public:
    Suma(const DatosOperacion &datos) : Operacion(datos) {}

    double calcular() override
    {
        resultado = 0;
        for (double n : operandos)
            resultado += n;
        return resultado;
    }
};
class Resta : public Operacion
{
public:
    Resta(const DatosOperacion &datos) : Operacion(datos) {}

    double calcular() override
    {
        resultado = 0;
        for (double n : operandos)
            resultado -= n;
        return resultado;
    }
};
class Multiplicacion : public Operacion
{
public:
    Multiplicacion(const DatosOperacion &datos) : Operacion(datos) {}

    double calcular() override
    {
        resultado = 0;
        for (double n : operandos)
            resultado *= n;
        return resultado;
    }
};
class Division : public Operacion
{
public:
    Division(const DatosOperacion &datos) : Operacion(datos) {}

    double calcular() override
    {
        resultado = 0;
        for (double n : operandos)
            resultado += n;
        return resultado;
    }
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

        DatosOperacion Seleccion_calc;
        muestra.mostrar_menu();
        Seleccion_calc.opcion = ValidadorEntero::leer_entero();

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
