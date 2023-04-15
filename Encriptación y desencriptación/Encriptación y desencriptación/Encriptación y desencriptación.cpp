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
    int contraseña;
    cout << "Crea una contraseña : ";
    cin >> contraseña;

    if (inversa(contraseña, 256) != 0) {

        cout << "Su contraseña para desencriptar es: " << inversa(contraseña, 256) << endl;

        fstream origen("C:/Users/51955/source/repos/Encriptación y desencriptación/origen.txt", ios::in | ios::binary);
        fstream destino("C:/Users/51955/source/repos/Encriptación y desencriptación/encriptado.txt", ios::out | ios::binary);

        string byte;
        char ch;
        while (origen.get(ch)) {
            byte += ch;
        }

        const int length = byte.length();
        char* Cbyte = new char[length + 1];
        Cbyte[length] = '\0';
        for (int i = 0; i < length; i++) {
            Cbyte[i] = (inversa(contraseña,256)*byte[i])%256;
        }

        destino.write(Cbyte, length);

        destino.close();
        origen.close();
        system("pause");
    }
    else {
        cout << "Elija otra contraseña porfi" << endl;
        encriptar();
    }
}

void desencriptar() {
    int contraseña{};
    cout << "Ingrese su contraseña para desencriptar: ";
    cin >> contraseña;

    fstream origen("C:/Users/51955/source/repos/Encriptación y desencriptación/encriptado.txt", ios::in | ios::binary);
    fstream destino("C:/Users/51955/source/repos/Encriptación y desencriptación/desencriptado.txt", ios::out | ios::binary);

    string byte;
    char ch;
    while (origen.get(ch)) {
        byte += ch;
    }

    const int length = byte.length();
    char* Cbyte = new char[length + 1];
    Cbyte[length] = '\0';
    for (int i = 0; i < length; i++) {
        Cbyte[i] = (inversa(contraseña, 256) * byte[i]) % 256;
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