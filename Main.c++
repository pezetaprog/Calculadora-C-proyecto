#include <iostream>
#include <stdlib.h>
using namespace std;

class GestorOperandos {
private:
    int cant;
    int* operandos;

public:
    GestorOperandos() : cant(0), operandos(nullptr) {}

    void setCantidad(int n) {
        cant = n;
        delete[] operandos;
        operandos = new int[cant];
    }

    void setOperando(int indice, int valor) {
        if (indice >= 0 && indice < cant)
            operandos[indice] = valor;
    }

    int* getOperandos() const { return operandos; }
    int getCantidad()   const { return cant; }

    ~GestorOperandos() { delete[] operandos; }
};

class LectorDatos {
public:

    int leerOpcionMenu() {
        int opcion;
        cin >> opcion;
        return opcion;
    }


    int leerOpcionOperacion() {
        int opcion;
        cin >> opcion;
        return opcion;
    }

    void leerOperandos(GestorOperandos& gestor) {
        int n;
        cout << "Cuantos numeros deseas operar: ";
        cin >> n;
        gestor.setCantidad(n);

        for (int i = 0; i < n; i++) {
            int valor;
            cout << "Ingresa el numero [" << i + 1 << "]: ";
            cin >> valor;
            gestor.setOperando(i, valor);
        }
    }
};

class Menu{
    public:
   void mostrar(){
     cout << "\n===== Menu Calculadora =====\n";
        cout << "1: Operaciones\n";
        cout << "2: Historial\n";
        cout << "3: Exportar resultados\n";
        cout << "4: Salir\n";
        cout << "Selecciona lo que deseas hacer: ";
   }
};

class MenuOperaciones{
public:
    void mostrar(){
     cout << "\n===== Menu Operaciones =====\n";
        cout << "1: Suma\n";
        cout << "2: Resta\n";
        cout << "3: Multiplicacion\n";
        cout << "4: Division\n";
        cout << "5: Agregar nueva operacion\n";
        cout << "Selecciona la operacion: ";
    }
};

class Operaciones {
public:
    virtual double calcular(int* operandos, int cant) = 0;
    virtual ~Operaciones() {}
};

class Suma : public Operaciones {
public:
    double calcular(int* operandos, int cant) override {
        double resultado = 0;
        for (int i = 0; i < cant; i++)
            resultado += operandos[i];
        return resultado;
    }
};

class Resta : public Operaciones {
public:
    double calcular(int* operandos, int cant) override {
        if (cant == 0) return 0;
        double resultado = operandos[0];
        for (int i = 1; i < cant; i++)
            resultado -= operandos[i];
        return resultado;
    }
};

class Multiplicacion : public Operaciones {
public:
    double calcular(int* operandos, int cant) override {
        if (cant == 0) return 0;
        double resultado = 1;
        for (int i = 0; i < cant; i++)
            resultado *= operandos[i];
        return resultado;
    }
};

class Division : public Operaciones {
public:
    double calcular(int* operandos, int cant) override {
        if (cant == 0) return 0;
        double resultado = operandos[0];
        for (int i = 1; i < cant; i++) {
            if (operandos[i] != 0)
                resultado /= operandos[i];
            else
                cout << "Error: Division por cero en indice " << i << endl;
        }
        return resultado;
    }
};

int main() {
    // objetos
    Menu menu;
    MenuOperaciones menuOp;
    LectorDatos lector;
    GestorOperandos gestor;

    // operaciones disponibles
    Suma suma;
    Resta resta;
    Multiplicacion multi;
    Division divi;

    int opcion;

    do {
        menu.mostrar();
        opcion = lector.leerOpcionMenu();

        switch (opcion) {

            case 1: {
                menuOp.mostrar();
                int opOp = lector.leerOpcionOperacion();

                lector.leerOperandos(gestor);

                Operaciones* operacion = nullptr;

                switch (opOp) {
                    case 1: operacion = &suma;  break;
                    case 2: operacion = &resta; break;
                    case 3: operacion = &multi; break;
                    case 4: operacion = &divi;  break;
                }

                if (operacion != nullptr) {
                    double resultado = operacion->calcular(
                        gestor.getOperandos(),
                        gestor.getCantidad()
                    );
                    cout << "Resultado: " << resultado << endl;
                }
                break;
            }

            case 2:
                cout << "Historial (pendiente)\n";
                break;

            case 3:
                cout << "Exportar (pendiente)\n";
                break;

            case 4:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while (opcion != 4);

    return 0;
}
