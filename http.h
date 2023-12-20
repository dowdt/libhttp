#ifndef _http_h_
#define _http_h_

#include "../net.c"

struct http_message {
	struct {
		int code;
		int length;
	} header;
	char *content;
	int length;
	struct {
		int in_content;
		int chunk;
		char buf[4096];
		int size;
		char *offset;
		char *last;
		int free;
		int left;
		int total;
	} state;
};

/* low level methods */
struct http_url {
	char *protocol;
	char *host;
	char *query;
};

struct http_url *http_parse_url(const char *);
int http_send(Socket* sock, const char *);
int http_read(Socket* sock, struct http_message *);

/* high level methods */
Socket* http_request(const char *);
int http_response(Socket*, struct http_message *);

#endif
