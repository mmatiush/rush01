#include <sys/types.h>
#include <sys/sysctl.h>
#include <iostream>

// #define BUFFERLEN 128

// int main(){
//     char buffer[BUFFERLEN];
//     size_t bufferlen = BUFFERLEN;
//     std::cout << "ProductName: Mac OS X" << std::endl;
// 	// build Version
//     sysctlbyname("kern.osversion",&buffer,&bufferlen,NULL,0);
//     std::cout << "BuildVersion: " << buffer << std::endl;
// 	// product version
//     sysctlbyname("kern.osrelease",&buffer,&bufferlen,NULL,0);
//     std::cout  << "ProductVersion: " << buffer << std::endl;
// }

// output:
// ProductName:	Mac OS X
// ProductVersion:	10.13.3
// BuildVersion:	17D102


// include <sys/types.h>
// include <sys/sysctl.h>
#include <stdio.h>
int main(){

// size_t bufferlen = 128;

size_t bufferlen = 512;
char buffer2[bufferlen];
sysctlbyname("kern.version",&buffer2,&bufferlen,NULL,0);
printf("%s\n", buffer2);


// char buffer3[bufferlen];
// sysctlbyname("kern.hostname",&buffer3,&bufferlen,NULL,0);
// printf("%s\n", buffer3);
}