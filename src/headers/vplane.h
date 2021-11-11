#ifndef VPLANE_H
#define VPLANE_H

#include "vehicle.h"

class VPlane : public Vehicle
{
public:
    VPlane();
    VPlane(QString& model, float EnginePower, float maxSpeed, float weight, float MAX_WEIGHT,  unsigned ReleaseYear, float fare);
    const VehicleParams& GetParams();
};

#endif // VPLANE_H
