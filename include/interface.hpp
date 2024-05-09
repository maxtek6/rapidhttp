#ifndef RAPIDHTTP_INTERFACE_HPP
#define RAPIDHTTP_INTERFACE_HPP

struct rapidhttp_loop;
struct rapidhttp_server;

struct rapidhttp_loop *rapidhttp_loop_new();
void rapidhttp_loop_free(struct rapidhttp_loop *loop);
void rapidhttp_loop_run(struct rapidhttp_loop *loop);
void rapidhttp_loop_quit(struct rapidhttp_loop *loop);

#endif