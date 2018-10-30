#pragma once
//===========================================================================
//	File Name	: ETHERNET_SETTING.h
//	Description : Plus-E Protocol Implementation for Linux Sockets
//===========================================================================

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

//connected boards limit
#define MAX_BD_CNT		3

//communication flags
#define SOCKET_ERROR -1

int   		        _socket[MAX_BD_CNT];
struct sockaddr_in	_server[MAX_BD_CNT];
struct sockaddr_in	_sender[MAX_BD_CNT];
int			        _sender_size = sizeof(struct sockaddr_in);

#define close_socket(bdid)		        close(_socket[bdid])		

#define send_tcp(bdid, buffer, length)  (send() != SOCKET_ERROR)
#define send_udp(bdid, buffer, length)  (sendto(_socket[bdid], buffer, (length), 0,( struct sockaddr * ) &_server[bdid], sizeof(_server[bdid]) ) != SOCKET_ERROR) 

#define recv_tcp(bdid, buffer, length)  recv()	
#define recv_udp(bdid, buffer, length)	recvfrom( _socket[bdid], buffer, (length), 0,( struct sockaddr * ) &_sender[bdid], &_sender_size )	
