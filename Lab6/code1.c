#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void copyArray(int count, int* source, int* destination) {
    int i;
    for(i = 0; i < count; i++) {
        destination[i] = source[i];
    }
}

void customSort(int count, int* x, int* y, int* z) {
    int i,j;
    for(i = 0; i < count-1; i++) {
        int smallest = x[i];
        int smallestIndex = i;
        for(j = i+1; j < count; j++) {
            if(x[j] < smallest) {
                smallest = x[j];
                smallestIndex = j;
            }
        }
        x[smallestIndex] = x[i];
        x[i] = smallest;

        int temp = y[i];
        y[i] = y[smallestIndex];
        y[smallestIndex] = temp;

        temp = z[i];
        z[i] = z[smallestIndex];
        z[smallestIndex] = temp;
    }
}

void printResults(int count, int* arrivalTime, int* executionTime, int* ct, char** pl) {
    int wt[count];
    int i, avgWT = 0;
    for(i = 0; i < count; i++) {
        wt[i] = ct[i] - arrivalTime[i] - executionTime[i];
        avgWT += wt[i];
    }
    avgWT /= count;

    printf("\n\n");
    printf("Process CompletionTime WaitingTime");
    printf("\n");
    for(i = 0; i < count; i++) {
        printf("%s      %-2d             %d\n", pl[i], ct[i], wt[i]);
    }
    printf("\nAverage Waiting Time: %d\n\n", avgWT);
}

void psjf(int count, int* arrivalTime, int* executionTime) {
    int et[count];
    copyArray(count, executionTime, et);
    int ct[count];
    char* pl[] = { "P1", "P2", "P3", "P4" };
    int time = 0;

    printf("Order of execution\n");
    bool completed = false;
    int lastMinProcessIndex = -1;
    while(!completed) {
        completed = true;
        int j;
        double min = INFINITY;
        int minProcessIndex = -1;
        for(j = 0; j < count; j++) {
            if(arrivalTime[j] <= time && et[j] < min && et[j] > 0) {
                min = et[j];
                minProcessIndex = j;
            }
            if(et[j] != 0) {
                completed = false;
            }
        }
        if(minProcessIndex != -1) {
            et[minProcessIndex]--;
            if(minProcessIndex != lastMinProcessIndex) {
                printf("%d-%s-", time, pl[minProcessIndex]);
                lastMinProcessIndex = minProcessIndex;
            }
            if(et[minProcessIndex] == 0) {
                ct[minProcessIndex] = time+1;
                printf("%d ", ct[minProcessIndex]);
            }
        }
        time++;
    }

    printResults(count, arrivalTime, executionTime, ct, pl);
}

void rr(int count, int* arrivalTime, int* executionTime, int timeQuantum) {
    int at[count], et[count];
    copyArray(count, arrivalTime, at);
    copyArray(count, executionTime, et);
    int pln[] = { 1, 2, 3, 4 };
    char* pl[] = { "P1", "P2", "P3", "P4" };
    customSort(count, at, et, pln);
    int completed = 0;
    int time = 0;
    int i = 0;
    int lastProcess = -1;
    int ct[count];
    while(completed != count) {
        if(at[i] <= time && et[i] != 0) {
            int rt = (et[i] < timeQuantum) ? et[i] : timeQuantum;
            et[i] -= rt;
            at[i] += rt;
            printf("%d-P%d-", time, pln[i]);
            time += rt;
            if(et[i] == 0) {
                completed++;
                ct[pln[i]-1] = time;
            }
            printf("%d ", time);
            lastProcess = i;
        }
        if(i == lastProcess && et[i] == 0) {
            time++;
        }
        i = (i + 1) % count;
    }
    printResults(count, arrivalTime, executionTime, ct, pl);
}

void npp(int count, int* arrivalTime, int* executionTime, int* priority) {
    int ct[count];
    int completed = 0;
    int time = 0;
    char* pl[] = { "P1", "P2", "P3", "P4" };
    bool processCompleted[] = { false, false, false, false };

    printf("Order of execution\n");
    while(completed != count) {
        int max = 0, maxPriorityIndex = -1;
        int j;
        for(j = 0; j < count; j++) {
            if(arrivalTime[j] <= time && priority[j] > max && !processCompleted[j]) {
                max = priority[j];
                maxPriorityIndex = j;
            }
        }

        if(maxPriorityIndex != -1) {
            completed++;
            printf("%d-%s-", time, pl[maxPriorityIndex]);
            time += executionTime[maxPriorityIndex];
            ct[maxPriorityIndex] = time;
            printf("%d ", time);
            processCompleted[maxPriorityIndex] = true;
        } else {
            time++;
        }
    }

    printResults(count, arrivalTime, executionTime, ct, pl);
}

int main() {
    const int count = 4;
    int arrivalTime[] = { 0, 5, 3, 7 };
    int executionTime[] = { 8, 4, 9, 16 };
    int priority[] = { 1, 2, 2, 3 };
    int timeQuantum = 3;
    while(1) {
        int i;
        printf("1.Preemptive SJF\n2.RR\n3.Non-preemptive Priority\n4.Exit\n");
        scanf("%d", &i);
        switch(i) {
            case 1:
                psjf(count, arrivalTime, executionTime);
                break;
            case 2:
                rr(count, arrivalTime, executionTime, timeQuantum);
                break;
            case 3:
                npp(count, arrivalTime, executionTime, priority);
                break;
            case 4:
                exit(0);
        }
    }
}
