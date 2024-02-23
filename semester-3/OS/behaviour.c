#include <stdio.h>
#include <stdlib.h>

int main() {
    // Get Linux kernel version
    system("uname -a");

    // Get CPU information
    system("lscpu");

    return 0;
}

