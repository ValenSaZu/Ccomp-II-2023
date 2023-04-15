#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int congruencia(int a, int b) {
    int x{ 1 };
    if (a >= b) {
        while ((x * b) <= a) {
            x += 1;
        }
    }
    a -= ((x - 1) * b);
    return a;
}
int casoNegativo(int a, int b) {
    int x{ 1 };
    if (a < 0) {
        while (a + b * x < 0)
            x += 1;
    }
    return a + b * x;
}
int inversa(int a, int b) {
    a = congruencia(a, b);
    int a2{ a }, b2{ b }, a3;
    int x{ 0 }, y{ 1 }, z{ 0 }, q, r{ 1 }, contador{ 0 };
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
        return (congruencia(z, b) % b);
    }
    else {
        return 0;
    }
}
void encriptar() {
    int contrase�a;
    cout << "Crea una contrase�a : ";
    cin >> contrase�a;

    if (inversa(contrase�a, 256) != 0) {

        cout << "Su contrase�a para desencriptar es: " << inversa(contrase�a, 256) << endl;

        fstream origen("C:/Users/51955/source/repos/Encriptaci�n y desencriptaci�n/origen.txt", ios::in | ios::binary);
        fstream destino("C:/Users/51955/source/repos/Encriptaci�n y desencriptaci�n/encriptado.txt", ios::out | ios::binary);

        string byte;
        char ch;
        while (origen.get(ch)) {
            byte += ch;
        }

        const int length = byte.length();
        char* Cbyte = new char[length + 1];
        Cbyte[length] = '\0';
        for (int i = 0; i < length; i++) {
            Cbyte[i] = (inversa(contrase�a,256)*byte[i])%256;
        }

        destino.write(Cbyte, length);

        destino.close();
        origen.close();
        system("pause");
    }
    else {
        cout << "Elija otra contrase�a porfi" << endl;
        encriptar();
    }
}

void desencriptar() {
    int contrase�a{};
    cout << "Ingrese su contrase�a para desencriptar: ";
    cin >> contrase�a;

    fstream origen("C:/Users/51955/source/repos/Encriptaci�n y desencriptaci�n/encriptado.txt", ios::in | ios::binary);
    fstream destino("C:/Users/51955/source/repos/Encriptaci�n y desencriptaci�n/desencriptado.txt", ios::out | ios::binary);

    string byte;
    char ch;
    while (origen.get(ch)) {
        byte += ch;
    }

    const int length = byte.length();
    char* Cbyte = new char[length + 1];
    Cbyte[length] = '\0';
    for (int i = 0; i < length; i++) {
        Cbyte[i] = (inversa(contrase�a, 256) * byte[i]) % 256;
    }

    destino.write(Cbyte, length);

    destino.close();
    origen.close();
    system("pause");

}
int main()
{
    string ingreso{};
    cout << "Ingrese 'e' para encriptar y 'd' para desencriptar (RECUERDA TENER TU ARCHIVO CORRECTAMENTE GUARDADO):" << endl;
    cin >> ingreso;
    if (ingreso == "e") {
        encriptar();
    }if (ingreso == "d") {
        desencriptar();
    }
	return 0;
}