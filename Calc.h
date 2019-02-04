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
                                                                        ������� ������ ������� � ���� '=' � �����.
                                                                    */
string Find_prev_elem(string &Data, int &pos, string &Chars, int elem);/*
                                                                        ������� ������� ����� ������ �������� �����������
                                                                        �� ������� ������ �����. ����� "������" � "������
                                                                        �����" ������ � ������ Data.
                                                                    */
string Find_next_elem(string &Data, int pos, string &Chars, int elem);/*
                                                                        �������� ���������� _prev_.
                                                                        ������ ������ ���������� ���� �� ������ � ����������
                                                                        �������:
                                                                            1. next;
                                                                            2. prev;
                                                                        ��� ������ � �������� ������� ������� ��� ������ next
                                                                        ����� �� ������.
                                                                    */
float Operation(int elem, string &Data, string &Chars, bool Deg);				/*
                                                                        ������� ��� ���������� �������� ��� ���������
                                                                        ����������.
                                                                    */
float Calculate(string &Data, string &Chars, int count, bool Deg);			/*
                                                                        ������� � ������ ����������� ��������.
                                                                    */

int Sort(string &Data, string &Chars);								/*
                                                                        ������� ��� ��������� ������ �������� � �����.
                                                                    */
int Capacity(const string Data);									/*
                                                                        ����� ���������� ��������� ����������� �� ��������.
                                                                    */
int Find_curr_pos(const string Data, const string Chars, int elem); /*
                                                                        ���������� ������� ����� ���������� �������� � ������
                                                                        Data.
                                                                    */
int BKT(string &Data, string Chars, bool Deg);						/*
                                                                        ������� ����������� ����������� ����������� ��
                                                                        �������� ������ �������� "(" � ")".
                                                                        ��������� ����������� ��������.
                                                                        �� ����� �� ��������������(������ "����������" ����
                                                                        ������ ������� ��������).
                                                                    */

void Start(string &Data, string &Chars, bool Deg);							/*
                                                                        ������� ��� ������ Sort � Calculate.
                                                                    */


bool bkt_check(string Data);										/*
                                                                        ������� ��� ���������� �������� ��� ���������
                                                                        ����������.
                                                                    */

void Bugs(string &Data);											/*
                                                                        ������� : ������� ���, ����� � ���� ������� �����������
                                                                        ����� �������, ��� : "++" "+-" � �.�.
                                                                    */
int Find_Chars(string Chars);										/*
                                                                        ��� ��������� ������ ���������� ��� sin, cos, tg, ctg,
                                                                        sqrt � ^
                                                                    */


string call(string Data, bool Deg);
