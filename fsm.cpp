#include <iostream>

typedef struct {
    State curSate;   //当前状态
    EventID eventId; //事件ID
    State nextState; //下个状态
    Action action;   //具体表现
} StateTransform;

typedef enum {
    state_1 = 1,
    state_2,
    state_3
} State;

typedef enum {
    event_1 = 1,
    event_2,
    event_3,
    event_4,
    event_5
} EventID;

enum Day {
    MON = 1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
};
enum enum_type_name {
    ENUM_CONST_1,
    ENUM_CONST_2,
    ENUM_CONST_n
} enum_variable_name;
typedef enum workday //此处的Workday可以省略，或者改成其他，不会影响后面
{
    saturday,
    sunday = 0,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday
} workday; //此处的workday为枚举型enum workday的别名，类似于int