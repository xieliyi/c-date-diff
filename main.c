/*
 * main.c
 *
 * $Revision: 1.00   $
 * $Author: xieliyi  $
 * $Date: 2018/05/26 $
 *
 */

#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include "date_diff.h"

int main(int argc, char **argv)
{
  int d;
  int y1=1,   m1=1, d1=1;
  int y2=2018,m2=5, d2=25;
  
  
  if(argc > 6)
  {
	  y1 = atoi(argv[1]);
	  m1 = atoi(argv[2]);
	  d1 = atoi(argv[3]);

	  y2 = atoi(argv[4]);
	  m2 = atoi(argv[5]);
	  d2 = atoi(argv[6]);
  }
  else if(argc > 3)
  {
	  y2 = atoi(argv[1]);
	  m2 = atoi(argv[2]);
	  d2 = atoi(argv[3]);
  }
  
  d = date_diff(y1,m1,d1,y2,m2,d2);

  printf("%04d/%02d/%02d-%04d/%02d/%02d=%d days!",y2,m2,d2,y1,m1,d1,d);

  return d;
}

