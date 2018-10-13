#include <sys/types.h>
#include <sys/sysctl.h>
#include <iostream>

#define BUFFERLEN 128
#define FIXPT_BITS 10
#define fixpt_fval(val) (static_cast<float>(val) / (1 << FIXPT_BITS))

int main(){
    char buffer[BUFFERLEN];
    size_t bufferlen = BUFFERLEN;
	// Intel(R) Core(TM) i5-7500 CPU @ 3.40GHz
    sysctlbyname("machdep.cpu.brand_string",&buffer,&bufferlen,NULL,0);
    std::cout << buffer << std::endl;

	struct loadavg load;
	size_t t = sizeof(loadavg);
    sysctlbyname("vm.loadavg",&load,&t,NULL,0);
    std::cout << (fixpt_fval(load.ldavg[0])) << std::endl;
    std::cout << (fixpt_fval(load.ldavg[1])) << std::endl;
    std::cout << (fixpt_fval(load.ldavg[2])) << std::endl;

}

