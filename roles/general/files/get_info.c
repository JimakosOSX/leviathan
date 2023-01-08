#include <stdio.h>      
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>
#include <stdbool.h>
#include <sys/utsname.h>  


/* Trying to duplicate this into an ASCII result we can get
 * clusters.gr
 * os           Ubuntu 22.04.1 LTS
 * host         Droplet 20171212
 * kernel       5.15.0-56-generic
 * uptime       16d 19h 6m
 * pkgs         891
 * memory       747M / 969M
 * update       08/01/2023 15:47
 * root_percent 39%
 * mailbox      xxx MB
 * IPs          127.0.0.1 174.138.10.122 10.18.0.5 10.110.0.2 172.22.206.75
 */


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
            printf("%s: %s\n", ifa->ifa_name, addressBuffer); 
        } 
        else if (ifa->ifa_addr->sa_family == AF_INET6 && ipv6 == true) { 
            // check it is IP6
            // is a valid IP6 Address
            tmpAddrPtr=&((struct sockaddr_in6 *)ifa->ifa_addr)->sin6_addr;
            char addressBuffer[INET6_ADDRSTRLEN];
            inet_ntop(AF_INET6, tmpAddrPtr, addressBuffer, INET6_ADDRSTRLEN);
            printf("%s: %s\n", ifa->ifa_name, addressBuffer); 
        } 
    }

    if (ifAddrStruct!=NULL) freeifaddrs(ifAddrStruct);
}


// Returns hostname for the local computer
void checkHostName(int hostname)
{
    if (hostname == -1)
    {
    perror("gethostname");
    exit(1);
    }
}

// Returns host information corresponding to host name
void checkHostEntry(struct hostent * hostentry)
{
    if (hostentry == NULL)
    {
        perror("gethostbyname");
        exit(1);
    }
}

void DistroName()
{
    system("cat /etc/issue > /tmp/.distro");
    FILE * fp = NULL;
    fp = fopen("/tmp/.distro", "r");

    char distro[100];
    fscanf(fp, "%s", distro);

    printf("Distribution: %s\n", distro);
}

int main (int argc, const char * argv[]) {
    
    // hostname 
    void checkHostName(int);
    void checkHostEntry(struct hostent *);

    char hostbuffer[256];
    char *IPbuffer;
    struct hostent *host_entry;
    int hostname;
    
    // To retrieve hostname
    hostname = gethostname(hostbuffer, sizeof(hostbuffer));
    checkHostName(hostname);
    
    // To retrieve host information
    host_entry = gethostbyname(hostbuffer);
    checkHostEntry(host_entry);
    
    printf("Hostname: %s\n", hostbuffer);
    
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

    printf("\nIP addresses\n\n");
    get_ip_addresses(ipv6);


    // linux distribution
    void DistroName();

    printf("\n");
    DistroName();
    printf("\n");

    return 0;
}


