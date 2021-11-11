#include "vcar.h"

VCar::VCar() : Vehicle()
{
}
VCar::VCar(QString& model, float EnginePower, float maxSpeed, float weight, float MAX_WEIGHT,  unsigned ReleaseYear, float fare)
    : Vehicle(model, EnginePower, maxSpeed, weight, MAX_WEIGHT, fare, ReleaseYear, DEFAULT_SETTINGS::DEFAULT_RATIO_CAR)
{
}

const VehicleParams& VCar::GetParams()
{
    return Vehicle::GetParams();
}
float VCar::GetTraveledMile() { return this->traveledMile; }
float VCar::GetGoalMile() { return this->goalMile; }
bool  VCar::SetTraveledMile(float traveledMile)
{/* Миля не может быть отрицательной, она всегда положительна */
    if (traveledMile <= 0)
        return false;
    else
        this->traveledMile = traveledMile;
    return true;
}
bool VCar::setGoalMile(float goalMile)
{ /* Путь не может быть меньше пройденных миль. */
    if (goalMile < this->traveledMile)
        return false;
    else
        this->goalMile = goalMile;
    return true;
}
