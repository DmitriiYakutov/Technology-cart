#include "output_automat.h"
#include <QCoreApplication>
#include <stdio.h>
#include <iostream>
#include <action.h>
#include <enumstate.h>

using namespace std;

void outputAutomat(action &Action)
{
    cout<<"Текущее положение: "<<Action.get_name()<<endl;
    for(int i = 0; i < end; i++)
    {
        if(Action.Output[i].get_state())
        {
            cout<<Action.Output[i].get_name();
            cout<<" выберите "<<i<<endl;
        }
    }
}
