#ifndef RAPIDHTTP_INTERFACE_HPP
#define RAPIDHTTP_INTERFACE_HPP

#include <cstdint>

struct rapidhttp_loop;
struct rapidhttp_server;
struct rapidhttp_request;

struct rapidhttp_loop *rapidhttp_loop_new();
void rapidhttp_loop_free(struct rapidhttp_loop *loop);
void rapidhttp_loop_run(struct rapidhttp_loop *loop);
void rapidhttp_loop_quit(struct rapidhttp_loop *loop);

struct rapidhttp_server *rapidhttp_server_new(struct rapidhttp_loop *loop, const char * host, uint16_t port);
void rapidhttp_server_free(struct rapidhttp_server *server);
void rapidhttp_server_listen(struct rapidhttp_server *server);
void rapidhttp_server_listen_tls(struct rapidhttp_server *server, const char * cert, const char * key);



#endif