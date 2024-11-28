#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>

using namespace std;


struct programm
{
	string ID;
	size_t num; //номер такта появления программы
	double p; //число требуемых процессоров
	size_t tn; //число тактов работы программы
};

template<typename T>
class TQueue
{
	size_t sz;
	std::stack<T> leftStack;
	std::stack<T> rightStack;

public:
	TQueue() : sz(0) { }
	size_t get_size() const { return sz; }
	bool IsEmpty() const { return sz == 0; }
	void Push(const T& val)
	{
		leftStack.push(val);
		sz++;
	}
	T Top()
	{
		if (rightStack.empty())
			while (!leftStack.empty())
			{
				rightStack.push(leftStack.top());
				leftStack.pop();
			}
		T val = rightStack.top();
		return val;
	}
	void Pop()
	{
		if (rightStack.empty())
			while (!leftStack.empty())
			{
				rightStack.push(leftStack.top());
				leftStack.pop();
			}
		rightStack.pop();
		sz--;
	}
};

class Cluster
{
	int processor_num; // количество процессоров в кластере
	int tact_work_max; // максимальное количество тактов работы кластера
	double threshold; //порог появления программы
	int R; // количество программ, появляюшихся на такте
	size_t Np = 0; // общее число программ 
	size_t Nex = 0; // число выполненных программ
	size_t Nrun = 0; // число запущенных программ
	double Loudar = 0; // средняя загруженность кластера
	vector<programm> not_missed_prog; // незапущенные программы
	vector<programm> missed_prog; //запущенные программы
	TQueue<programm> queue_programm; // очередь программ на запуск

public:
	Cluster(int pr, double th, vector<programm> n_m_p, int R_)
	{
		if (pr >= 16 && pr <= 64)
			processor_num = pr;
		else
			throw "impossible number of processors";
		if (th > 0 && th <= 1)
			threshold = th;
		else
			throw "impossible number of threshold for the appearance of the program";
		if (R_ > 0)
			R = R_;
		else
			throw "the number of possible programs to appear is incorrect";
		for (int i = 0; i < n_m_p.size(); i++)
		{
			if (n_m_p[i].p <= 0 || n_m_p[i].p > processor_num)
				throw "there are programs that cannot be executed on the cluster with so many processors";
		}
		not_missed_prog = n_m_p;
	}

	void StartingСluster(int tact)
	{
		double available_proces = processor_num;
		if (tact > 0)
			tact_work_max = tact;
		else
			throw "impossible number of tact work max";
		srand(time(0));
		for (int i = 0; i < tact_work_max; i++) // i - номер такта
		{
			int j = 0;
			int k = 0;
			while (j < R - k) // рандомизированное появление программ и их добавление в очередь
			{
				if ((rand() % 1000 - 1) / 1000 <= threshold && not_missed_prog.size() != 0)
				{
					queue_programm.Push(not_missed_prog[j]);
					not_missed_prog[j].num = i;
					not_missed_prog.erase(not_missed_prog.begin() + j);
					k++;
					Np++;
				}
				else
					j++;
			}
			while (!queue_programm.IsEmpty()) //проверка программы на доступность для запуска
			{  
				if (queue_programm.Top().p <= available_proces)
				{
					available_proces -= queue_programm.Top().p;
					missed_prog.push_back(queue_programm.Top());
					queue_programm.Pop();
					Nrun++;
				}
				else
					break;
			}
			Loudar += (processor_num - available_proces);
			j = 0;
			k = missed_prog.size();
			while (j < k) // снятие с выполнения закончившихся программ
			{
				if (missed_prog[j].tn == 0)
				{
					available_proces += missed_prog[j].p;
					missed_prog.erase(missed_prog.begin() + j);
					Nex++;
					k--;
				}
				else
					j++;

			}
			for (int l = 0; l < missed_prog.size(); l++) // имитация прохождения одного такта
			{
				missed_prog[l].tn--;
			}

		}
	}

	map<string, double> get_result()
	{
		map<string, double> results{ {"Np", Np}, { "Nex", Nex}, { "Nrun", Nrun}, {"Loudar", Loudar / tact_work_max}};
		return results;
	}

};
