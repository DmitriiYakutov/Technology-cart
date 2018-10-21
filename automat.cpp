#include "automat.h"
#include <enumstate.h>
#include <enumcondition.h>
#include <QCoreApplication>
#include <stdio.h>
#include <iostream>
#include <output_automat.h>

using namespace std;

    void automat::set_automat(int fisrt_position)
    {
        cout<<"Строится автомат!!"<<endl;
        Action = new action[end];

//названия вершин графа
        Action[test].set_name("Проверка систем", test);
        Action[request_task].set_name("Запрос задачи", request_task);
        Action[start_task].set_name("Выполнене задачи", start_task);
        Action[end_task].set_name("Завершение задачи", end_task);
        Action[go_to_the_charging_station].set_name("Следовать до зарядной  станции", go_to_the_charging_station);
        Action[charge].set_name("Процедура зарядки", charge);
        Action[error_message].set_name("Сообщение об ошибке", error_message);
        Action[debug].set_name("Устранение ошибок", debug);
        Action[end].set_name("Отключение", end);


//создание таблицы переходов
        int root = test;
        Action[root].Output[test].set_output(TRUE);
        Action[root].Output[test].set_name("Система не проверена", no_test, test);
        Action[root].Output[request_task].set_output(TRUE);
        Action[root].Output[request_task].set_name("Система проверена, нет ошибок", no_errors, request_task);
        Action[root].Output[start_task].set_output(FALSE);
        Action[root].Output[end_task].set_output(FALSE);
        Action[root].Output[go_to_the_charging_station].set_output(TRUE);
        Action[root].Output[go_to_the_charging_station].set_name("Низкий уровень заряда", low_charge, go_to_the_charging_station);
        Action[root].Output[charge].set_output(FALSE);
        Action[root].Output[error_message].set_output(TRUE);
        Action[root].Output[error_message].set_name("Обнаружены ошибки", errors, error_message);
        Action[root].Output[debug].set_output(FALSE);
        Action[root].Output[end].set_output(FALSE);

        root = request_task;
        Action[root].Output[test].set_output(FALSE);
        Action[root].Output[request_task].set_output(TRUE);
        Action[root].Output[request_task].set_name("Запрашивается задача", no_message_task, request_task);
        Action[root].Output[start_task].set_output(TRUE);
        Action[root].Output[start_task].set_name("Задача получена", get_task, start_task);
        Action[root].Output[end_task].set_output(FALSE);
        Action[root].Output[go_to_the_charging_station].set_output(TRUE);
        Action[root].Output[go_to_the_charging_station].set_name("Задач нет", no_task, go_to_the_charging_station);
        Action[root].Output[charge].set_output(FALSE);
        Action[root].Output[error_message].set_output(FALSE);
        Action[root].Output[debug].set_output(FALSE);
        Action[root].Output[end].set_output(FALSE);

        root = start_task;
        Action[root].Output[test].set_output(FALSE);
        Action[root].Output[request_task].set_output(FALSE);
        Action[root].Output[start_task].set_output(TRUE);
        Action[root].Output[start_task].set_name("Задача выполняется", no_end_task, start_task);
        Action[root].Output[end_task].set_output(TRUE);
        Action[root].Output[end_task].set_name("Задача выполнена", off_task, end_task);
        Action[root].Output[go_to_the_charging_station].set_output(FALSE);
        Action[root].Output[charge].set_output(FALSE);
        Action[root].Output[error_message].set_output(FALSE);
        Action[root].Output[debug].set_output(FALSE);
        Action[root].Output[end].set_output(FALSE);

        root = end_task;
        Action[root].Output[test].set_output(TRUE);
        Action[root].Output[test].set_name("Задача завершена", no_end_task, test);
        Action[root].Output[request_task].set_output(FALSE);
        Action[root].Output[start_task].set_output(FALSE);
        Action[root].Output[end_task].set_output(TRUE);
        Action[root].Output[end_task].set_name("Задача завершена", off_task, end_task);
        Action[root].Output[go_to_the_charging_station].set_output(FALSE);
        Action[root].Output[charge].set_output(FALSE);
        Action[root].Output[error_message].set_output(FALSE);
        Action[root].Output[debug].set_output(FALSE);
        Action[root].Output[end].set_output(FALSE);

        root = go_to_the_charging_station;
        Action[root].Output[test].set_output(FALSE);
        Action[root].Output[request_task].set_output(FALSE);
        Action[root].Output[start_task].set_output(FALSE);
        Action[root].Output[end_task].set_output(FALSE);
        Action[root].Output[go_to_the_charging_station].set_output(TRUE);
        Action[root].Output[go_to_the_charging_station].set_name("Не доехал до ЗС", no_in_charge, go_to_the_charging_station);
        Action[root].Output[charge].set_output(TRUE);
        Action[root].Output[charge].set_name("Доехал до ЗС", in_charge, charge);
        Action[root].Output[error_message].set_output(FALSE);
        Action[root].Output[debug].set_output(FALSE);
        Action[root].Output[end].set_output(FALSE);

        root = charge;
        Action[root].Output[test].set_output(TRUE);
        Action[root].Output[test].set_name("Зарядка завершена", no_test, test);
        Action[root].Output[request_task].set_output(FALSE);
        Action[root].Output[start_task].set_output(FALSE);
        Action[root].Output[end_task].set_output(FALSE);
        Action[root].Output[go_to_the_charging_station].set_output(FALSE);
        Action[root].Output[charge].set_output(TRUE);
        Action[root].Output[charge].set_name("Зарядка не завершена", no_test, charge);
        Action[root].Output[error_message].set_output(FALSE);
        Action[root].Output[debug].set_output(FALSE);
        Action[root].Output[end].set_output(FALSE);

        root = error_message;
        Action[root].Output[test].set_output(FALSE);
        Action[root].Output[request_task].set_output(FALSE);
        Action[root].Output[start_task].set_output(FALSE);
        Action[root].Output[end_task].set_output(FALSE);
        Action[root].Output[go_to_the_charging_station].set_output(FALSE);
        Action[root].Output[charge].set_output(FALSE);
        Action[root].Output[error_message].set_output(TRUE);
        Action[root].Output[error_message].set_name("Сообщение об ошибке формируется", errors_not_show, error_message);
        Action[root].Output[debug].set_output(TRUE);
        Action[root].Output[debug].set_name("Сообщение об ошибке выведено", errors_show, debug);
        Action[root].Output[end].set_output(TRUE);
        Action[root].Output[end].set_name("Есть критические ошибки", critical_errors, end);

        root = debug;
        Action[root].Output[test].set_output(TRUE);
        Action[root].Output[test].set_name("Ошибки исправлены", errors_solved, test);
        Action[root].Output[request_task].set_output(FALSE);
        Action[root].Output[start_task].set_output(FALSE);
        Action[root].Output[end_task].set_output(FALSE);
        Action[root].Output[go_to_the_charging_station].set_output(FALSE);
        Action[root].Output[charge].set_output(FALSE);
        Action[root].Output[error_message].set_output(FALSE);
        Action[root].Output[debug].set_output(TRUE);
        Action[root].Output[debug].set_name("Ошибки исправляются", errors_not_solved, debug);
        Action[root].Output[end].set_output(FALSE);

        root = end;
        Action[root].Output[test].set_output(FALSE);
        Action[root].Output[request_task].set_output(FALSE);
        Action[root].Output[start_task].set_output(FALSE);
        Action[root].Output[end_task].set_output(FALSE);
        Action[root].Output[go_to_the_charging_station].set_output(FALSE);
        Action[root].Output[charge].set_output(FALSE);
        Action[root].Output[error_message].set_output(FALSE);
        Action[root].Output[debug].set_output(FALSE);
        Action[root].Output[end].set_output(TRUE);
        Action[root].Output[end].set_name("Отключение", off, end);

        first_state = fisrt_position;
    }

    int automat::work_automat(int status)
    {
       int jump;
       current_state  = status;
       cout<<"Выберите условие для перехода:"<<endl;
       outputAutomat(Action[current_state]);
       cin>>jump;
       cout<<endl;
       if(Action[current_state].Output[jump].get_next_state() == jump)
         current_state = jump;
       outputAutomat(Action[current_state]);
       return current_state;

    }
