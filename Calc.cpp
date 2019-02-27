#include "Calc.h"


Calculator::Calculator(string input, bool Deg)
{
    string Chars;
    int i = 1;
    string Data = input;
    Err = false;
    Data = correct(Data);

    if (!bkt_check(Data))
    {
        return;
    }
    if(Err)
    {
        i = 0;
    }
    while (i != 0)
    {
        if (Err)
        {
            break;
        }
        i = BKT(Data, Chars, Deg);
    }
    if (atof(Data.c_str()) -  atoi(Data.c_str()) == 0)
    {
        Data =  to_string(atoi(Data.c_str())) + " ";
    }
    Result = Data;
}

string Calculator::correct(string Data)
{
    int i = 0, j = 0;

    string temp;
    string correct_input = {'+', '-', '/' ,
    '*', '(', ')', '^', '=', '.', '0', '1',
    '2', '3', '4', '5', '6', '7', '8', '9',
    'c', 'e', 'g', 'i', 'l', 'n', 'o', 'p',
    'q', 'r', 's', 't' };

    //удаление пробелов

    while (Data.find(' ') != -1)
    {
        i = Data.find(' ');
        if (Data[i] == (char)' ')
        {
            Data.erase(i,1);
        }
    }

    //преобразование букв из "А" в "а"

    for (i = 0; i < Data.length(); i++)
    {
        if ((int)Data[i] >= 65 && (int)Data[i] <= 90)
        {
            Data[i] = (char)((int)Data[i] + 32);
        }
    }

    //удаление всех "="

    while(Data.find('=') != -1)
    {
        Data.erase(Data.find('='),1);
    }

    //проверка на принадлежность введённых символов "азбуке"
    for (i = 0; i < Data.length(); i++)
        {
            Err = true;
            for (j = 0; j < correct_input.length(); j++)
            {
                if (Data[i] == correct_input[j])
                {
                    Err = false;
                    j = correct_input.length() - 1;
                }
            }
            if (Err)
            {
                Error = "Syntax error ";
                return Data;
            }

        }
    //проверка на корректность введённых символов

        for (i = 0; i < Data.length(); i++)
        {
            switch ((int)Data[i])
            {
            case 41:
            {
                if (Data[i + 1] == '(')
                {
                    Error = "Syntax error: \")(\" ";
                    Err = true;
                    return Data;
                }
                else
                {
                     i++;
                }

                break;
            }

            case 115:	//s
            {
                if (Data[i + 1] == 'q' && Data[i + 2] == 'r' && Data[i + 3] == 't')
                {
                    i += 4;
                }
                else if (Data[i + 1] == 'i' && Data[i + 2] == 'n')
                {
                    i += 3;
                }
                else
                {
                    Error = "Syntax error on " + to_string(i+1) + " pos ";
                    Err = true;
                    return Data;
                }
                break;
            }
            case 99:	//c
            {
                if (Data[i + 1] == 'o' && Data[i + 2] == 's')
                {
                    i += 3;
                }
                else if (Data[i + 1] == 't' && Data[i + 2] == 'g')
                {
                    i += 3;
                }
                else
                {
                    Error = "Syntax error on " + to_string(i + 1) + " pos ";
                    Err = true;
                    return Data;
                }
                break;
            }
            case 108:	//l
            {
                if (Data[i + 1] == 'o' && Data[i + 2] == 'g')
                {
                    i += 3;
                }
                else
                {
                    Error = "Syntax error on " + to_string(i + 1) + " pos ";
                    Err = true;
                    return Data;
                }
                break;
            }
            case 112: //pi
            {
                if (Data[i + 1] == 'i')
                {
                    i += 2;
                }
                else
                {
                    Error = "Syntax error on " + to_string(i + 1) + " pos ";
                    Err = true;
                    return Data;
                }
                break;
            }
            case 101:	//e
            {
                i += 1;
                break;
            }
            case 116:
            {
                if (Data[i + 1] == 'g')
                {
                    i += 2;
                }
                else
                {
                    Error = "Syntax error on " + to_string(i + 1) + " pos ";
                    Err = true;
                    return Data;
                }
                break;
            }
            default:
            {
                Err = true;
                for (j = 0; j < 19; j++)
                {
                    if (Data[i] == correct_input[j])
                    {
                        Err = false;
                        j = 19;
                        i++;
                    }
                }
                if (Err)
                {
                    Error = "Syntax error on " + to_string(i + 1) + " pos ";
                    return Data;
                }
            }
            }
            i--;
        }

    //преобразование для упрощения работы

    for (i = 0; i < Data.length(); i++)
    {
        if ((Data[i] == (char)'s') && (Data[i + 1] == (char)'i') && (Data[i + 2] == (char)'n'))
        {
            Data.erase(i, 3);
            Data.insert(i, "s");
        }
        else if ((Data[i] == (char)'c') && (Data[i + 1] == (char)'o') && (Data[i + 2] == (char)'s'))
        {
            Data.erase(i, 3);
            Data.insert(i, "c");
        }
        else if ((Data[i] == (char)'t') && (Data[i + 1] == (char)'g'))
        {
            Data.erase(i, 2);
            Data.insert(i, "t");
        }
        else if ((Data[i] == (char)'c') && (Data[i + 1] == (char)'t') && (Data[i + 2] == (char)'g'))
        {
            Data.erase(i, 3);
            Data.insert(i, "g");
        }
        else if ((Data[i] == (char)'s') && (Data[i + 1] == (char)'q') && (Data[i + 2] == (char)'r') && (Data[i + 3] == (char)'t'))
        {
            Data.erase(i, 4);
            Data.insert(i, "v");
        }
        else if ((Data[i] == (char)'l') && (Data[i + 1] == (char)'o') && (Data[i + 2] == (char)'g'))
        {
            Data.erase(i, 3);
            Data.insert(i, "l");
        }
        else if ((Data[i] == (char)'p') && (Data[i + 1] == (char)'i'))
        {
            Data.erase(i, 2);
            temp = to_string(pi);
            Data.insert(i, temp);
        }
        else if(Data[i] == (char)'e')
        {
            Data.erase(i, 1);
            temp = to_string(exp);
            Data.insert(i, temp);
        }
    }

    Data.insert(0, " ");
    Data.insert(Data.length(), " ");

    return Data;
}

int Calculator::Capacity(const string Data)
{
    int i = 0, counter = 0;

    while (Data[i] != NULL)
    {
        if (Data[i] == ' ')
        {
            counter++;
        }
        i++;
    }
    if (counter == 1) counter++;
    return counter - 1;
}

int Calculator::Sort(string &Data, string &Chars)
{
    int i = 0, count = 0;

    while (Data.length() > i)
    {
        if (Data[i] == '+' || Data[i] == '-' ||
            Data[i] == '/' || Data[i] == '*' ||
            Data[i] == 'v' || Data[i] == '^' ||
            Data[i] == 's' || Data[i] == 'c' ||
            Data[i] == 't' || Data[i] == 'g' ||
            Data[i] == 'l')
        {
            Chars = Chars + (char)Data[i];
            Data[i] = ' ';
            count++;
        }

        i++;
    }

    return count;
}

string Calculator::Find_prev_elem(string &Data, int &pos, string &Chars, int elem)
{
    string element;
    int i = pos - 1, counter = 0;

    while (Data[i] != ' ')
    {
        i--;
    }
    counter = abs(pos - i);

    element = Data.substr(pos - counter, counter);
    Data.erase(pos - counter, counter);
    pos = pos - counter;
    return element;
}

string Calculator::Find_next_elem(string &Data, int pos, string &Chars, int elem)
{
    string element;
    string a = "\0";
    int i = pos + 1, counter = 1;

    if (Data[i] == ' ')
    {
        i++;
    }

    while (Data[i] != ' ')
    {
        i++;
    }
    counter = abs(pos - i);

    if (Data[pos + 1] == ' ')
    {
        Data.erase(pos, 1);
        a = Chars[elem + 1];
        Chars.erase(elem + 1, 1);
        counter--;
    }

    element = a + Data.substr(pos + 1, counter);
    Data.erase(pos + 1, counter);

    return element;
}

int Calculator::Find_curr_pos(const string Data, const string Chars, int elem)
{
    int pos = 0, counter = 0;

    while (Data[pos] != NULL)
    {
        if (Data[pos] == ' ')
        {
            if (counter == elem + 1)
            {
                return pos;
            }
            counter++;
        }
        pos++;
    }

    return -1;
}

void Calculator::Bugs(string &Data)
{
    int i = 0;

    while (Data[i] != NULL)
    {
        if (Data[i] == '+')
        {
            if (Data[i + 1] == '-')
            {
                Data.erase(i, 1);
                i = 0;
            }
            else if (Data[i + 1] == '+')
            {
                Data.erase(i + 1, 1);
                i = 0;
            }
            else if (Data[i + 1] == '/')
            {
                Err = true;
                Error = "Syntax error : \"+/\" ";
                return;
            }
            else if (Data[i + 1] == '*')
            {
                Err = true;
                Error = "Syntax error : \"+*\" ";
                return;
            }
        }
        else if (Data[i] == '-')
        {
            if (Data[i + 1] == '-')
            {
                Data.erase(i, 2);
                Data.insert(i, "+");
                i = 0;
            }
            else if (Data[i + 1] == '+')
            {
                Data.erase(i + 1, 1);
                i = 0;
            }
            else if (Data[i + 1] == '/')
            {
                Err = true;
                Error = "Syntax error : \"-/\" ";
                return;
            }
            else if (Data[i + 1] == '*')
            {
                Err = true;
                Error = "Syntax error : \"-*\" ";
                return;
            }

        }
        else if (Data[i] == '*')
        {
            if (Data[i + 1] == '+')
            {
                Data.erase(i + 1, 1);
                i = 0;
            }
            else if (Data[i + 1] == '/')
            {
                Err = true;
                Error = "Syntax error : \"*/\" ";
                return;
            }
            else if (Data[i + 1] == '*')
            {
                Err = true;
                Error = "Syntax error : \"**\" ";
                return;
            }

        }
        else if (Data[i] == '/')
        {
            if (Data[i + 1] == '+')
            {
                Data.erase(i + 1, 1);
                i = 0;
            }
            else if (Data[i + 1] == '*')
            {
                Err = true;
                Error = "Syntax error : \"/*\" ";
                return;
            }
            else if (Data[i + 1] == '/')
            {
                Err = true;
                Error = "Syntax error : \"//\" ";
                return;
            }
        }

        i++;
    }


}

float Calculator::Operation(int elem, string &Data, string &Chars, bool Deg)
{
    int pos = Find_curr_pos(Data, Chars, elem);
    float res = 0;
    string a, b;

    if (pos == -1)
    {
        Error = "error, calc dead";
        Err = true;
        return 0;
    }


    //менять местами а и b запрещено !!!

    b = Find_next_elem(Data, pos, Chars, elem);
    a = Find_prev_elem(Data, pos, Chars, elem);

    /*if ( (a.length() == 1 && a[0] == ' ' ) || (b.length() == 1 && b[0] == ' ') )
    {
        if (Chars.length() == 1 && (Chars[0] == '/' || Chars[0] == '*' || Chars[0] == '^') )
        {
            Err = true;
            Error = " Syntax error: " + a + Chars[0] + b;
            return res;
        }
    }*/

    switch ((int)Chars[elem])
    {
    case 42:
        // "*"
        {
            if ((a.length() == 1 && (a[0] == '\0' || a[0] == ' ')) ||
                    (b.length() == 1 && (b[0] == '\0' || b[0] == ' ')))
            {
                Err = true;
                Error = " Syntax error: " + a + Chars[0] + b;
            }
            else
            {
                res = atof(a.c_str()) * atof(b.c_str());
            }
            break;
        }
    case 43:
        // "+"
        res = atof(a.c_str()) + atof(b.c_str());
        break;
    case 45:
        // "-"
            res = atof(a.c_str()) - atof(b.c_str());
        break;
    case 47:
        // "/"
        {
            if ((a.length() == 1 && (a[0] == '\0' || a[0] == ' ')) ||
                    (b.length() == 1 && (b[0] == '\0' || b[0] == ' ')))
            {
                Err = true;
                Error = "Syntax error:" + a + Chars[0] + b;
            }
            else
            {
                if (atof(b.c_str()) != 0)
                {
                res = atof(a.c_str()) / atof(b.c_str());
                }
                else
                {
                    Error = "Сan't be divided by zero ";
                    Err = true;
                }
            }
            break;
        }
    case 115://sin
        if (!Deg)
        {
            res = sin(atof(b.c_str()));
        }
        else
        {
            res = sin(atof(b.c_str()) * pi / 180);
        }
        break;
    case 99://cos
        if (!Deg)
        {
            res = cos(atof(b.c_str()));
        }
        else
        {
            res = cos(atof(b.c_str()) * pi / 180);
        }
        break;
    case 116://tg
        if (!Deg)
        {
            res = sin(atof(b.c_str())) / cos(atof(b.c_str()));
        }
        else
        {
            res = sin(atof(b.c_str()) * pi / 180) / cos(atof(b.c_str()) * pi / 180);
        }

        break;
    case 103://ctg
        if (!Deg)
        {
            res = cos(atof(b.c_str()) ) / sin(atof(b.c_str()) );
        }
        else
        {
            res = cos(atof(b.c_str()) * pi / 180) / sin(atof(b.c_str()) * pi / 180);
        }
        break;
    case 94:// ^
        res = pow(atof(a.c_str()),atof(b.c_str()));
        break;
    case 118:// sqrt
        res = pow(atof(b.c_str()),0.5);
        break;
    default:
        break;
    }

    a = " " + to_string(res);
    Data.insert(pos, a);

    Chars.erase(elem, 1);

    return res;
}

int Calculator::Find_Chars(string Chars)
{
    int pos = 0, i = 0, j = 0, temp;
    int mass[6];
    mass[0] = (int)Chars.find('s');
    mass[1] = (int)Chars.find('c');
    mass[2] = (int)Chars.find('t');
    mass[3] = (int)Chars.find('g');
    mass[4] = (int)Chars.find('v');
    mass[5] = (int)Chars.find('^');

    for (i = 0; i < 5 ; i++)
    {
        for (j = 0; j < 5 - i; j++)
        {
                temp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = temp;
        }
    }

    for (i = 0; i < 6; i++)
    {
        if (mass[i] != -1)
        {
            pos = mass[i];
            break;
        }
    }

    return pos;
}

float Calculator::Calculate(string & Data, string & Chars, int count, bool Deg)
{
    int i = 0, j = 0;
    float result = 0;

    if (Chars.find('s') != -1 || Chars.find('c') != -1 ||
        Chars.find('t') != -1 || Chars.find('g') != -1 ||
        Chars.find('v') != -1 || Chars.find('^') != -1)
    {
        i = Find_Chars(Chars);
        Operation(i, Data, Chars, Deg);

    }
    else if (Chars.find('*') != -1 || Chars.find('/') != -1)
    {
        i = Chars.find('*');
        j = Chars.find('/');

        if (j != -1 && i != -1)
        {
            if (i < j)
            {
                Operation(i, Data, Chars, Deg);
            }
            else
            {
                Operation(j, Data, Chars, Deg);
            }
        }
        else if (j != -1)
        {
            Operation(j, Data, Chars, Deg);
        }
        else
        {
            Operation(i, Data, Chars, Deg);
        }
    }
    else
    {
        Operation(0, Data, Chars, Deg);
    }

    return result;
}

int Calculator::BKT(string &Data, string Chars, bool Deg)
{
    int i = 0;
    int counter = 0, bkt_counter = 0, temp = 0, j = 1;
    string bkt_Data;
    string log10;
    float res;

    Bugs(Data);
    if (Err)
    {
        return 0;
    }
    bkt_Data = Data;
    temp = Data.find('l');


    if (temp != -1)
    {
        i = 1;
        while (1)
        {
            if (bkt_Data[bkt_Data.find('l') + i] == NULL)
            {
                break;
            }
            log10 = bkt_Data[bkt_Data.find('l') + i];
            if (log10[0] == '(')
            {
                Err = false;
                break;
            }
            i++;


        }
        log10.clear();
        if (Err)
        {
            Error = "Error Log: please, try 'log' with '(...)' ";
            return 0;
        }
        i = 0;
        bkt_Data.clear();

        while (1)
        {
            if (Data[temp + counter] == '(')
            {
                bkt_counter++;
            }
            else if (Data[temp + counter] == ')')
            {
                bkt_counter--;
            }

            if (Data[temp + counter] == ')' && bkt_counter == 0)
            {
                break;
            }
            bkt_Data += Data[temp + counter];
            counter++;

        }

        while (bkt_Data[j] != '(')
        {
            log10 += bkt_Data[j];
            j++;
        }

        bkt_Data.erase(0, j + 1);

        bkt_Data.insert(0, " ");
        i = bkt_Data.length();
        bkt_Data.insert(i, " ");

        BKT(bkt_Data, Chars, Deg);

        if (atof(bkt_Data.c_str()) <= 0)
        {
            Error = "Error Log : b < 0 ";
            Err = true;
            return 0;
        }
        if (log10.empty())
        {
            log10 = "10";
        }
        else if (atof(log10.c_str()) <= 0 || atof(log10.c_str()) == 1)
        {
            Error = "Error Log : a < 0 || a = 1 ";
            Err = true;
            return 0;
        }

        res = log(atof(bkt_Data.c_str()))/ log(atof(log10.c_str()));
        log10 = to_string(res);
        Data.erase(temp, counter + 1);
        Data.insert(temp, log10);
        bkt_Data = Data;
        BKT(bkt_Data, Chars, Deg);
        Data = bkt_Data;
    }
    i = Data.find('(') + 1;
    temp = 0;
    counter = 0;
    bkt_counter = 1;
    bkt_Data = Data;

    if (i != 0)
    {
        bkt_Data.clear();
        while (Data[i + counter] != NULL)
        {
            if (Data[i + counter] == '(')
            {
                bkt_counter++;
            }
            else if (Data[i + counter] == ')')
            {
                bkt_counter--;
            }

            if (Data[i + counter] == ')' && bkt_counter == 0)
            {
                break;
            }
            bkt_Data += Data[i + counter];
            counter++;

        }

        if (bkt_Data.empty())
        {
            bkt_Data = "0";
        }

        bkt_Data.insert(0, " ");
        temp = bkt_Data.length();
        bkt_Data.insert(temp, " ");

        BKT(bkt_Data, Chars, Deg);
    }
    else
    {
        Start(bkt_Data, Chars, Deg);
        if (Err)
        {
            return 1;
        }
    }

    if (i != 0 && !Err)
    {
        bkt_Data.erase(0, 1);
        bkt_Data.erase(bkt_Data.length() - 1, 1);
        Data.erase(i - 1, counter + 2);
        Data.insert(i - 1, bkt_Data);
        BKT(Data, Chars, Deg);
    }
    else
    {
        Data = bkt_Data;
    }
    return i;
}

bool Calculator::bkt_check(string Data)
{
    int bkt_counter = 0, i = 0;

    while (Data[i] != NULL)
    {
        if (Data[i] == '(')
        {
            bkt_counter++;
        }
        else if (Data[i] == ')')
        {
            bkt_counter--;
        }
        i++;
    }

    if (bkt_counter == 0)
    {
        return true;
    }
    else
    {
        if ( bkt_counter < 0 )
        {
            Error = "Error : missed '(' ";
            Err = true;
        }
        else
        {
            Error = "Error : missed ')' ";
            Err = true;
        }
        return false;
    }

}

void Calculator::Start(string &Data, string &Chars, bool Deg)
{
    int i = 0;

    if (Sort(Data, Chars) != 0)
    {
        while (1 != Capacity(Data) )
        {
            if (Err)
            {
                return;
            }
            Calculate(Data, Chars, i, Deg);
        }
    }

}

bool Calculator::isError()
{
    return Err;
}

//"-(-144.12/-(12.112*-14) + 11.64235/2) * -60 * -(-3 )="
//"cos(sin(((-(-144.12/-(12.112*-14)+11.64235/2)*-60*-(-3)+log(log(e))+(e*pi)))/log12(pi)))="

