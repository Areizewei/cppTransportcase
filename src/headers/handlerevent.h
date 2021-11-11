#ifndef HANDLEREVENT_H
#define HANDLEREVENT_H
#include "vehicle.h"

/*
 * CLASS HandlerEvent
 * - класс-обработчик, предназначенный для работами с "событиями".
 * Под событием подразумевается некоторая нестандартная логика,
 * приводящая к появлениям исключительных ситуаций.
 *
 * Событие можно вызвать специально, в независимости оттого, было ли оно определено поведением
 * класса.
 *
 */

class HandlerEvent
{
public:
    HandlerEvent(Vehicle &vehicle, float FrequencyStandartEvent, float FrequencyNotStandartEvent);

    /* Настройка стандартных параметров генерации событий */
    bool SetSettingsEvents(float FrequencyStandartEvent, float FrequencyNotStandartEvent);
    /* Генерация случайного события */
    bool GenerationEvent();
protected:
    /* Генерация случайного типа Event */
    void GenerationStatus();
    /* Запись данных в параметры vehicle*/
    bool RecordToOrder();
private:
    enum Event {
        NO_EVENT = 200,
        EVENT_ACCIDENT,
        EVENT_BAD_WEATHER,
        EVENT_BAD_ROAD
    };
    Vehicle *vehicle;
    QString Event;
    unsigned evtStatus;
    float FREQUENCY_NOT_STANDART_EVENT;
    float FREQUENCY_STANDART_EVENT;
};

#endif // HANDLEREVENT_H
