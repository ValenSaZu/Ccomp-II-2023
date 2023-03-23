#include <iostream>
#include <math.h>

using namespace std;

int congruencia(int a, int b) {
    int x{ 1 };
    if (a >= b){
        while ((x * b) < a) {
            x += 1;
        }
        a -= (x * b);
    }
    return a;
}
int casoNegativo(int a, int b) {
    int x{ 1 };
    if (a < 0) {
        while(a + b * x < 0)
            x += 1;
    }
    return a + b * x;
}
int suma(int a, int c) {
    return a + c;
}
int resta(int a, int c) {
    return a - c;
}
int multiplicación(int a, int c) {
    return a * c;
}
int exponenciación(int a, int c) {
    int resultado{1};
    if (c > 6) {
        while (c > 6) {
            resultado *= pow(a, 6);
            c -= 6;
        }
        resultado *= pow(a, c);
        return resultado;
    }
    else {
        return pow(a, c);
    }
}
int inversa(int a, int b) {
    a = congruencia(a, b);
    int a2{a}, b2{b}, a3;
    int x{0}, y{1}, z, q, r{1}, contador{0};
    while (r != 0) {
        a3 = r;
        q = b2 / a2;
        r = b2 % a2;
        b2 = a2;
        a2 = r;
        contador += 1;
    }
    if (a3 == 1) {
        a2 = a;
        b2 = b;
        while (contador > 1) {
            q = b2 / a2;
            r = b2 % a2;
            b2 = a2;
            a2 = r;
            z = casoNegativo(x - y * q, b);
            x = y;
            y = z;
            contador -= 1;
        }
        return z;
    }
    return 0;
}

void reconoceOperacion() {
    int a, b, c, d;
    string e;
    cout << "Ingrese su módulo: " << endl;
    cin >> a;
    cout << "%" << endl;
    cin >> b;
    cout << "Operación (+, -, *, ^, inversa): "<< endl;
    cin >> e;
    if (e == "+" || e == "-" || e == "*") {
        cout << "Ingrese su segundo módulo: " << endl;
        cin >> c;
        cout << "%" << endl;
        cin >> d;
        if (b == d) {
            int m = b;
            if (e == "+") {
                cout << "Resulatdo: " << casoNegativo(suma(a, c), m) << " % " << m << "  = " << casoNegativo(suma(a, c), m) % m << endl;
            }
            if (e == "-") {
                cout << "Resultado: " << casoNegativo(resta(a, c), m) << " % " << m << "  = " << casoNegativo(resta(a, c), m) % m << endl;
            }
            if (e == "*") {
                cout << "Resultado: " << casoNegativo(multiplicación(a, c), m) << " % " << m << "  = " << casoNegativo(multiplicación(a, c), m) % m << endl;
            }
        } else {
            cout << "Parece haber un error en tu operación, revisa e intentalo de nuevo :D";
        }
    }
    else if (e == "^") {
        cout << "Ingrese su exponente: " << endl;
        cin >> c;
        cout << "Resultado: " << exponenciación(congruencia(a,b), c) << " % " << b << "  = " << exponenciación(congruencia(a, b), c) % b << endl;
    }
    else if (e == "inversa") {
        cout << "Resultado: " << inversa(a, b) << " % " << b << "  = " << inversa(a, b) % b << endl;
    }
    else {
        cout << "No resolvemos estas operaciones :( elige una de las opciones <3" << endl;
    }
}
int main()
{
    reconoceOperacion();
    return 0;
}
