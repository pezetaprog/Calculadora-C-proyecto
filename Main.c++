#include <iostream>
#include <cmath>
using namespace std;


class Operaciones {
public:
    virtual double calcular(int* operandos, int cant) = 0;
    virtual string getNombre() = 0;
    virtual ~Operaciones() {}
};


class Suma : public Operaciones {
public:
    string getNombre() override { return "Suma"; }
    double calcular(int* operandos, int cant) override {
        double resultado = 0;
        for (int i = 0; i < cant; i++)
            resultado += operandos[i];
        return resultado;
    }
};

class Resta : public Operaciones {
public:
    string getNombre() override { return "Resta"; }
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
    string getNombre() override { return "Multiplicacion"; }
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
    string getNombre() override { return "Division"; }
    double calcular(int* operandos, int cant) override {
        if (cant == 0) return 0;
        double resultado = operandos[0];
        for (int i = 1; i < cant; i++) {
            if (operandos[i] != 0)
                resultado /= operandos[i];
            else
                cout << "Error: Division por cero en indice " << i << "\n";
        }
        return resultado;
    }
};


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


class Menu {
public:
    void mostrar() {
        cout << "\n===== Menu Calculadora =====\n";
        cout << "1: Operaciones\n";
        cout << "2: Historial\n";
        cout << "3: Exportar resultados\n";
        cout << "4: Salir\n";
        cout << "Selecciona lo que deseas hacer: ";
    }
};

class MenuOperaciones {
public:
    void mostrar(Operaciones** ops, int cantidad) {  
        cout << "\n===== Menu Operaciones =====\n";
        for (int i = 0; i < cantidad; i++)
            cout << i + 1 << ": " << ops[i]->getNombre() << "\n";
        cout << "Selecciona la operacion: ";
    }
};


class Calculadora {
private:
    Menu menu;
    MenuOperaciones menuOp;
    LectorDatos lector;
    GestorOperandos gestor;
    Operaciones** ops;
    int cantOps;

public:
    Calculadora(Operaciones** operaciones, int cantidad) {
        cantOps = cantidad;
        ops = new Operaciones*[cantOps];
        for (int i = 0; i < cantOps; i++)
            ops[i] = operaciones[i];
    }

    ~Calculadora() {
        delete[] ops;
    }

    void ejecutar() {
        int opcion;
        do {
            menu.mostrar();
            opcion = lector.leerOpcionMenu();

            switch (opcion) {
                case 1: realizarOperacion(); break;
                case 2: cout << "Historial (pendiente)\n"; break;
                case 3: cout << "Exportar (pendiente)\n";  break;
                case 4: cout << "Saliendo...\n"; break;
                default: cout << "Opcion invalida\n";
            }
        } while (opcion != 4);
    }

private:
    void realizarOperacion() {
        menuOp.mostrar(ops, cantOps);
        int opOp = lector.leerOpcionOperacion();

        if (opOp < 1 || opOp > cantOps) {
            cout << "Operacion invalida\n";
            return;
        }

        Operaciones* operacion = ops[opOp - 1];
        lector.leerOperandos(gestor);

        double resultado = operacion->calcular(
            gestor.getOperandos(),
            gestor.getCantidad()
        );

        cout << "Resultado: " << resultado << "\n";
    }
};


int main() {
    Suma suma;
    Resta resta;
    Multiplicacion multi;
    Division divi;

    Operaciones* ops[] = { &suma, &resta, &multi, &divi };
    int cantidad = 4; 

    Calculadora calc(ops, cantidad);
    calc.ejecutar();

    return 0;
}