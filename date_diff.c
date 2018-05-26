/*
 * date_diff.c
 *
 * $Revision: 1.00   $
 * $Author: xieliyi  $
 * $Date: 2018/05/26 $
 *
 */

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

