#include <action.h>

#ifndef AUTOMAT_H
#define AUTOMAT_H

class automat
{
    friend class action;
public:
    action *Action;
    automat(){};
    void set_automat(int fisrt_position);
    int work_automat(int status);
    ~automat(){};
private:
    int first_state;
    int current_state;
    int input_condition;
};

#endif // AUTOMAT_H
