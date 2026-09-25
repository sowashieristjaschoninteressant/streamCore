#pragma once 
#include <stdio.h>

#define info(fmt,...) printf("[=] " fmt "\n", ##__VA_ARGS__) 
#define warn(fmt,...) printf("[-] " fmt "\n", ##__VA_ARGS__)
#define okay(fmt,...) printf("[+] " fmt "\n", ##__VA_ARGS__)