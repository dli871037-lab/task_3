/******************************
* Автор: Ли Даниил            *
* Задание: Линейные алгоритмы *
* Вариант: 13                 *
******************************/

#include <iostream>
#include <iomanip>  //для красивого формата вывода

using namespace std;

int main()
{
  double tempIn, tempOver, wideIn, wideOver, thermalCondIn, thermalCondOver,
         tempCoordinates, wallCoordinates, finishstep, step;

  cout << "Температура внутренней стенки, C: ";
  cin >> tempIn;
  cout << "Температура внешней стенки, C: ";
  cin >> tempOver;
  cout << "Толщина внутреннего слоя, см: ";
  cin >> wideIn;
  cout << "Толщина внешнего слоя, см: ";
  cin >> wideOver;
  cout << "Теплопроводность внутреннего слоя: ";
  cin >> thermalCondIn;
  cout << "Теплопроводность внешнего слоя: ";
  cin >> thermalCondOver;

  
  double g1 = thermalCondIn / wideIn;    // проводимость 1-го слоя
  double g2 = thermalCondOver / wideOver;  // проводимость 2-го слоя
  double temperatureBetween = (g1 * tempIn + g2 * tempOver) / (g1 + g2);   // температура на границе слоёв

  int step = 100;  // шаг 1 цикла
  finishstep = 300;   // произвольный параметр для завершения 1 цикла 
  tempCoordinates = 500;

  while (tempCoordinates > finishstep)
  {
    if (tempCoordinates > temperatureBetween)
      wallCoordinates = (tempCoordinates - tempIn) /
      (temperatureBetween - tempIn) * wideIn;
    else
      wallCoordinates = (tempCoordinates - temperatureBetween) /
      (tempOver - temperatureBetween) * wideOver + wideIn;

    cout << fixed << setprecision(3) << wallCoordinates / 100 << endl;  // вывод координат в метрах и 3 числа после точки
    tempCoordinates -= step;
  }

  // меняем шаг и начинаем с новой температуры для второго цикла
  step = 75;
  tempCoordinates = 250;

  do
  {
    if (tempCoordinates > temperatureBetween)
      wallCoordinates = (tempCoordinates - tempIn) /
      (temperatureBetween - tempIn) * wideIn;
    else
      wallCoordinates = (tempCoordinates - temperatureBetween) /
      (tempOver - temperatureBetween) * wideOver + wideIn;

    cout << fixed << setprecision(3) << wallCoordinates / 100 << endl;  // вывод координат в метрах и 3 числа после точки
    tempCoordinates -= step;
   } while (tempCoordinates >= 150);

  return 0;
}