#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE* fp = NULL;
	fp = fopen("C:\\Users\\user\\Desktop\\schedule.txt", "r");
	char time1[20];
	char time_hour1[5] = {' '};
	char time_hour2[5] = {' '};
	char time_min1[5] = {' '};
	char time_min2[5] = {' '};
	int hour1, hour2, min1, min2;
	int sum = 0;
	int count = 0;
	if (fp == NULL)
	{
		printf("파일열기 실패\n");
		return 1;
	}
	while (fgets(time1, 20, fp) != NULL)
	{
	//	printf("%s\n", time1);
		time_hour1[0]= time1[0];
		time_hour1[1]=time1[1];
		time_min1[0]=time1[3];
		time_min1[1]=time1[4];
		time_hour2[0]=time1[6] ;
		time_hour2[1]=time1[7];
		time_min2[0]=time1[9];
		time_min2[1]=time1[10];
		hour1 = atoi(time_hour1);
		hour2 = atoi(time_hour2);
		min1 = atoi(time_min1);
		min2 = atoi(time_min2);
	//	printf("%d %d %d %d\n", hour1,min1,hour2,min2);
		sum += ((hour2 * 60) + min2) - ((hour1 * 60) - min1);
		count++;
	}
	printf("총 분 : %d  일한 날짜 : %d\n", sum,count);
	double sum1 = sum / 60;
	printf("총 시간 : %lf\n", sum1);
	printf("이번 달 월급 : %lf\n", sum1 * 8590);
	return 0;
}