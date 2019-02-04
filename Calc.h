#pragma once

#include <iostream>
#include <string>
#include <math.h>

#define pi 3.14159265
#define exp 2.71828183

//#pragma warning (disable : 4244 4018)

using namespace std;


using namespace std;


string correct(string Data);										/*
                                                                        Убирает лишние пробелы и знак '=' в конце.
                                                                    */
string Find_prev_elem(string &Data, int &pos, string &Chars, int elem);/*
                                                                        Находит операнд перед знаком операции основываясь
                                                                        на позиции самого знака. После "чистит" в "нужном
                                                                        месте" данные в строке Data.
                                                                    */
string Find_next_elem(string &Data, int pos, string &Chars, int elem);/*
                                                                        Работает аналогично _prev_.
                                                                        Фунции должны вызываться одна за другой в конкретном
                                                                        порядке:
                                                                            1. next;
                                                                            2. prev;
                                                                        При вызове в обратном порядке позиция для чистки next
                                                                        будет не верной.
                                                                    */
float Operation(int elem, string &Data, string &Chars, bool Deg);				/*
                                                                        Функция для выполнения операций над соседними
                                                                        операндами.
                                                                    */
float Calculate(string &Data, string &Chars, int count, bool Deg);			/*
                                                                        Подсчёт с учётом приоритетов операций.
                                                                    */

int Sort(string &Data, string &Chars);								/*
                                                                        Функция для отделения знаков операций и чисел.
                                                                    */
int Capacity(const string Data);									/*
                                                                        Выдаёт количество операндов основываясь на пробелах.
                                                                    */
int Find_curr_pos(const string Data, const string Chars, int elem); /*
                                                                        Возвращает позицию знака конкретной операции в строке
                                                                        Data.
                                                                    */
int BKT(string &Data, string Chars, bool Deg);						/*
                                                                        Функция выполняющая расстановку приоритетов по
                                                                        средству поиска символов "(" и ")".
                                                                        Выполняет рекурсивные действия.
                                                                        До конца не оптимизирована(иногда "накидывает" пару
                                                                        лишних уровней рекурсии).
                                                                    */

void Start(string &Data, string &Chars, bool Deg);							/*
                                                                        Функция для вызова Sort и Calculate.
                                                                    */


bool bkt_check(string Data);										/*
                                                                        Функция для выполнения операций над соседними
                                                                        операндами.
                                                                    */

void Bugs(string &Data);											/*
                                                                        Костыль : убирает баг, когда в ходе решения встречаются
                                                                        такие моменты, как : "++" "+-" и т.д.
                                                                    */
int Find_Chars(string Chars);										/*
                                                                        Для упрощения поиска приоритета для sin, cos, tg, ctg,
                                                                        sqrt и ^
                                                                    */


string call(string Data, bool Deg);
