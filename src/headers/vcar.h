#ifndef VCAR_H
#define VCAR_H
#include "vehicle.h"

class VCar : public Vehicle
{
public:
    VCar();
    VCar(QString& model, float EnginePower, float maxSpeed, float weight, float MAX_WEIGHT,  unsigned ReleaseYear, float fare);
    const VehicleParams& GetParams();
    float GetTraveledMile();
    float GetGoalMile();
    bool SetTraveledMile(float traveledMile);
    bool setGoalMile(float goalMile);
private:
    /*
     * Variables:
     * @float traveledMile -> переменная, содержащая в себе значение пройденного пути
     * машиной;
     * @float goalMile -> переменная, содержащая в себе путь, который должна проехать машина.
    */

    float traveledMile = 0.0; // Изначально, машина не проехала никакого расстояния
    float goalMile;

};

#endif // VCAR_H
