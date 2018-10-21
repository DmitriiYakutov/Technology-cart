#include <output.h>

#ifndef ACTION_H
#define ACTION_H

class action
{
public:
    friend class input;
    friend class output;
    output* Output;
    action(){};
    void set_name(char *set, int index);
    char* get_name();
    ~action();
private:
    char *name_action;
    int index_name;
    bool state;
};
#endif // ACTION_H
