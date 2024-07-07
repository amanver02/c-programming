#include <stdio.h>

// Structure to represent a process
   struct Process {
    int processId;  // Process ID
     int arrivalTime; // Arrival Time
    int burstTime;   // Burst Time
    int completionTime; // Completion Time
};

// Function to calculate turnaround time and waiting time
void calculateTimes(struct Process processes[], int n) {
    int currentTime = 0;
 
    for (int i = 0; i < n; i++) {
        // If the process has not arrived yet, wait for it to arrive
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }

        // Calculate completion time
        processes[i].completionTime = currentTime + processes[i].burstTime;

        // Update current time
        currentTime = processes[i].completionTime;
    }
}

// Function to calculate average turnaround time and waiting time
void calculateAverageTimes(struct Process processes[], int n) {
    float totalTurnaroundTime = 0, totalWaitingTime = 0;

    for (int i = 0; i < n; i++) {
        totalTurnaroundTime += (float)(processes[i].completionTime - processes[i].arrivalTime);
        totalWaitingTime += (float)(processes[i].completionTime - processes[i].arrivalTime - processes[i].burstTime);
    }

    float averageTurnaroundTime = totalTurnaroundTime / n;
    float averageWaitingTime = totalWaitingTime / n;

    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);
    printf("Average Waiting Time: %.2f\n", averageWaitingTime);
}

// Function to display the schedule
void displaySchedule(struct Process processes[], int n) {
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].processId, processes[i].arrivalTime,
               processes[i].burstTime, processes[i].completionTime);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input the processes
    for (int i = 0; i < n; i++) {
        processes[i].processId = i + 1;
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    // Sort processes based on arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
                // Swap the processes
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Calculate completion time
    calculateTimes(processes, n);

    // Display the schedule
    displaySchedule(processes, n);

    // Calculate and display average turnaround time and waiting time
    calculateAverageTimes(processes, n);

    return 0;
}
