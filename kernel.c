#include "globalKernelInfo.h"
#include "outputLib.h"

void init(void) {
        initiateOOC();
	unsigned char i = 5;
	unsigned int mantisColor = GREEN_ON_BLACK;
	sprint("              Mantis OS (beta)\n", &mantisColor);
	sprint("_________________________________________________\n", &mantisColor);
	sprint(&i, NULL);
}
