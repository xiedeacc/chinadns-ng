#define _GNU_SOURCE
#include "logutils.h"
#include "netutils.h"
#include "dnsutils.h"
#include "maputils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#undef _GNU_SOURCE

#define CHINADNS_VERSION "chinadns-ng v1.0.0"

#define DEFAULT_SETNAME4 "chnroute"
#define DEFAULT_SETNAME6 "chnroute6"

#define UPSTREAM_MAXCOUNT 4
#define SOCKBUFF_MAXSIZE 1024

#define BINDSOCK_INDEX -1
#define CHINADNS_INDEX1 0
#define CHINADNS_INDEX2 1
#define TRUSTDNS_INDEX1 2
#define TRUSTDNS_INDEX2 3

#define IF_VERBOSE if (g_verbose)

static bool         g_verbose                           = false;
static const char  *g_bind_addr                         = "127.0.0.1";
static sock_port_t  g_bind_port                         = 65353;
static int          g_local_socket                      = -1;
static int          g_remote_sockets[UPSTREAM_MAXCOUNT] = {-1, -1, -1, -1};
static const char  *g_remote_names[UPSTREAM_MAXCOUNT]   = {"114.114.114.114", "", "8.8.8.8", ""};
static char         g_socket_buffer[SOCKBUFF_MAXSIZE]   = {0};
static uint16_t     g_current_message_id                = 1;
static hashmap_t   *g_message_id_hashmap                = NULL;

/* print command help information */
static void print_command_help(void) {
    printf("usage: chinadns-ng <options...>. the existing options are as follows:\n"
           " -b, --bind-addr <addr>               listen address, default: 127.0.0.1\n" 
           " -l, --bind-port <port>               listen port number, default: 65353\n"
           " -c, --china-dns <ip:port[,ip:port]>  china dns server, default: <114DNS>\n"
           " -t, --trust-dns <ip:port[,ip:port]>  trust dns server, default: <GoogleDNS>\n"
           " -4, --ipset-name4 <ipset-setname4>   ipset ipv4 set name, default: chnroute\n"
           " -6, --ipset-name6 <ipset-setname6>   ipset ipv6 set name, default: chnroute6\n"
           " -r, --reuse-port                     enable SO_REUSEPORT, default: <disabled>\n"
           " -v, --verbose                        print the verbose log, default: <disabled>\n"
           " -V, --version                        print `chinadns-ng` version number and exit\n"
           " -h, --help                           print `chinadns-ng` help information and exit\n"
           "bug report: https://github.com/zfl9/chinadns-ng. email: zfl9.com@gmail.com (Otokaze)\n"
    );
}

/* parse and check command arguments */
static void parse_command_args(int argc, char *argv[]) {
    // TODO
}

/* handle local socket readable event */
static void handle_local_packet(void) {
    // TODO
}

/* handle remote socket readable event */
static void handle_remote_packet(int index) {
    // TODO
}

int main(int argc, char *argv[]) {
    print_command_help();
    return 0;
}
