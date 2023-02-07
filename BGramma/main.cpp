#include "Dictionary.h"
#include "BGramma.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned int start_time = clock(); // начальное время
    


    Dictionary a;
    a.Create();
    cout << "Работает!\n";
    //a.PrintDictionary();

    string s;
    int N;
    /*cout << "Введите слово: ";
    cin >> s;
    cout << "Введите количество слов для продолжения: ";
    cin >> N;*/

    s = "a";
    N = 3;

     BGramma b;
    b.Create();
    //b.PrintBGramma();

    /*cout << s << " ";*/
    string str;

    for (int i = 0; i < N; i++) {
        str = b.PlusBGramma(s);
        cout << str << " ";
        if (s == ".") i = N;
        s = str;
    }
    // здесь должен быть фрагмент кода, время выполнения которого нужно измерить
    unsigned int end_time = clock(); // конечное время
   // unsigned int search_time = end_time - start_time; // искомое время
    cout << end_time - start_time << endl;
}
