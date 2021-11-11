#include "vplane.h"

VPlane::VPlane() : Vehicle()
{
}
VPlane::VPlane(QString& model, float EnginePower, float maxSpeed, float weight, float MAX_WEIGHT,  unsigned ReleaseYear, float fare)
    : Vehicle(model, EnginePower, maxSpeed, weight, MAX_WEIGHT, fare, ReleaseYear, DEFAULT_SETTINGS::DEFAULT_RATIO_PLANE)
{
}

const VehicleParams& VPlane::GetParams()
{
    return Vehicle::GetParams();
}
