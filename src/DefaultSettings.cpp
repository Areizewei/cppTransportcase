#include "DefaultSettings.h"
/*
 * Определение констант  DefaultSettings.h
*/
namespace DEFAULT_SETTINGS {
    /* Приблизительно, на 111 раз генерации объекта будет создан объект, обозначающий NOT_STANDART_EVENT */
   extern const float DEFAULT_FREQUENCY_NOT_STANDART_EVENT {0.009};
   /* Генерация каждого объекта, в среднем, происходит раз в 25 секунд */
   extern const float DEFAULT_FREQUENCY_STANDART_EVENT {0.04};
   /* Стандартные стоимости прохождения 1 мили за определенный вид транспорта*/
   extern const float DEFAULT_FARE_CAR {70.01};
   extern const float DEFAULT_FARE_PLANE {140.47};
   /* Стартовый капитал компании */
   extern const float DEFAULT_CAPITAL {1204000.00};
   /* Минимальная стандартная стоимость заказа, которая может быть установлена */
   extern const float DEFAULT_COST_ORDER {10000};
   /* Рейты увеличения времени в пути */
   extern const float DEFAULT_RATIO_CAR {2.12};
   extern const float DEFAULT_RATIO_PLANE {0.8};
   extern const float DEFAULT_RATIO_TRAIN {1.2};
   /* Коэффициент потери денег за какие-либо события в пути*/
   extern const float DEFAULT_LOST_RATIO_MONEY {0.2};
   /* Дефолтное время в пути */
   extern const int DEFAULT_TIME_IN_WAY {600};
   /* Стандартное минимальное время исполнения заказа в секундах*/
   extern const int DEFAULT_TIME_TO_EXECUTE{60};
   /* Стандартное количество ТС компании */
   extern const int DEFAULT_COUNT_CAR {30};

}
