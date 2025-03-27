#include <iostream>
#include <string>
#include <map>
using namespace std;
double EnterNumberh()
{

}
double EnterCalcNumber(int num_a)
{
    

}
double EnterNumberKonec(int num_a)
{

}
bool UserInput(string input) {
	if (input.empty()) return false;
	try {
		//преобразование введенного значения в тип int
		int number = stoi(input);
		if (number < 0) return false;
	}
	catch (...) //если возникла ошибка в блоке try
	{return false;}
	return true;
}
//вспомогательная функция для ввода целых чисел
function<void()> EnterNumber(int& varLink, string label) {
	return [&varLink, label]() {
		string raw_input;
		cout << label << " = ";
		getline(cin, raw_input);
		while (!UserInput(raw_input)) {
			cout << label << " = ";
			getline(cin, raw_input);
		}
		varLink = stoi(raw_input);
		};
}
int main() {
    //Создание меню с использованием map
    map<int, number> menu = {
       {1, {"Введите натуральное число X"},EnterNumberh};
       {2, {"Начинается ли оно и заканчивается одной и той же цифрой?"},EnterCalcNumber};
       {3, {"Заканчивается ли оно нечетной цифрой?"},EnterNumberKonec};
    };
    int choice = 0; 
    // Основной цикл программы
setlocale(LC_ALL, "RU");
cout << "Меню: " << endl;
// Вывод всех пунктов меню
for (const auto& item : menu) {
    cout << "Task " << item.first << ". " << item.second.title << endl;
}
cout << "0. Выход" << endl; // пункт для выхода из программы

while (true) {
    // Ввод выбора пользователя
    EnterNumber(choice, "Введите номер пункта: ");
    cin >> choice;
    // Выход из программы, если выбран пункт 0
    if (choice == 0) {
        cout << "2025 FirstName LastName" << endl;
        break;
    }
    cout << endl;
    // Проверка существует ли выбранный пункт меню
    if (menu.find(choice) != menu.end()) {
        menu[choice].action(); // Выполнение действия, связанного с пунктом меню
    }
    else {
        cout << "Некорректный ввод. "; // сообщение об ошибке, если пункт не найден
    }
    cout << endl << endl; 
}
return 0;
}