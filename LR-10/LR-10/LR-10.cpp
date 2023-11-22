#include<iostream>
#include<Windows.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include<fstream>
#pragma warning(disable : 4996)
using namespace std;
bool Error(int N)
{
    if (!cin)
    {
        cin.clear();
        cin.ignore(50, '\n');
        cout << "Ошибка в вводе значения, попробуйте снова." << endl;
        return 1;
    }
    else
        return 0;
}
int main() {
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ofstream outputFile("log-file.txt");
    time_t currentTime = time(0);
    string timeString = ctime(&currentTime);
    int N, randomNum, k,p;
 
    cout << "Введите значение N: " << endl;
input1: 
    currentTime = time(0);
    timeString = ctime(&currentTime);
    cin >> N;
    if (Error(N) == 1)
    {
        outputFile << "Ошибка при ввода числа N - " << timeString << endl;
        goto input1;
    }
    outputFile << "Входные данные: " << endl << N << " Время ввода значения N: " << timeString << endl;
    randomNum = rand() % N + 1;
    cout << "Введите значение k: " << endl;
input2:
    cin >> k;
    if (Error(k)==1)
    {
        outputFile << "Ошибка при ввода числа k - " << timeString << endl;
        goto input2;
    }
    outputFile << endl << N << " Время ввода значения k: " << timeString << endl;
    outputFile << "Выходные данные:" << endl;
    cout << endl;
    for (int i = 0;i < k;i++)
    {
        cout << endl << "Введите(угадайте) случайное число:";
    input3:
        cout << endl;
        cin >> p;
        if (Error(p)==1)
        {
            outputFile << "Ошибка при ввода числа p - " << timeString << endl;
            goto input3;
        }
       currentTime = time(0);
       timeString = ctime(&currentTime);
        if (p == randomNum)
        {
            cout << "Вы угадали!";
            outputFile << endl << p << " Время ввода " << i+1<< " попытки: " << timeString << endl << "Вы угадали!";
            outputFile.close();
            return 0;
        }
        else
        {
            outputFile << endl << p << " Время ввода " << i + 1 << " попытки: " << timeString << endl << "Неверная попытка.";
            cout << "Осталось попыток - " << k - i - 1 << "." << endl;
        } 
        if (i + 1 == k)
            cout << endl << "Вы проиграли :(." << endl << "Загаданое число было - " << randomNum << endl;
    }
    
}