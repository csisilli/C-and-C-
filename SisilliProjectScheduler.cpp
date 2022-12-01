#include <iostream>
using namespace std;
struct Process

{
	int pid; // Process ID
	int bt; // Burst Time
	int art; // Arrival Time
};

void findTurnAroundTime(Process proc[], int n, int wt[], int tat[])

{
	for (int i = 0; i < n; i++)
		tat[i] = proc[i].bt + wt[i];
}
void findWaitingTime(Process proc[], int n, int wt[])
{
	int rt[n];
	for (int i = 0; i < n; i++)
		rt[i] = proc[i].bt;
	int complete = 0, t = 0, minm = INT_MAX;
	int shortest = 0, finish_time;
	bool check = false;
	while (complete != n)
	{
		for (int j = 0; j < n; j++)
		{
			if ((proc[j].art <= t) && (rt[j] < minm) && rt[j] > 0)
			{
				minm = rt[j];
				shortest = j;
				check = true;
			}
		}
		if (check == false)
		{
			t++;
			continue;
		}
		rt[shortest]--;
		minm = rt[shortest];
		if (minm == 0)
			minm = INT_MAX;
		if (rt[shortest] == 0)
		{
			complete++;
			check = false;
			finish_time = t + 1;
			wt[shortest] = finish_time -
				proc[shortest].bt -
				proc[shortest].art;
			if (wt[shortest] < 0)
				wt[shortest] = 0;
		}
		t++;
	}
}
// Function to calculate average time
void findavgTime(Process proc[], int n)
{
	int wt[n], tat[n], total_wt = 0,
		total_tat = 0;
	findWaitingTime(proc, n, wt);
	findTurnAroundTime(proc, n, wt, tat);
	cout << "Processes " << " Burst time " << " Waiting time " << " Turn around time\n";
	for (int i = 0; i < n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << proc[i].pid << "\t\t" << proc[i].bt << "\t\t " << wt[i] << "\t\t " << tat[i] << endl;
	}
	cout << "\nAverage waiting time = " << (float)total_wt / (float)n; cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}
// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
	wt[0] = 0;
	for (int i = 1; i < n; i++)
		wt[i] = bt[i - 1] + wt[i - 1];
}
// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n; i++)
		tat[i] = bt[i] + wt[i];
}
//Function to calculate average time
void findavgTime(int processes[], int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;
	//Function to find waiting time of all processes
	findWaitingTime(processes, n, bt, wt);
	//Function to find turn around time for all processes
	findTurnAroundTime(processes, n, bt, wt, tat);
	cout << "Processes " << " Burst time " << " Waiting time " << " Turn around time\n";
	for (int i = 0; i < n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i + 1 << "\t\t" << bt[i] << "\t " << wt[i] << "\t\t " << tat[i] << endl;
	}
	cout << "Average waiting time = " << (float)total_wt / (float)n;
	cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}
int main()
{
	int processes[] = { 1, 2, 3 };
	int n = sizeof processes / sizeof processes[0];
	int burst_time[] = { 10, 5, 8 };
	cout << "Result for non-preemptive FCFS:\n";
	findavgTime(processes, n, burst_time);
	cout << endl << endl;
	Process proc[] = { { 1, 10, 1 }, { 2, 5, 1 }, { 3, 8, 2 } };
	n = sizeof(proc) / sizeof(proc[0]);
	cout << "Result for preemptive SJF:\n";
	findavgTime(proc, n);
	return 0;
}