#include <stdio.h>
#include <math.h>

// Definir una constante para el valor de pi
#define PI 3.14159265

// Definir una estructura para almacenar las coordenadas polares
typedef struct {
  double r; // radio
  double theta; // ángulo en grados
} polar;

// Definir una estructura para almacenar las coordenadas rectangulares
typedef struct {
  double x; // coordenada x
  double y; // coordenada y
} rectangular;

// Definir una función para convertir de grados a radianes
double to_radians(double degrees) {
  return degrees * PI / 180.0;
}

// Definir una función para convertir de coordenadas polares a rectangulares
rectangular polar_to_rectangular(polar p) {
  rectangular r;
  // Aplicar las fórmulas de conversión
  r.x = p.r * cos(to_radians(p.theta));
  r.y = p.r * sin(to_radians(p.theta));
  return r;
}

// Definir una función para mostrar las coordenadas rectangulares
void print_rectangular(rectangular r) {
  printf("(x, y) = (%.2f, %.2f)\n", r.x, r.y);
}

// Programa principal
int main() {
  // Crear una variable de tipo polar
  polar p;
  // Asignar los valores dados de r y theta
  p.r = 5;
  p.theta = 60;
  // Convertir de coordenadas polares a rectangulares
  rectangular r = polar_to_rectangular(p);
  // Mostrar el resultado
  print_rectangular(r);
  return 0;
}
