//Для подключения и использования стандартной библиотеки ввода-вывода
#include <iostream>
#include <fstream>
//Подключение библиотеки строковых функций:
//memset(), strcpy(), strlen()
#include <string.h>
#include "stdlib.h"
//Для вывода русских символов на консоль
#include <clocale>
#include <Windows.h>
using namespace std;
//Глобальные константы для длин вспомогательных текстовых буферов
#define SUBL 512
#define BIGL 4096


class Word {
    private:
        char buf[BIGL];//Объявляем вспомогательный текстовый буфер
        char word[BIGL];
        int countPref; // (0-3)
        int countCorin; // (1-2)
        int countSuf; // (0-3)
        string pref;
        string corin;
        string suf;
        string ending;
        string type;
        string rid;
        string chislo;
        string osoba;
        string vidminok;
    public:
        Word(){};
        Word(string _rid, string _chislo, string _osoba, string _vidminok){
            rid = _rid;
            chislo = _chislo;
            osoba = _osoba;
            vidminok = _vidminok;
        };
        //Ввод с консоли
        void input_word();
        //Вывод на консоль
        void output_word();
        //Ввод с файла
        void input_word_from_file(string filename);
        //Вывод с файла
        void output_word_to_file(string filename);
        //Разбиение слова на слоги
        void split_word();
        //Ввод слова по частям: префикс суфикс корень окончание
        void input_by_parts();
        //Вывод по частям слова
        void output_by_parts();
};
