/* NTRIP Client
@Parameters: <server_ip>,
             <server_port>,
             <mountpoint>: value from mountpoint table,
             <user>: username registrered on NTRIP service,
             <passwd>: user's password,
             <gpg_message>: GPGGA or GNGGA received from GPS
@Returns: A string of  RTCM */

#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

#include "ntrip_util.h"


std::string ntrip_socket(std::string server_ip, int server_port, std::string mountpoint, std::string user, std::string passwd, std::string gpg_message) {
  int ret;
  int m_sock;
  time_t start, stop;
  char recv_buf[1024] = {0};
  char request_data[1024] = {0};
  char userinfo_raw[48] = {0};
  char userinfo[64] = {0};

  // char server_ip[] = ;
  // int server_port = 2101;
  // // If mount point is NULL, request source table.
  // // char mountpoint[] = "";
  // char mountpoint[] = "iMAX-GGB";
  // char user[] = "4269573848";
  // char passwd[] = "09126072091";
  // char gpgga[] = "$GNGGA,102522.00,3543.9422019,N,05123.3815335,E,1,07,1.2,1333.394,M,2.476,M,,*70";

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(struct sockaddr_in));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(server_port);
  server_addr.sin_addr.s_addr = inet_addr(server_ip.c_str());

  // Generate base64 encoding of username and password.
  snprintf(userinfo_raw, 63 , "%s:%s", user.c_str(), passwd.c_str());
  Base64Encode(userinfo_raw, userinfo);

   // Generate request data format of ntrip.
  snprintf(request_data, 1023,
           "GET /%s HTTP/1.1\r\n"
           "User-Agent: %s\r\n"
           "Accept: */*\r\n"
           "Connection: close\r\n"
           "Authorization: Basic %s\r\n"
           "\r\n",
           mountpoint.c_str(), kClientAgent, userinfo);

  m_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (m_sock == -1) {
    printf("create socket fail\n");
    exit(1);
  }

  // Connect to caster.
  if (connect(m_sock, reinterpret_cast<struct sockaddr *>(&server_addr),
              sizeof(struct sockaddr_in)) < 0) {
    printf("connect caster failed!!!\n");
    exit(1);
  }

  int flags = fcntl(m_sock, F_GETFL);
  fcntl(m_sock, F_SETFL, flags | O_NONBLOCK);

  // Send request data.
  if (send(m_sock, request_data, strlen(request_data), 0) < 0) {
    printf("send request failed!!!\n");
    exit(1);
  }

  // Wait for request to connect caster success.
  while (1) {
    ret = recv(m_sock, (void *)recv_buf, sizeof(recv_buf), 0);
    if ((ret > 0) && !strncmp(recv_buf, "ICY 200 OK\r\n", 12)) {
      ret = send(m_sock, gpg_message.c_str(), strlen(gpg_message.c_str()), 0);
      if (ret < 0) {
        printf("send gpgga data fail\n");
        exit(1);
      }
      printf("send gpgga data ok\n");
      break;
    } else if (ret == 0) {
      printf("remote socket close!!!\n");
    } else {
      printf("%s\n", recv_buf);
    }
  }

  // Receive data that returned by caster.
  start = time(NULL);
  std::string response = "";
  int j = 1;
  while ( j < 5) {
    ret = recv(m_sock, recv_buf, sizeof(recv_buf), 0);
    if (ret > 0) {
      stop = time(NULL);
      printf("recv data:[%d] used time:[%d]\n", ret, (int)(stop - start));
      for(int i = 0; i < sizeof(recv_buf);i++){
        response = response + recv_buf[i];
      }
      j = j+1;
      start = time(NULL);
    } else if (ret == 0) {
      printf("remote socket close!!!\n");
      return response;
    }
  }
}

