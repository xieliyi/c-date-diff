/*
 * holiday.c
 *
 * $Revision: 1.00   $
 * $Author: xieliyi  $
 * $Date: 2018/05/25 $
 *
 */
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <time.h>

int date_to_day(int y, int m, int d)
{
  int mon[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
  int day = 0;
  int i;
  
  for(i=1; i<y; i++)
  {
    day += (i%4==0 && i%100!=0 || i%400==0)? 366 : 365;
  }
  if(y%4==0 && y%100!=0 || y%400==0) mon[2]++;
  
  for(i=1; i<m; i++)
  {
      day += mon[i];
  }
  return day + d;
}

int date_diff(int y1, int m1, int d1, int y2, int m2, int d2)
{
  int a = date_to_day(y1, m1, d1);
  int b = date_to_day(y2, m2, d2);
  return b-a;
}

int main(int argc, char **argv)
{
  int y=2018,m=5,d=25;
  int ret = 0;
  if(argc > 3)
  {
	  y = atoi(argv[1]);
	  m = atoi(argv[2]);
	  d = atoi(argv[3]);
  }
  else
  {
	  time_t now;
	  struct tm *tm_now;
	  time(&now);
	  tm_now = gmtime(&now);
	  y = 1900 + tm_now->tm_year;
	  m = 1 + tm_now->tm_mon;
	  d = tm_now->tm_mday;
  }	  
  printf("%d年%d月%d日：",y,m,d);
  
  int n = date_diff(1998,9,1,y,m,d);

  int nn = n%(5+2);
  if(nn < 5)
  {
  	ret = 1;
	//上学
	printf("上学");
  }
  else
  {
  	ret = 2;
	//放假
	printf("放假");
  }
  return ret;
}

