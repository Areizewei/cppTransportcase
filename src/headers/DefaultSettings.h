#ifndef DEFAULTSETTINGS_H
#define DEFAULTSETTINGS_H
/*
 * DEFAULT_SETTINGS -> это список стандартных параметров программы,
 * которые нужны в случае повторного запуска программы (отсутствие конфиг. файлов).
 * В частности, определяются главные коэффициенты:
 *  Частота "несчастных" событий - NOT_STANDART;
 *  Частота появления заказов на товары - STANDART_EVENT;
 *  Стартовый капитал фирмы (без приращения) - CAPITAL;
 *  Количество машин, используемых в процессе работы компании - COUNT_CAR.
 *
 *  Определение констант находится в файле DefaultSettings.cpp.
*/
namespace DEFAULT_SETTINGS {
   extern const float DEFAULT_FREQUENCY_NOT_STANDART_EVENT;
   extern const float DEFAULT_FREQUENCY_STANDART_EVENT;
   extern const float DEFAULT_FARE_CAR;
   extern const float DEFAULT_FARE_PLANE;
   extern const float DEFAULT_CAPITAL;
   extern const float DEFAULT_COST_ORDER;
   extern const float DEFAULT_RATIO_CAR;
   extern const float DEFAULT_RATIO_PLANE;
   extern const float DEFAULT_RATIO_TRAIN;
   extern const float DEFAULT_LOST_RATIO_MONEY;
   extern const int DEFAULT_TIME_IN_WAY;
   extern const int DEFAULT_TIME_TO_EXECUTE;
   extern const int DEFAULT_COUNT_CAR;

}
#endif // DEFAULTSETTINGS_H
