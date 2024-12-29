#include <iostream>
#include <Cluster.h>

void main()
{
    setlocale(LC_ALL, "Russian");
	int processor_num; // количество процессоров в кластере
	int tact_work_max; // максимальное количество тактов работы кластера
	double threshold; //порог появления программы
	int R; // количество программ, появляюшихся на такте
    cout << "Добро пожаловать в приложение по симуляции кластера, \nвведите количество процессоров кластера: ";
	cin >> processor_num;
	cout << "\n Введите порог появления программы: ";
	cin >> threshold;
	cout << "\n Введите максимальное количество программ, которое может появиться на такте: ";
	cin >> R;
	Cluster al(processor_num, threshold, R);
	cout << "\nВведите максимальное число тактов работы кластера: ";
	cin >> tact_work_max;
	al.StartingСluster(tact_work_max);
	map<string, double> j;
	j = al.get_result();
	cout << "\nВсего появившихся программ было: " << j["Np"];
	cout << "\nЧисло выполненных программ: " << j["Nex"];
	cout << "\nЧисло запущенных программ: " << j["Nrun"];
	cout << "\nСредняя загруженность процессора: " << j["Loudar"];
}
