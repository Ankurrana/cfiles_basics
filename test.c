#include <stdio.h>      /* printf */
#include "math.h"       /* atan */

#define PI 3.14159265

int main ()
{
  double param, result;
  param = 0;
  result = atan (param) * 180 / PI;
  printf ("The arc tangent of %f is %f degrees\n", param, result );
  return 0;
}