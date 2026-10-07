/****************************************
* Автор: Ли Даниил                      *
* Задание: Циклы с пред- и постусловием *
* Вариант: 13                           *
****************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
   
  double tempIn, tempOver, wideIn, wideOver,
         lambdaIn, lambdaOver, tempCoordinates,
         wallCoordinates, finishStep;
    

  int step;      // текущий шаг изменения температуры, °C

  cout << "Inner wall temperature, C: ";
  cin >> tempIn;
  cout << "Outer wall temperature, C: ";
  cin >> tempOver;
  cout << "Inner layer thickness, см: ";
  cin >> wideIn;
  cout << "Outer layer thickness, см: ";
  cin >> wideOver;
  cout << "Inner layer thermal conductivity: ";
  cin >> lambdaIn;
  cout << "Outer layer thermal conductivity: ";
  cin >> lambdaOver;

  
  double thermalConductanceIn = lambdaIn / wideIn;       // проводимость 1-го слоя
  double thermalConductanceOver = lambdaOver / wideOver; // проводимость 2-го слоя
  // Температура на границе слоёв
  double temperatureBetween = (thermalConductanceIn * tempIn + thermalConductanceOver * tempOver) /
                              (thermalConductanceIn + thermalConductanceOver);

  cout << fixed << setprecision(3);   // 3 цифры после точки
  cout << "Temperature at the layer interface: " << temperatureBetween << endl;
  cout << "    t         x" << endl;


  step = 100;            // шаг первого цикла
  finishStep = 300;      // граница: 1-й цикл работает пока t > 300
  tempCoordinates = 500; // стартовая температура для 1-го цикла

  while (tempCoordinates > finishStep) 
  {
    if (tempCoordinates > temperatureBetween)
      wallCoordinates = (tempCoordinates - tempIn) /
      (temperatureBetween - tempIn) * wideIn;
    else
      wallCoordinates = (tempCoordinates - temperatureBetween) /
      (tempOver - temperatureBetween) * wideOver + wideIn;

    cout << setw(5) << tempCoordinates                  // setw(5) для красивого вывода
         << setw(10) << wallCoordinates / 100 << endl;   // делим на 100 переводя в метры
    tempCoordinates -= step;
  }

  step = 100;            // шаг 2-го цикла
  tempCoordinates = 250; // старт 2-го цикла

  do 
  {
    if (tempCoordinates > temperatureBetween)
      wallCoordinates = (tempCoordinates - tempIn) /
      (temperatureBetween - tempIn) * wideIn;
    else
      wallCoordinates = (tempCoordinates - temperatureBetween) /
      (tempOver - temperatureBetween) * wideOver + wideIn;

    cout << setw(5) << tempCoordinates
         << setw(10) << wallCoordinates / 100 << endl;   // делим на 100 переводя в метры
    tempCoordinates -= step;
  } while (tempCoordinates >= 150);

return 0;
}