﻿#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <vector>
#include <locale>
#include <string>
#include <algorithm>
#include<conio.h>
#include <stdio.h>
#include<windows.h>
#include <string.h>
#include<stdlib.h>
#include <memory>
#include <map>
#include <unordered_map>
#include <iterator>
#include <regex>
#include <sstream>
#include "libxl.h"
using namespace libxl;
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
typedef std::vector<char>     T_str;
int* KolichestvoBigramok;
/////////////////////////////////////////////////////////////////////////////////////////
template<class Range, class Iterator>
bool is_last_element_of(Range const& r, Iterator&& it) 
{
    using std::end;
    if (it == end(r)) return false;
    if (std::next(std::forward<Iterator>(it)) == end(r)) return true;
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////
char  tolower_rus(char c)
{
    return  tolower
    (
        c,
        std::locale("")
    );
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
T_str  string_tolower_rus(const T_str& str)
{
    T_str   res_str = str;

    std::transform
    (
        str.begin(),
        str.end(),
        res_str.begin(),
        tolower_rus
    );

    return  res_str;
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
bool isalpha_rus(char c) {
    return c >= 'а' && c <= 'я' || c >= 'А' && c <= 'Я'
        || c == 'ё' || c == 'Ё'; // если надо включаем букву ё
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
int Change_registors()
{
    std::locale::global(std::locale(""));

    std::ifstream in("text.txt");/////
    std::vector<char> array{
        std::istreambuf_iterator<char>(in),
        std::istreambuf_iterator<char>() };

    T_str   s = string_tolower_rus(array);

    std::ofstream out("Смена регистров_1.txt");
    std::copy(s.begin(), s.end(),
        std::ostreambuf_iterator<char>(out));
    _getch();
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
bool delete_characters_1(char c)
{
    switch (c)
    {
    case 'а':
    case 'б':
    case 'в':
    case 'г':
    case 'д':
    case 'е':
    case 'ё':
    case 'ж':
    case 'з':
    case 'и':
    case 'й':
    case 'к':
    case 'л':
    case 'м':
    case 'н':
    case 'о':
    case 'п':
    case 'р':
    case 'с':
    case 'т':
    case 'у':
    case 'ф':
    case 'х':
    case 'ц':
    case 'ч':
    case 'ш':
    case 'щ':
    case 'ъ':
    case 'ы':
    case 'ь':
    case 'э':
    case 'ю':
    case 'я':
        return false;
    case ' ':
        return false;
    default:
        return true;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
bool delete_characters_2(char c)
{
    switch (c)
    {
    case 'а':
    case 'б':
    case 'в':
    case 'г':
    case 'д':
    case 'е':
    case 'ё':
    case 'ж':
    case 'з':
    case 'и':
    case 'й':
    case 'к':
    case 'л':
    case 'м':
    case 'н':
    case 'о':
    case 'п':
    case 'р':
    case 'с':
    case 'т':
    case 'у':
    case 'ф':
    case 'х':
    case 'ц':
    case 'ч':
    case 'ш':
    case 'щ':
    case 'ъ':
    case 'ы':
    case 'ь':
    case 'э':
    case 'ю':
    case 'я':
        return false;
    default:
        return true;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
void helper_delete()
{
    fstream inpt_1("Смена регистров_1.txt", ios_base::in);
    fstream outpt_1("Смена регистров.txt", ios_base::out);
    char c;
    while (inpt_1.get(c))
    {
        if (c == 'ё')
        {
            outpt_1.put('е');
        }
        else if (c == 'ъ')
        {
            outpt_1.put('ь');
        }
        else if (!isalpha_rus(c))
        {
            outpt_1.put(' ');
        }
        else outpt_1.put(c);
    }
    inpt_1.close();
    outpt_1.close();
    std::locale::global(std::locale(""));
    std::cout << "Удаление лишних символов в файле\n>> ";
    std::ifstream in("Смена регистров.txt");
    std::vector<char> array{
        std::istreambuf_iterator<char>(in),
        std::istreambuf_iterator<char>() };

    std::string s;
    for (char c : array) {
        s.push_back(c);
    }

    /////////////////////////////////////////////////////////////////////////////////////////
    s.erase(std::remove_if(s.begin(), s.end(), &delete_characters_1), s.end());
    std::ofstream out_1("Удаление лишних символов в файле с пробелами.txt");
    std::copy(s.begin(), s.end(),
        std::ostreambuf_iterator<char>(out_1));
    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////
    s.erase(std::remove_if(s.begin(), s.end(), &delete_characters_2), s.end());
    std::ofstream out_2("Удаление лишних символов в файле без пробелов.txt");
    std::copy(s.begin(), s.end(),
        std::ostreambuf_iterator<char>(out_2));
    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////
    _getch();
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
void Bigramka1()
{
        std::ifstream inBigramka("Удаление лишних символов в файле с пробелами.txt");
        std::vector<char> massiv{
            std::istreambuf_iterator<char>(inBigramka),
            std::istreambuf_iterator<char>() };
        vector<char> s = massiv;

        map< string, float> KKKRIPTA;
        map < string, float> ::iterator it_1, it_2;
        int countbich = 0;
        int kabachok = 0;
            //////////////////////////////////////
            //I am assuming that buffer has some data
            char* c = new char[massiv.size()];

            for (int a = 0; a < massiv.size(); a++)
            {
                c[a] = massiv[a];
            }
            int a = massiv.size();

            //////////////////////////////////////
            cout << "Количество символов " << (massiv.size() - 1) << endl;
 
            for (int h = 0; h <= massiv.size()-2; h++)//for each char in string/////
            {
                    char BigramkaChar[3] = { c[h],c[h + 1],0 };
                    std::string BigramkaString(BigramkaChar);

                    it_2 = it_1 = KKKRIPTA.find(BigramkaString);
                    if (it_2 == KKKRIPTA.end())
                    {
                        KKKRIPTA.insert(make_pair(BigramkaString, 1));
                        countbich++;
                    }
                    else if (it_2 != KKKRIPTA.end())
                    {
                        it_2->second++;
                        countbich++;
                    }
            }
            std::ofstream ofs("Биграмка с пробелами з шагом 1.txt");
            std::streambuf* our_buffer = std::cout.rdbuf(ofs.rdbuf());
            for (auto& e : KKKRIPTA)  //for each unique char in map
            {
                std::map< char, float>::iterator iter;
                std::cout << e.first << "\t" << e.second << "\t" << e.second / countbich << endl;
            }
            std::cout.rdbuf(our_buffer);
            ofs.close();
            return;
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
void Bigramka2()
{
    std::ifstream inBigramka("Удаление лишних символов в файле с пробелами.txt");
    std::vector<char> massiv{
        std::istreambuf_iterator<char>(inBigramka),
        std::istreambuf_iterator<char>() };
    vector<char> s = massiv;

    map< string, float> KKKRIPTA;
    map < string, float> ::iterator it_1, it_2;
    int countbich = 0;
    int kabachok = 0;
    //////////////////////////////////////
    //I am assuming that buffer has some data
    char* c = new char[massiv.size()];

    for (int a = 0; a < massiv.size(); a++)
    {
        c[a] = massiv[a];
    }
    int a = massiv.size();

    //////////////////////////////////////
    cout << "Количество символов " << (massiv.size() - 1) << endl;
    int k = massiv.size();
    for (int h = 0; h <= k; h=h+2)//for each char in string/////
    {
        if (h <= massiv.size() - 1)
        {
            char BigramkaChar[3] = { c[h],c[h + 1],0 };
            std::string BigramkaString(BigramkaChar);

            it_2 = it_1 = KKKRIPTA.find(BigramkaString);
            if (it_2 == KKKRIPTA.end())
            {
                KKKRIPTA.insert(make_pair(BigramkaString, 1));
                countbich++;
            }
            else if (it_2 != KKKRIPTA.end())
            {
                it_2->second++;
                countbich++;
            }
        }
        else if (h == massiv.size())
        {
            cout << "Конец массива...." << endl;
            kabachok = h;
        }
    }
    std::ofstream ofs("Биграмка с пробелами з шагом 2.txt");
    std::streambuf* our_buffer = std::cout.rdbuf(ofs.rdbuf());
    for (auto& e : KKKRIPTA)  //for each unique char in map
    {
        std::map< char, float>::iterator iter;
        std::cout << e.first << "\t" << e.second << "\t" << e.second / countbich << endl;
    }
    std::cout.rdbuf(our_buffer);
    ofs.close();
    return;
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
void Bigramka3()
{
    std::ifstream inBigramka("Удаление лишних символов в файле без пробелов.txt");
    std::vector<char> massiv{
        std::istreambuf_iterator<char>(inBigramka),
        std::istreambuf_iterator<char>() };
    vector<char> s = massiv;

    map< string, float> KKKRIPTA;
    map < string, float> ::iterator it_1, it_2;
    int countbich = 0;
    int kabachok = 0;
    //////////////////////////////////////
    //I am assuming that buffer has some data
    char* c = new char[massiv.size()];

    for (int a = 0; a < massiv.size(); a++)
    {
        c[a] = massiv[a];
    }
    int a = massiv.size();

    //////////////////////////////////////
    cout << "Количество символов " << (massiv.size() - 1) << endl;
    int k = massiv.size();
    for (int h = 0; h <= k; h++)//for each char in string/////
    {
        if (h <= massiv.size() - 1)
        {
            char BigramkaChar[3] = { c[h],c[h + 1],0 };
            std::string BigramkaString(BigramkaChar);

            it_2 = it_1 = KKKRIPTA.find(BigramkaString);
            if (it_2 == KKKRIPTA.end())
            {
                KKKRIPTA.insert(make_pair(BigramkaString, 1));
                countbich++;
            }
            else if (it_2 != KKKRIPTA.end())
            {
                it_2->second++;
                countbich++;
            }
        }
        else if (h == massiv.size())
        {
            cout << "Конец массива...." << endl;
            kabachok = h;
        }
    }
    std::ofstream ofs("Биграмка без пробелов з шагом 1.txt");
    std::streambuf* our_buffer = std::cout.rdbuf(ofs.rdbuf());
    for (auto& e : KKKRIPTA)  //for each unique char in map
    {
        std::map< char, float>::iterator iter;
        std::cout << e.first << "\t" << e.second << "\t" << e.second / countbich << endl;
    }
    std::cout.rdbuf(our_buffer);
    ofs.close();
    return;
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
void Bigramka4()
{
    std::ifstream inBigramka("Удаление лишних символов в файле без пробелов.txt");
    std::vector<char> massiv{
        std::istreambuf_iterator<char>(inBigramka),
        std::istreambuf_iterator<char>() };
    vector<char> s = massiv;

    map< string, float> KKKRIPTA;
    map < string, float> ::iterator it_1, it_2;
    int countbich = 0;
    int kabachok = 0;
    //////////////////////////////////////
    //I am assuming that buffer has some data
    char* c = new char[massiv.size()];

    for (int a = 0; a < massiv.size(); a++)
    {
        c[a] = massiv[a];
    }
    int a = massiv.size();

    //////////////////////////////////////
    cout << "Количество символов " << (massiv.size() - 1) << endl;
    int k = massiv.size();
    for (int h = 0; h <= k; h = h + 2)//for each char in string/////
    {
        if (h <= massiv.size() - 1)
        {
            char BigramkaChar[3] = { c[h],c[h + 1],0 };
            std::string BigramkaString(BigramkaChar);

            it_2 = it_1 = KKKRIPTA.find(BigramkaString);
            if (it_2 == KKKRIPTA.end())
            {
                KKKRIPTA.insert(make_pair(BigramkaString, 1));
                countbich++;
            }
            else if (it_2 != KKKRIPTA.end())
            {
                it_2->second++;
                countbich++;
            }
        }
        else if (h == massiv.size())
        {
            cout << "Конец массива...." << endl;
            kabachok = h;
        }
    }
    std::ofstream ofs("Биграмка без пробелов з шагом 2.txt");
    std::streambuf* our_buffer = std::cout.rdbuf(ofs.rdbuf());
    for (auto& e : KKKRIPTA)  //for each unique char in map
    {
        std::map< char, float>::iterator iter;
        std::cout << e.first << "\t" << e.second << "\t" << e.second / countbich << endl;
    }
    std::cout.rdbuf(our_buffer);
    ofs.close();
    return;
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
void BuckvoSchet1()
{
    std::ifstream inBigramka("Удаление лишних символов в файле с пробелами.txt");
    std::vector<char> massiv{
        std::istreambuf_iterator<char>(inBigramka),
        std::istreambuf_iterator<char>() };
    vector<char> s = massiv;

    map< string, float> KKKRIPTA;
    map < string, float> ::iterator it_1, it_2;
    int countbich = 0;
    int kabachok = 0;
    //////////////////////////////////////
    //I am assuming that buffer has some data
    char* c = new char[massiv.size()];

    for (int a = 0; a < massiv.size(); a++)
    {
        c[a] = massiv[a];
    }
    int a = massiv.size();

    //////////////////////////////////////
    cout << "Количество символов " << (massiv.size() - 1) << endl;
    int k = massiv.size();
    for (int h = 0; h <= k; h++)//for each char in string/////
    {
        if (h <= massiv.size() - 1)
        {
            char BigramkaChar[2] = { c[h],0 };
            std::string BigramkaString(BigramkaChar);

            it_2 = it_1 = KKKRIPTA.find(BigramkaString);
            if (it_2 == KKKRIPTA.end())
            {
                KKKRIPTA.insert(make_pair(BigramkaString, 1));
                countbich++;
            }
            else if (it_2 != KKKRIPTA.end())
            {
                it_2->second++;
                countbich++;
            }
        }
        else if (h == massiv.size())
        {
            cout << "Конец массива...." << endl;
            kabachok = h;
        }
    }
    std::ofstream ofs("Букви с пробелами.txt");
    std::streambuf* our_buffer = std::cout.rdbuf(ofs.rdbuf());
    for (auto& e : KKKRIPTA)  //for each unique char in map
    {
        std::map< char, float>::iterator iter;
        std::cout << e.first << "\t" << e.second << "\t" << e.second / countbich << endl;
    }
    std::cout.rdbuf(our_buffer);
    ofs.close();
    return;
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
void BuckvoSchet2()
{
    std::ifstream inBigramka("Удаление лишних символов в файле без пробелов.txt");
    std::vector<char> massiv{
        std::istreambuf_iterator<char>(inBigramka),
        std::istreambuf_iterator<char>() };
    vector<char> s = massiv;

    map< string, float> KKKRIPTA;
    map < string, float> ::iterator it_1, it_2;
    int countbich = 0;
    int kabachok = 0;
    //////////////////////////////////////
    //I am assuming that buffer has some data
    char* c = new char[massiv.size()];

    for (int a = 0; a < massiv.size(); a++)
    {
        c[a] = massiv[a];
    }
    int a = massiv.size();

    //////////////////////////////////////
    cout << "Количество символов " << (massiv.size() - 1) << endl;
    int k = massiv.size();
    for (int h = 0; h <= k; h++)//for each char in string/////
    {
        if (h <= massiv.size() - 1)
        {
            char BigramkaChar[2] = { c[h],0 };
            std::string BigramkaString(BigramkaChar);

            it_2 = it_1 = KKKRIPTA.find(BigramkaString);
            if (it_2 == KKKRIPTA.end())
            {
                KKKRIPTA.insert(make_pair(BigramkaString, 1));
                countbich++;
            }
            else if (it_2 != KKKRIPTA.end())
            {
                it_2->second++;
                countbich++;
            }
        }
        else if (h == massiv.size())
        {
            cout << "Конец массива...." << endl;
            kabachok = h;
        }
    }
    std::ofstream ofs("Букви без пробелов.txt");
    std::streambuf* our_buffer = std::cout.rdbuf(ofs.rdbuf());
    for (auto& e : KKKRIPTA)  //for each unique char in map
    {
        std::map< char, float>::iterator iter;
        std::cout << e.first << "\t" << e.second << "\t" << e.second / countbich << endl;
    }
    std::cout.rdbuf(our_buffer);
    ofs.close();
    return;
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////`
int Vivod()
{
    cout << "\n";
    int counter_2 = 1, chosen_option_2 = counter_2;
    std::vector<std::string> OPTIONS;
    setlocale(LC_ALL, "Ukrainian");

    OPTIONS.push_back("                                                                  \n");
    OPTIONS.push_back("-----------------------------------------------------------------\n");
    OPTIONS.push_back("|                               Menu                             |\n");
    OPTIONS.push_back("-----------------------------------------------------------------\n");
    OPTIONS.push_back("| 1 - Биграмка без пробелов з шагом 1                            |\n");
    OPTIONS.push_back("| 2 - Биграмка без пробелов з шагом 2                            |\n");
    OPTIONS.push_back("| 3 - Биграмка с пробелами з шагом 1                             |\n");
    OPTIONS.push_back("| 4 - Биграмка с пробелами з шагом 2                             |\n");
    OPTIONS.push_back("-----------------------------------------------------------------\n");
    OPTIONS.push_back("|                              Вихід                             |\n");
    OPTIONS.push_back("-----------------------------------------------------------------\n");
    while (chosen_option_2 != 9)
    {
        HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD cd;
        cd.X = 0;
        cd.Y = 0;
        SetConsoleCursorPosition(hd, cd);

        for (size_t j = 0; j < OPTIONS.size(); ++j)
        {
            if ((j + 1) == counter_2) std::cout << "> " << OPTIONS[j] << std::endl;
            else                    std::cout << OPTIONS[j] << std::endl;
        }
        char pressed_2 = _getch();

        if (pressed_2 == 'w' && counter_2 != 0)
            counter_2--;
        if (pressed_2 == 'w' && counter_2 == 0)
            counter_2 = OPTIONS.size();
        if (pressed_2 == 's' && counter_2 != OPTIONS.size())
            counter_2++;
        if (pressed_2 == 's' && counter_2 == OPTIONS.size())
            counter_2 = 0;

        if (pressed_2 == '\r' || pressed_2 == '\n')
        {
            chosen_option_2 = counter_2;

            HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD cd;
            cd.X = 0;
            cd.Y = 0;
            SetConsoleCursorPosition(hd, cd);
            switch (chosen_option_2)
            {
            case 5:
                system("pause");
                system("cls");
                cout << "\n";
                cout << "Биграмка без пробелов з шагом 1" << endl;
                Bigramka1();
                system("pause");
                system("cls");
                cout << "\n";
                break;
            case 6:
                system("pause");
                system("cls");
                cout << "\n";
                cout << "Биграмка без пробелов з шагом 2" << endl;
                Bigramka2();
                system("pause");
                system("cls");
                cout << "\n";
                break;
            case 7:
                system("pause");
                system("cls");
                cout << "\n";
                cout << "Биграмка с пробелами з шагом 1" << endl;
                Bigramka3();
                system("pause");
                system("cls");
                cout << "\n";
                break;
            case 8:
                system("pause");
                system("cls");
                cout << "\n";
                cout << "Биграмка с пробелами з шагом 4" << endl;
                Bigramka4();
                system("pause");
                system("cls");
                cout << "\n";
                break;
            case 10:
                system("pause");
                system("cls");
                cout << "\n";
                cout << "Вихiд... ";
                system("pause");
                system("cls");
                cout << "\n";
                return 0;
                break;
            default:
                cout << "Вибрана невірна команда\n";
            }
            _getch();
        }
    }
    _getch();
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////`
int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывод

    int counter = 1, chosen_option = counter;
    std::vector<std::string> Options;
    setlocale(LC_ALL, "Ukrainian");
    Options.push_back("          	                                                        \n");
    Options.push_back("-----------------------------------------------------------------\n");
    Options.push_back("|                               Menu                             |\n");
    Options.push_back("-----------------------------------------------------------------\n");
    Options.push_back("| 1 - Изменение регистров в текстовом файле                      |\n");
    Options.push_back("| 2 - Удаление лишних символов                                   |\n");
    Options.push_back("| 3 - Частота биграмм                                            |\n");
    Options.push_back("| 4 - Частота букв                                               |\n");
    Options.push_back("-----------------------------------------------------------------\n");
    Options.push_back("|                              Вихід                             |\n");
    Options.push_back("-----------------------------------------------------------------\n");
    while (chosen_option != 9)
    {
        HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD cd;
        cd.X = 0;
        cd.Y = 0;
        SetConsoleCursorPosition(hd, cd);

        for (size_t i = 0; i < Options.size(); ++i)
        {
            if ((i + 1) == counter) std::cout << "> " << Options[i] << std::endl;
            else                    std::cout << Options[i] << std::endl;
        }
        char pressed = _getch();

        if (pressed == 'w' && counter != 0)
            counter--;
        if (pressed == 'w' && counter == 0)
            counter = Options.size();
        if (pressed == 's' && counter != Options.size())
            counter++;
        if (pressed == 's' && counter == Options.size())
            counter = 0;

        if (pressed == '\r' || pressed == '\n')
        {
            chosen_option = counter;

            HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD cd;
            cd.X = 0;
            cd.Y = 0;
            SetConsoleCursorPosition(hd, cd);
            switch (chosen_option)
            {
            case 5:
                system("pause");
                system("cls");
                cout << "\n";
                cout << "1 - Изменение регистров в текстовом файле\n";
                Change_registors();
                system("pause");
                system("cls");
                cout << "\n";
                break;
            case 6:
                system("pause");
                system("cls");
                cout << "\n";
                cout << "2 - Удаление лишних символов\n";
                helper_delete();
                cout << "\n";
                system("pause");
                system("cls");
                cout << "\n";
                break;
            case 7:
                system("pause");
                system("cls");
                cout << "\n";
                cout << "3 - Частота биграмм\n";
                Vivod();
                cout << "\n";
                system("pause");
                system("cls");
                cout << "\n";
                break;
             case 8:
                system("pause");
                system("cls");
                cout << "\n";
                cout << "4 - Частота букв\n";
                BuckvoSchet1();
                BuckvoSchet2();
                system("pause");
                system("cls");
                cout << "\n";
                break;
            case 10:
                system("pause");
                system("cls");
                cout << "\n";
                cout << "Вихiд... ";
                system("pause");
                system("cls");
                cout << "\n";
                return 0;
                break;
            }
            _getch();
        }
    }
    _getch();
}