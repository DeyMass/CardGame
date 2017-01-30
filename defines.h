#ifndef DEFINES_H
#define DEFINES_H

#define SERVER_ADDRESS		"192.168.0.101"
#define SERVER_PORT			1234

#define TIMEOUT_MS			3000
#define WAIT_FOR_CONNECTION	1
#define CONNECTED			0
#define DISCONNECTED		2
#define CONNECTION_SUCCESS	1
#define CONNECTION_ERROR	-1

#define READY_FOR_START		1
#define READY_FOR_CONECT	2
#define GAME_END			100

#define MESSAGE_LENGTH		40
#define FIRST_MESSAGE		"HI, SERVER! MY CODE #742654"

#define DECK_SIZE			36
#define START_HAND			4

//			0			1		2	3
enum Suit {Piki = 0, Kresti, Chervi, Bubi};
enum Value {_2 = 0, _3, _4, _5, _6, _7, _8, _9, _10, J, Q, K, A};
//			0		1	2	3	4	5	6	7	8	9	10	11	12
#endif // DEFINES_H
