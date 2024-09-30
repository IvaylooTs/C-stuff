#include <stdio.h>
#include <stdlib.h>
#define VEHICLES_COUNT 4
typedef struct {
        char brand[20];
        char model[20];
        int year;
   } Features;

typedef struct {
    Features *vehicles;
} Vehicles;

int main()
{
   Vehicles garage;
   garage.vehicles = malloc(sizeof(Features) * VEHICLES_COUNT);

   for (int i=0; i<)

   free(garage.vehicles);

   return 0;
}
