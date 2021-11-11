#ifndef VEHICLE_H
#define VEHICLE_H
#include <QString>
#include "DefaultSettings.h"
#include "sOrderParams.h"
struct VehicleParams {
    QString p_model;
    float p_enginePower;
    float p_maxSpeed;
    float p_weight;
    float p_MAX_WEIGHT;
    unsigned p_ReleaseYear;
    float p_costMile;
    float p_ratioSlow;

    VehicleParams() : p_model("Vehicle"), p_enginePower(0.0), p_maxSpeed(0.0),
        p_weight(0.0), p_MAX_WEIGHT(0.0), p_ReleaseYear(2017),
         p_costMile(79.02)
    {
    }
    VehicleParams(const VehicleParams &other)
    {
        this->p_model = other.p_model;
        this->p_enginePower = other.p_enginePower;
        this->p_maxSpeed = other.p_maxSpeed;
        this->p_weight = other.p_weight;
        this->p_MAX_WEIGHT = other.p_MAX_WEIGHT;
        this->p_ReleaseYear = other.p_ReleaseYear;
        this->p_costMile = other.p_costMile;
        this->p_ratioSlow = other.p_ratioSlow;
    }
    VehicleParams(QString model, float enginePower, float maxSpeed, float weight, float MAX_WEIGHT, unsigned ReleaseYear, float fare, float ratioSlow)
        : p_model(model), p_enginePower(enginePower), p_maxSpeed(maxSpeed),
          p_weight(weight), p_MAX_WEIGHT(MAX_WEIGHT), p_ReleaseYear(ReleaseYear),
          p_costMile(fare), p_ratioSlow(ratioSlow)
    { }
    VehicleParams& operator =(const VehicleParams &other)
    {
        this->p_model = other.p_model;
        this->p_enginePower = other.p_enginePower;
        this->p_maxSpeed = other.p_maxSpeed;
        this->p_weight = other.p_weight;
        this->p_MAX_WEIGHT = other.p_MAX_WEIGHT;
        this->p_ReleaseYear = other.p_ReleaseYear;
        this->p_costMile = other.p_costMile;
        this->p_ratioSlow = other.p_ratioSlow;
        return *this;
    }
};


/*
 * CLASS Vehicle
 * - класс, предназначенный для работы с объектами типа ТС,
 * в их абстрактном виде.
 * В программном коде объекты данного класса в его чистом виде не используются.
 * Вместо этого используется концепция наследования, которая и реализует
 * интерфейс данного класса.
 * Его стандартное назначение -
 * описание некоторые параметров, методов, необходимых для реализации объектов одинакового типа.
 *
 * Его дополнительное назначение -
 * это описание интерфейса исполнения заказов.
 * Такое решение не применимо в контексте реальных задач,
 * но возможно к использованию в учебных целях, где действует правило:
 * @нуль - один - много@ (проект относится к нулю, дальнейшего масштабирования не будет)
 */
class Vehicle
{
protected:
    VehicleParams Params;
    OrderParams OParams;
    unsigned int ID;
    static int current_ID;
public:
    Vehicle();
    Vehicle(const Vehicle&);
    Vehicle(QString&, float, float, float, float, float, unsigned, float);

    const VehicleParams& GetParams();
    const OrderParams& GetParamsOrder();

    unsigned GetID();

    bool SetTimeToExecuteOrder(int inSeconds);
    int GetTimeToExecuteOrder();

    bool SetStatusExecuteOrder(bool isExecute);
    bool GetStatusOrder();

    bool SetCostOrder(float CostInRubles);
    float GetCostOrder();

    bool AddLostCostOrder(float CostInRubles);
    float GetLostCostOrder();

    bool SetEventOrder(QString Event);
    QString GetEventOrder();

    bool SetCityOrder(QString City);
    QString GetCityOrder();




};


#endif // VEHICLE_H
