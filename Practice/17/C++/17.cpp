#include <iostream>
using namespace std;
const int dlina_massiva = 37;
const int k = 12;
// b -- Чёрные, r -- Красные.
int main() {
    int count[dlina_massiva];            
    int round_appearance[dlina_massiva]; 
    for (int i = 0; i < dlina_massiva; i++)
        count[i] = round_appearance[i] = 0;

    int input;
    int round_counter = 0;
    int b = 0, r = 0;
    while (++round_counter) {
        cin >> input;
        if (input < 0)
            break;

        count[input]++;
        round_appearance[input] = round_counter;
    // Нахождение наибольшего из введённых
        int highest_number = -1;
        for (int i = 0; i < dlina_massiva; i++)
            if (count[i] > highest_number)
                highest_number = count[i];
    // Вывод на экран наибольшего числа
        for (int i = 0; i < dlina_massiva; i++)
            if (count[i] == highest_number)
                cout << i << " ";
              cout << endl;

              //Вывожу на экран массив, без введённых элементов
        for (int i = 0; i < dlina_massiva; i++)
            if (round_appearance[i] == 0 || (round_counter - round_appearance[i] > k))
                cout << i << " ";
            cout << endl;
    // Подсчёт красных и чёрных ячеек на поле
        if (input != 0) {
            if (input <= 10 || (input > 18 && input <= 28))
                if (input % 2 == 1) 
                    r = r + 1;
                else                
                    b = b + 1;
                else
                if (input % 2 == 0) 
                    r = r + 1;
                else                
                    b = b + 1;
        }

        cout << r << " " << b << endl;
        cout << endl;
    }
}