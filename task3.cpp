/****************************************
* Автор: Ли Даниил                      *
* Задание: Циклы с пред- и постусловием *
* Вариант: 13                           *
****************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  constexpr int countOfSymbols1 = 5;
  constexpr int countOfSymbols2 = 10;
  constexpr int countOfDigitsAfterPoint = 3;

  double t1, t2, wide1, wide2, lambda1, lambda2, tempCoord,
         wallCoord, finishStep, thermalCond1, thermalCond2, step, t_c;
      
  cout << "Inner wall temperature, C: ";
  cin >> t1;
  cout << "Outer wall temperature, C: ";
  cin >> t2;
  cout << "Inner layer thickness, centimeters: ";
  cin >> wide1;
  cout << "Outer layer thickness, centimeters: ";
  cin >> wide2;
  cout << "Inner layer thermal conductivity: ";
  cin >> lambda1;
  cout << "Outer layer thermal conductivity: ";
  cin >> lambda2;

  thermalCond1 = lambda1 / wide1;    

  thermalCond2 = lambda2 / wide2;   

  t_c = (thermalCond1 * t1 + thermalCond2 * t2) / (thermalCond1 + thermalCond2);

  // 3 цифры после точки и вывод 
  cout << setprecision(countOfDigitsAfterPoint)
       << "Temperature at the layer interface: " << t_c << endl 
       << "    t         x" << endl;

  // шаг первого цикла
  step = 100.0;

  // граница: 1-й цикл работает пока t > 300
  finishStep = 300.0;

  // стартовая температура для 1-го цикла
  tempCoord = 500.0; 

  while (tempCoord > finishStep) {
 
    if (tempCoord > t_c) {
      wallCoord = (tempCoord - t1) / (t_c - t1) * wide1;
    } else {
      wallCoord = (tempCoord - t_c) / (t2 - t_c) * wide2 + wide1;
    }
        
    // setw() для следующего вывода выделяем необходимое число символов
    cout << setw(countOfSymbols1) << tempCoord
         << setw(countOfSymbols2) << wallCoord / 100.0 << endl;
        
    tempCoord -= step;
  }

  // шаг 2-го цикла
  step = 100.0;

  // старт 2-го цикла            
  tempCoord = 250.0; 

  do {

    if (tempCoord > t_c) {
      wallCoord = (tempCoord - t1) / (t_c - t1) * wide1;
    } else {
      wallCoord = (tempCoord - t_c) / (t2 - t_c) * wide2 + wide1;
    }

    cout << setw(countOfSymbols1) << tempCoord
         << setw(countOfSymbols2) << wallCoord / 100.0 << endl;
        
    tempCoord -= step;
  } while (tempCoord >= 150.0);

  return 0;
}
