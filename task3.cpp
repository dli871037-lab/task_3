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
           wallCoordinates, finishStep, thermalConductanceIn,
           thermalConductanceOver, step, temperatureBetween;
      
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

    // проводимость 1-го слоя
    thermalConductanceIn = lambdaIn / wideIn;    

    // проводимость 2-го слоя
    thermalConductanceOver = lambdaOver / wideOver;   

    // Температура на границе слоёв
    temperatureBetween = (thermalConductanceIn * tempIn + thermalConductanceOver * tempOver) /
                         (thermalConductanceIn + thermalConductanceOver);

    // 3 цифры после точки и вывод 
    cout << fixed << setprecision(3)    
         << "Temperature at the layer interface: " << temperatureBetween << endl 
         << "    t         x" << endl;

    // шаг первого цикла
    step = 100.0;

    // граница: 1-й цикл работает пока t > 300
    finishStep = 300.0;

    // стартовая температура для 1-го цикла
    tempCoordinates = 500.0; 

    while (tempCoordinates > finishStep)
    {
        if (tempCoordinates > temperatureBetween) {
            wallCoordinates = (tempCoordinates - tempIn) / (temperatureBetween - tempIn) * wideIn;
        }
            
        else {
            wallCoordinates = (tempCoordinates - temperatureBetween) / (tempOver - temperatureBetween) * wideOver + wideIn;
        }
        
        // setw(5) для красивого вывода (будет выводится только первые 5 цифр) и делим координаты на 100, переводя в метры
        cout << setw(5) << tempCoordinates                  
             << setw(10) << wallCoordinates / 100.0 << endl;  
        
        tempCoordinates -= step;
    }

    // шаг 2-го цикла
    step = 100.0;

    // старт 2-го цикла            
    tempCoordinates = 250.0; 

    do
    {
        if (tempCoordinates > temperatureBetween) {
            wallCoordinates = (tempCoordinates - tempIn) / (temperatureBetween - tempIn) * wideIn;
        }
            
        else {
            wallCoordinates = (tempCoordinates - temperatureBetween) / (tempOver - temperatureBetween) * wideOver + wideIn;
        }
        // выводим первые 5 цифр у температуры и первые 10 у координат, также переводим координаты в метры
        cout << setw(5) << tempCoordinates
             << setw(10) << wallCoordinates / 100.0 << endl;  
        
        tempCoordinates -= step;
    } while (tempCoordinates >= 150.0);

    return 0;
}
