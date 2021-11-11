#include "handlerevent.h"
#include "DefaultSettings.h"
#include <QRandomGenerator>
HandlerEvent::HandlerEvent(Vehicle &vehicle, float FrequencyStandartEvent, float FrequencyNotStandartEvent)
{
    this->vehicle = &vehicle;
    this->FREQUENCY_STANDART_EVENT = FrequencyStandartEvent;
    this->FREQUENCY_NOT_STANDART_EVENT = FrequencyNotStandartEvent;
}
bool HandlerEvent::SetSettingsEvents(float FrequencyStandartEvent, float FrequencyNotStandartEvent)
{/* Вероятность не может быть больше 1 (100%) или меньше 0% */
    if (FrequencyStandartEvent <= 0 || FrequencyNotStandartEvent <= 0)
        return false;
    else if (FrequencyStandartEvent > 1 || FrequencyNotStandartEvent > 1)
        return false;
    else {
        this->FREQUENCY_STANDART_EVENT = FrequencyStandartEvent;
        this->FREQUENCY_NOT_STANDART_EVENT = FrequencyNotStandartEvent;
        return true;
    }
}

bool HandlerEvent::GenerationEvent()
{
    this->GenerationStatus();
    ;
    return this->RecordToOrder();
}

/* Генерация случайного типа Event */
void HandlerEvent::GenerationStatus()
{
 /* Описание работы
  * Данная функция с FREQUENCY(_NOT)_STANDART_EVENT вероятностью генерирует число,
  * которое входит  в определенный диапазон чисел событий Event.
  * Конечное число представляет собой беззнаковый целочисленный тип.
  * Вычисляется по формуле:
  * P(S, NS) = ( An * F(S)) + (Zn * F(NS));
  * Где P -итоговая вероятность,
  * An, Zn - случайные числа в диапазоне от 0 до 1000 включительно,
  * F(S) - стандартная частота вероятности обычного события,
  * F(NS) - частота появления нестандартного события.
  *
  * Сумма обеих вероятностей для появления случайного события должна быть больше 35.
  */
    float chanceStandart = QRandomGenerator::global()->bounded(0, 1001) * this->FREQUENCY_STANDART_EVENT;
    float chanceNotStandart = QRandomGenerator::global()->bounded(0, 1001) * this->FREQUENCY_NOT_STANDART_EVENT;
    float TotalChance = chanceStandart + chanceNotStandart;
    if (TotalChance > 35) {
        unsigned RandomNumber = QRandomGenerator::global()->bounded(201, 205);
        switch(RandomNumber) {
        case EVENT_ACCIDENT:
            this->evtStatus = 201;
            break;
        case EVENT_BAD_ROAD:
            this->evtStatus = 202;
            break;
        case EVENT_BAD_WEATHER:
            this->evtStatus = 203;
            break;
        default:
            this->evtStatus = 200;
        }
    } else
        this->evtStatus = 200;

}
/* Запись данных в параметры vehicle*/
bool HandlerEvent::RecordToOrder()
{
    switch (this->evtStatus) {
    case EVENT_ACCIDENT:
        this->vehicle->SetEventOrder("Произошла авария, возможны задержки.");
        break;
    case EVENT_BAD_ROAD:
        this->vehicle->SetEventOrder("Плохие дороги. Это может повредить товар!");
        break;
    case EVENT_BAD_WEATHER:
        this->vehicle->SetEventOrder("Плохая видимость в пути");
        break;
    default:
        this->vehicle->SetEventOrder("Дорога не предвещает беды");
        return true;
        break;
    }
    this->vehicle->AddLostCostOrder(this->vehicle->GetCostOrder()*DEFAULT_SETTINGS::DEFAULT_LOST_RATIO_MONEY);

    return true;
}
