#include "handlerorders.h"
#include <QRandomGenerator>

HandlerOrders::HandlerOrders(Vehicle &vehicle)
{/* Получение валидного адреса существующего объекта */
    this->vehicle = &vehicle;
}
bool HandlerOrders::ChangeObject(Vehicle &vehicle)
{ /* Объект не изменится, если это будет он же сам */
    if (this->vehicle->GetID() == vehicle.GetID())
        return false;
    else
        this->vehicle = &vehicle;
    return true;
}
bool HandlerOrders::CreateOrder()
{
    if ( this->isHaveOrder() )
        return false;
    this->GenerationWay();
    this->GenerationTimeToExecute();
    this->GenerationCost();
    this->GenerationCity();
    this->RecordToOrder();
    return true;
}

bool HandlerOrders::isHaveOrder()
{
    return vehicle->GetStatusOrder();
}
void HandlerOrders::RecordToOrder()
{
    this->vehicle->SetCostOrder(this->COST_ORDER);
    this->vehicle->SetStatusExecuteOrder(true);
    this->vehicle->SetTimeToExecuteOrder(this->TIME_TO_EXECUTE);
    this->vehicle->SetCityOrder(this->SelectedCity);
}
void HandlerOrders::GenerationCost()
{
    this->COST_ORDER = vehicle->GetParams().p_costMile * this->WAY_TO_ORDER;
}
void HandlerOrders::GenerationTimeToExecute()
{
    this->TIME_TO_EXECUTE = this->WAY_TO_ORDER / vehicle->GetParams().p_maxSpeed;
}
void HandlerOrders::GenerationWay()
{
    /*
     * Путь вычисляется по следующей формуле:
     *  S = dX * t * 2 / Ix;
     * Где dX - это ratior slow ТС,
     * t - стандартное время в пути;
     * Ix - случайный коэффициент, генерируемый в процессе работы алгоритма.
     */

    float RandomNumber = QRandomGenerator::global()->bounded(2.0);
    this->WAY_TO_ORDER = vehicle->GetParams().p_ratioSlow * DEFAULT_SETTINGS::DEFAULT_TIME_IN_WAY * 2 / RandomNumber;
}
void HandlerOrders::GenerationCity()
{ /* Генерация случайного города*/
    /* Подобное преобразование не рекомендуется к использованию.
     * В данном случае, генерируется случайное число, которое приводится
     * к City.
    */
    City city = static_cast<City>(QRandomGenerator::global()->bounded(0, MAX_COUNT_CITY));
    switch (city) {
    case MOSCOW:
        this->SelectedCity = "Moscow";
        break;
    case PITER:
        this->SelectedCity = "Piter";
        break;
    case KALININGRAD:
        this->SelectedCity = "Kaliningrad";
        break;
    case SAXALINSK:
        this->SelectedCity = "Saxalinsk";
        break;
    case BERLIN:
        this->SelectedCity = "Berlin";
        break;
    default:
        this->SelectedCity = "Other city";
        break;
    }

}
