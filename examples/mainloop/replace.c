#include "shared.h"

void replace() {
   int x = 0x12;
   for (int i=0;i<0xdeadbeaf;i++) {
       x = x * x;
   }
}
