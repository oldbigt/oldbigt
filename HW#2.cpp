
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 12
void costtime(char customer[], int cost[]);
void starttime(char customer[], int start[],int cost[], int arrive[]);
void addq(char queue[], char customer);
char deleteq(char queue[]);
void printq(char queue[]);
int front = 1;
int rear = 1;
int main()
{
	char customer[13] = { 'A','B','C','D','E','F','G','H','I','J','K','L','O' };
	int arrive[13] =    { 480,485,490,495,500,505,510,515,520,525,530,535,0 };
	int start[13];
	int cost[13];
	char queue[13];
	int time = 480;
	costtime(customer, cost);
	printf("\n");
	//starttime(cost, start, arrive, customer);
	starttime(customer,start,cost, arrive );
	printf("\n");
	printf("TIME	S	QUEUE\n");
	printf("-------------------\n");
	int i = 0;
	int j = 0;
	char sline;
	while (time < start[11] + cost[11]) {
		printf("%d:%02d:%02d:%02d:%02d:%02d ", time / 60, time % 60,i,j,time, start[11] + cost[11]);
		
		if (time == arrive[i]) {
			addq(queue, customer[i]);
			i++;
		}
		if (time == start[j]) {
			sline = deleteq(queue);
			j++;
		}
		if (time < arrive[j - 1] + cost[j - 1]) {
			printf("%c	", sline);
		}
		else
			printf(" ");
		printq(queue);
		printf("\n");
		time++;
	}
	printf("\nEND\n");
	exit;
}
void costtime(char customer[], int cost[]) {
	srand(time(NULL));
	for (int i = 0; i < 12; i++) {
		cost[i] = rand() % 9 + 4;
		printf("%c %d minute", customer[i], cost[i]);
		printf("\n");
	}
	return;
}
void starttime(char customer[], int start[], int cost[], int arrive[]) {
	start[0] = 480;
	for (int i = 1; i <= 12; i++) {
		if (start[i - 1] + cost[i - 1] < arrive[i]) {
			start[i] = arrive[i];
		}
		else {
			start[i] = start[i - 1] + cost[i - 1];
		}
		printf("%cstarttime is %d:%02d", customer[i - 1], start[i - 1] / 60, start[i - 1] % 60);
		printf("\n");
	}
}
void addq(char queue[], char customer) {
	rear = (rear + 1) % MAX_SIZE;
	if (front == rear)
		printf("CIRCULATE QUEUE is full");
	else
		queue[rear] = customer;


}
char deleteq(char queue[]) {
	if (front == rear) {
		printf("CIRCULATE QUEUE is empty");
		return -1;
	}
	else
	{
		front = (front + 1) % MAX_SIZE;
		return queue[front];
	}
	
}
void printq(char queue[]) {
	int i = front;
	while (i != rear) {
		i = (i + 1) % MAX_SIZE;
		printf("%c", queue[i]);
	}
}
