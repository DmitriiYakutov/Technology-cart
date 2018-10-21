#ifndef OUTPUT_H
#define OUTPUT_H


class output
{
public:
    output(){};
    void set_output(bool status);
    void set_name(char *set, int index, int next);
    char* get_name();
    int get_name_index();
    bool get_state();
    int get_next_state();
    ~output(){};
private:
    char *name_output;
    bool state_output;
    int index_name;
    int next_state;
};

#endif // OUTPUT_H
