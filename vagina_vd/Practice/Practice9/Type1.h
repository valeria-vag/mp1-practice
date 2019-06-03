#ifndef _TYPE_1_H_
#define _TYPE_1_H_
#include "Task.h"

class Type1 : public Task
{
public:
    Type1(string, Date);
    ~Type1();
    void print();
};
#endif