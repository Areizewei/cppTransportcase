#ifndef SORDERPARAMS_H
#define SORDERPARAMS_H
#include <QString>
struct OrderParams {
    QString City;
    QString Event;
    bool ExecuteOrder = false;
    float CostOrder;
    float LostOrder = 0.0;
    int TimeToExecuteOrder;
};
#endif // SORDERPARAMS_H
