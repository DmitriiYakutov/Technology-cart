#include <enumstate.h>
#include "action.h"
#include <QCoreApplication>
#include <stdio.h>
#include <iostream>

using namespace std;

void action::set_name(char *set, int index)
{
    Output = new output[end];
    cout<<"Задаётся имя вершины!!!"<<endl;
    index_name = index;
    name_action = new char;
    name_action = set;
}

char* action::get_name()
{
    return name_action;
}
