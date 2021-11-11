#include "vehicle.h"
int Vehicle::current_ID = 0;

Vehicle::Vehicle() : ID(current_ID++)
{
}
Vehicle::Vehicle(QString& model, float EnginePower, float maxSpeed, float weight, float MAX_WEIGHT, float fare, unsigned ReleaseYear, float ratioSlow) : Vehicle()
{
    Params.p_model = model;
    Params.p_enginePower = EnginePower;
    Params.p_maxSpeed = maxSpeed;
    Params.p_weight = weight;
    Params.p_MAX_WEIGHT = MAX_WEIGHT;
    Params.p_costMile = fare;
    Params.p_ReleaseYear = ReleaseYear;
    Params.p_ratioSlow = ratioSlow;
}

const VehicleParams& Vehicle::GetParams() { return Params; }
const OrderParams& Vehicle::GetParamsOrder() { return OParams; }

unsigned Vehicle::GetID() { return ID; }

int Vehicle::GetTimeToExecuteOrder() { return this->OParams.TimeToExecuteOrder; }
bool Vehicle::SetTimeToExecuteOrder(int inSeconds)
{ /* Минимальное время исполнения заказа не может быть меньше  DEFAULT_TIME_TO_EXECUTE */
    if (inSeconds < DEFAULT_SETTINGS::DEFAULT_TIME_TO_EXECUTE)
        return false;
    else
        this->OParams.TimeToExecuteOrder = inSeconds;
    return true;
}

bool Vehicle::SetStatusExecuteOrder(bool isExecute) { this->OParams.ExecuteOrder = isExecute; return true; }
bool Vehicle::GetStatusOrder() { return this->OParams.ExecuteOrder; }

bool Vehicle::SetCostOrder(float CostInRubles)
{/* Цена заказа не может быть минимально стандартной DEFAULT_COST_ORDER */
    if (CostInRubles < DEFAULT_SETTINGS::DEFAULT_COST_ORDER)
        return false;
    else
        this->OParams.CostOrder = CostInRubles;
    return true;
}
float Vehicle::GetCostOrder() { return this->OParams.CostOrder; }
bool Vehicle::AddLostCostOrder(float CostInRubles)
{ /* Денежная сумма не может быть отрицательной */
    if (CostInRubles <= 0)
        return false;
    else
        this->OParams.LostOrder += CostInRubles;
    return true;
}
float Vehicle::GetLostCostOrder() { return this->OParams.LostOrder; }

bool Vehicle::SetEventOrder(QString Event)
{ /* В данном случае, Event не может иметь длину меньше 3 */
    if (Event.length() < 3)
        return false;
    else
        this->OParams.Event = Event;
    return true;
}
QString Vehicle::GetEventOrder() { return this->OParams.Event; }

bool Vehicle::SetCityOrder(QString City)
{ /* В данном случае, City не может иметь длину меньше 3 */
    if (City.length() < 3)
        return false;
    else
        this->OParams.City = City;
    return true;
}
QString Vehicle::GetCityOrder() { return this->OParams.City; }
