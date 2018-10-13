// #include <sys/types.h>
// #include <sys/sysctl.h>
// #include <stdio.h>

// #define BUFFERLEN 128

// int main(){
//     char buffer[BUFFERLEN];
// 	long i = 0;
//     size_t a = 8;
//     size_t bufferlen = BUFFERLEN;
//     sysctlbyname("machdep.cpu.brand_string",&buffer,&bufferlen,NULL,0);
//     sysctlbyname("vm.swapusage",&i,&a,NULL,0);
//     printf("%s\n", buffer);
//     printf("%ld\n", i);
// }




// #include <stdio.h>
// #include <stdint.h>
// #include <sys/types.h>
// #include <sys/sysctl.h>

// int main(void)
// {
//     int mib[2] = { CTL_HW, HW_MEMSIZE };
//     u_int namelen = sizeof(mib) / sizeof(mib[0]);
//     uint64_t size;
//     size_t len = sizeof(size);

//     if (sysctl(mib, namelen, &size, &len, NULL, 0) < 0)
//     {
//         perror("sysctl");
//     }
//     else
//     {
//         printf("HW.HW_MEMSIZE = %llu bytes\n", size);
//     }
//     return 0;
// }


// #include <mach/vm_statistics.h>
// #include <mach/mach_types.h>
// #include <mach/mach_init.h>
// #include <mach/mach_host.h>
// #include <stdio.h>

// int main(int argc, const char * argv[]) {
//     vm_size_t page_size;
//     mach_port_t mach_port;
//     mach_msg_type_number_t count;
//     vm_statistics64_data_t vm_stats;

//     mach_port = mach_host_self();
//     count = sizeof(vm_stats) / sizeof(natural_t);
//     if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
//         KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
//                                         (host_info64_t)&vm_stats, &count))
//     {
//         long long free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;

//         long long used_memory = ((int64_t)vm_stats.active_count +
//                                  (int64_t)vm_stats.inactive_count +
//                                  (int64_t)vm_stats.wire_count) *  (int64_t)page_size;
//         printf("free memory: %lld\nused memory: %lld\n", free_memory, used_memory);
//     }

//     return 0;
// }





// #include <iostream>
// #include <mach/mach_init.h>
// #include <mach/mach_error.h>
// #include <mach/mach_host.h>
// #include <mach/vm_map.h>

// static unsigned long long _previousTotalTicks = 0;
// static unsigned long long _previousIdleTicks = 0;

// float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
// {
//   unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
//   unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;
//   float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
//   _previousTotalTicks = totalTicks;
//   _previousIdleTicks  = idleTicks;
//   return ret;
// }
// // Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
// // You'll need to call this at regular intervals, since it measures the load between
// // the previous call and the current one.
// float GetCPULoad()
// {
//    host_cpu_load_info_data_t cpuinfo;
//    mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
//    if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
//    {
//       unsigned long long totalTicks = 0;
//       for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
//       return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
//    }
//    else return -1.0f;
// }


// int main(void)
// {
//     std::cout << "CPULouad: " << GetCPULoad() << std::endl;
// }




// #include <stdio.h>
// #include <stdlib.h>
// #include <errno.h>
// #include <err.h>
// #include <sys/stat.h>
// #include <sys/types.h>


// int main( int argc, char *argv[] ){
//     struct stat statbuf;
//     long  freemem;
//     stat( "/proc", &statbuf );
//     freemem = statbuf.st_size;
//     printf( "Free memory: %ld bytes\n", freemem );
//     printf( "Free memory: %ld KB\n", freemem / 1024 );
//     printf( "Free memory: %ld MB\n", freemem / ( 1024 * 1024 ) );
//     return 0;
// } 







// int main(void)
// {
//     struct loadavg load;

//     size_t bufferlen = sizeof(loadavg);
//     sysctlbyname("vm.loadavg",&load,&bufferlen,NULL,0);
//     printf("%u %u %u %ld\n", load.ldavg[0], load.ldavg[1], load.ldavg[2], load.fscale);

// }




// #include <sys/types.h>
// #include <sys/sysctl.h>
// #include <stdio.h>

// int main(){

//     size_t bufferlen = 128;

//     bufferlen = 512;
//     char buffer2[bufferlen];
//     sysctlbyname("kern.version",&buffer2,&bufferlen,NULL,0);
//     printf("%s\n", buffer2);
    

//     char buffer3[bufferlen];
//     sysctlbyname("kern.hostname",&buffer3,&bufferlen,NULL,0);
//     printf("%s\n", buffer3);

// }
