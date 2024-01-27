#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926536
//x rad * 180/PI =57.29577951308
//x grad *Pi/180=0.01745329252

int main() {
  float x,seno,coseno,tangente,rad;
  printf ("Ingresa un angulo en grados :");
  scanf ("%f", &x);
  rad=x*PI/180;
  seno=sin(rad);
  coseno=cos(rad);
  tangente=tan(rad);
  printf("el seno = %.4f \n",seno);
  printf("el coseno = %.4f \n",coseno);
  printf("la tangente = %.4f \n",tangente);

return 0;
}
