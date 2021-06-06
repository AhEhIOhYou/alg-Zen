#include <iostream>
#include <cmath>
#include <string.h>
#include <string>
#include <cstdio>

//Простая проверка числа на простоту
bool isPrime( long int prime)
{
    long int i, j;
    j = (long int)sqrt((long double)prime);
    for ( i = 2; i <= j; i++)
        if ( prime % i == 0 )
            return false;

    return true;
}

//Поиск наибольшего общего делителя
long int greatestCommonDivisor(long int e, long int t)
{
    while (e > 0)
    {
        long int tmp;
        tmp = e;
        e = t % e;
        t = tmp;
    }
    return t;
}

//Вычисление открытой экспоненты
long int calculateE( long int t )
{
    // Выбирается целое число e ( 1 < e < t ) // взаимно простое со значением функции Эйлера (t)
    long int e;

    //Перебираем
    for ( e = 2; e < t; e++ )
    {
        if (greatestCommonDivisor(e, t) == 1 )
        {
            return e;
        }
    }

    return -1;
}

long int calculateD(long int e, long int t)
{
//    условие: d ⋅ e ≡ 1 (mod φ(n))
    long int d;
    long int k = 1;

    while (true)
    {
        k = k + t;
        if (k % e == 0)
        {
            d = (k / e);
            return d;
        }
    }
}

//Кодирование символа - номер символа, открытый ключ
long int encrypt(long int i, long int e, long int n )
{
    long int current, result;

    current = i - 97;
    result = 1;

//    Это возведение в степень такое
    for (long int j = 0; j < e; j++ )
    {
        result = (result * current) % n;
    }

    return result;
}

//Декодирование символа - номер символа, закрытый ключ
long int decrypt(long int i, long int d, long int n)
{
    long int current, result;

    current = i;
    result = 1;

    for ( long int j = 0; j < d; j++ )
    {
        result = result * current;
        result = result % n;
    }

    return result + 97;
}

int main( )
{
    using namespace std;
    long int p, q, n, t, e, d;

//  Массивы для хранения текстов
    long int encryptedText[100];
    memset(encryptedText, 0, sizeof(encryptedText));

    long int decryptedText[100];
    memset(decryptedText, 0, sizeof(decryptedText));

    string encrText;

    bool flagP = false;
    bool flagQ = false;

//    Ввод и проверка на простоту p и q
    while (!flagP)
    {
        cout << "p: ";
        cin >> p;
        flagP = isPrime(p);
    }
    while (!flagQ)
    {
        cout << "q: ";
        cin >> q;
        flagQ = isPrime(q);
    }
//    Произведение p и q
    n = p * q;
    cout << "p*q = " << n << endl;
//    Функция Эйлера
    t = ( p - 1 ) * ( q - 1 );
    cout << "F(n) = " << t << endl;
//    Открытая эксспонента
    e = calculateE(t);
//    Секретная экспонента
    d = calculateD(e, t);

    cout << "Public key: {" << e << ", " << n << "}" << endl;
    cout << "Private key: {" << d << ", " << n << "}" << endl;

//    Ввод шифруемого текста
    cout << "Encr text: " << endl;
    std::cin.ignore();
    getline(std::cin, encrText );

//    Шифрование
    for (long int i = 0; i < encrText.length(); i++)
        encryptedText[i] = encrypt(encrText[i], e, n);
    cout << "Result: ";

    for (long int i = 0; i < encrText.length(); i++ )
        printf( "%c", (char)encryptedText[i] );

    cout << endl;

//    Дешифрование
    for (long int i = 0; i < encrText.length(); i++)
        decryptedText[i] = decrypt(encryptedText[i], d, n);

    cout << "Origin text:";

    for (long int i = 0; i < encrText.length(); i++)
        printf( "%c", (char)decryptedText[i] );

    cout << endl;

    system("pause");
    return 0;
}
