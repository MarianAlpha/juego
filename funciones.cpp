#include "funciones.h"
#include <time.h>
#include <ctime>

void delay(int secs) {
for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}
