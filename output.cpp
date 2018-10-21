#include "output.h"
#include <QCoreApplication>
#include <stdio.h>
#include <iostream>

using namespace std;

void output::set_output(bool status)
{
    cout<<"Задаётся наличие данного перехода!!!"<<endl;
    state_output = status;
}

void output::set_name(char *set, int index, int next)
{
    cout<<"Задаётся имя перехода!!!"<<endl;
    index_name = index;
    name_output = new char;
    name_output = set;
    next_state = next;
}

char* output::get_name()
{
    return name_output;
}

int output::get_name_index()
{
    return index_name;
}

bool output::get_state()
{
    return state_output;
}

int output::get_next_state()
{
    return next_state;
}
