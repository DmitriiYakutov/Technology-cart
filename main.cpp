#include <QCoreApplication>
#include <stdio.h>
#include <iostream>
#include <output.h>
#include <action.h>
#include <automat.h>
#include <enumstate.h>
#include <enumcondition.h>

using namespace std;

int main()
{



    int work = 0;
    automat robot;
    cout<<"Задайте начальное состояние робота!!"<<endl;
    cout<<"test - 0, request_task - 1, start_task - 2, end_task - 3"<<endl;
    cout<<"go_to_the_charging_station - 4, charge - 5"<<endl;
    cout<<"error_message - 6, debug - 7, end - 8"<<endl;
    cout<<"Выйти из программы - 9"<<endl;
    cin>>work;
    robot.set_automat(test);
    while(work < 9)
    {
        getchar();
        system("clear");
        work = robot.work_automat(work);
        cout<<"выйти из программы - 10, продолжить - "<<work<<endl;
        cin>>work;
    }
    return 0;
}

