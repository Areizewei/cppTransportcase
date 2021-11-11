#ifndef HANDLERORDERS_H
#define HANDLERORDERS_H
#include "vehicle.h"
/*
 * HandlerOrders - класс-обработчик, предназначенный для заполнения
 * необходимых полей в объекте-наследнике Vehicle.
 * Предоставляет функционал, позволяющий работать с одним объектом семейства Vehicle.
 *
 * Класс не имеет представления о том, с каким количеством объектов он работает.
 * На вход нему поступает один объект, вследствие которого он вызывает обработчик заказа.
 * Если же заказ уже был создан, тогда возвращается false и выполнение кода продолжается
 * в штатном режиме. Исключение не выбрасывается.
*/
class HandlerOrders
{
public:
    HandlerOrders(Vehicle &vehicle);
    /* Изменение адреса объекта, с которым происходит обработка заказов */
    bool ChangeObject(Vehicle &vehicle);
    /* Создание заказа у объекта */
    bool CreateOrder();

protected:
    /* Запись настроек в параметры объекта-наследника Vehicle */
    void RecordToOrder();
    /* Формирование цены */
    void GenerationCost();
    /* Генерация времени выполнения заказа */
    void GenerationTimeToExecute();
    /* Генерация длины пути заказа */
    void GenerationWay();
    /* Генерация случайного города и его запись */
    void GenerationCity();
    /* Проверка существования заказа */
    bool isHaveOrder();

private:
    enum City {
      MOSCOW,
      PITER,
      KALININGRAD,
      SAXALINSK,
      BERLIN
    };

   Vehicle *vehicle;
   QString SelectedCity;
   int MAX_COUNT_CITY = 5;
   float COST_ORDER;
   float WAY_TO_ORDER;
   int TIME_TO_EXECUTE;
};

#endif // HANDLERORDERS_H
