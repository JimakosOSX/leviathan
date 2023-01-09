/* Trying to duplicate the get_info bash script with C. */


#include <unistd.h>
#include <stdio.h>      
#include <stdlib.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>
#include <stdbool.h>
#include <sys/utsname.h>  
#include <ctype.h>
#include <sys/sysinfo.h>
#include <time.h>

void printmemsize(char *str, unsigned long ramsize) {
        printf("%s %ld MB\n",str, (ramsize/1024)/1024 );
}

void get_date(void) {
    time_t t;
    time(&t);

    printf("Last update  = %s", ctime(&t));
}

int get_ram(void) {
        struct sysinfo info;
        sysinfo(&info);

        printmemsize("Total RAM    =", info.totalram);
          
   /*
        printf("current running processes: %d\n", info.procs);

        FILE * fp = NULL;
        fp = fopen("/proc/meminfo", "r");
    
        char line[500];

          while (fgets(line, sizeof(line), fp)) {
          printf("%s", line); 
          }

        fclose(fp);
    */
        return 0;
}

int get_uptime(void) {

    FILE * uptimefile;
    char uptime_chr[28];
    long uptime = 0;

    if((uptimefile = fopen("/proc/uptime", "r")) == NULL)
        perror("supt"), exit(EXIT_FAILURE);

    fgets(uptime_chr, 12, uptimefile);
    fclose(uptimefile);

    uptime = strtol(uptime_chr, NULL, 10);

    long days = uptime / (3600 * 24);
    long hours = ( uptime / 3600 ) % 24;

    printf("uptime       = %ld day(s), %ld hour(s)\n", days, hours);

    return(EXIT_SUCCESS);
}

int kernel_version(void) {

    struct utsname buffer;
    char *p;
    long ver[16];
    int i=0;

    if (uname(&buffer) != 0) {
        perror("uname");
        exit(EXIT_FAILURE);
    }

    printf("system name  = %s\n", buffer.sysname);
    printf("node name    = %s\n", buffer.nodename);
    printf("release      = %s\n", buffer.release);
    printf("version      = %s\n", buffer.version);
    printf("machine      = %s\n", buffer.machine);

#ifdef _GNU_SOURCE
    printf("domain name = %s\n", buffer.domainname);
#endif

    p = buffer.release;

    while (*p) {
        if (isdigit(*p)) {
            ver[i] = strtol(p, &p, 10);
            i++;
        } else {
            p++;
        }
    }

    // printf("Kernel %ld Major %ld Minor %ld Patch %ld\n", ver[0], ver[1], ver[2], ver[3]);

    return EXIT_SUCCESS;
}

void get_ip_addresses(bool ipv6) {

    struct ifaddrs * ifAddrStruct=NULL;
    struct ifaddrs * ifa=NULL;
    void * tmpAddrPtr=NULL;

    getifaddrs(&ifAddrStruct);

           
    for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) {
        if (!ifa->ifa_addr) {
            continue;
        }
        if (ifa->ifa_addr->sa_family == AF_INET ) { 
            // check it is IP4
            // is a valid IP4 Address
            tmpAddrPtr=&((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            char addressBuffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);

            printf("%s ", addressBuffer);
            // printf("\t%s: %s\n", ifa->ifa_name, addressBuffer); 
        } 
        else if (ifa->ifa_addr->sa_family == AF_INET6 && ipv6 == true) { 
            // check it is IP6
            // is a valid IP6 Address
            tmpAddrPtr=&((struct sockaddr_in6 *)ifa->ifa_addr)->sin6_addr;
            char addressBuffer[INET6_ADDRSTRLEN];
            inet_ntop(AF_INET6, tmpAddrPtr, addressBuffer, INET6_ADDRSTRLEN);
            printf("%s ", addressBuffer); 

            // printf("\t%s: %s\n", ifa->ifa_name, addressBuffer); 
        } 
    }
    
    printf("\n");
    if (ifAddrStruct!=NULL) freeifaddrs(ifAddrStruct);
}


void DistroName() {
    system("cat /etc/issue > /tmp/.distro");
    FILE * fp = NULL;
    fp = fopen("/tmp/.distro", "r");

    char distro[100];
    fscanf(fp, "%s", distro);
    fclose(fp);

    printf("distribution = %s\n", distro);
}

int main (int argc, const char * argv[]) {

    // date and time
    void get_date(void);
    get_date();

    // ram
    int get_ram(void);
    get_ram();

    // ip addresses
    void get_ip_addresses(bool ipv6);
    bool ipv6 = false;

    if (argc == 2)
    {
        if (strcmp(argv[1], "ipv6") == 0)
        {
            ipv6 = true;
        }

        else
        {
            printf("Argument %s unknown.\nEnter ipv6 to see the IPV6 addresses after IPV4 ones.\n", argv[1]);
            return(1);
        }
    }

    printf("IP addresses = ");
    get_ip_addresses(ipv6);

    // linux distribution
    void DistroName();
    DistroName();

    // linux kernel version
    int kernel_version(void);
    kernel_version();

    // uptime
    int get_uptime(void);
    get_uptime();
 
    return 0;
}


