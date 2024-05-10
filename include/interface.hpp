#ifndef RAPIDHTTP_INTERFACE_HPP
#define RAPIDHTTP_INTERFACE_HPP

#include <cstdint>
#include <memory>

struct rapidhttp_loop;
struct rapidhttp_server;
struct rapidhttp_request;
struct rapidhttp_response;
struct rapidhttp_response_writer;

typedef void (*rapidhttp_handle_func)(struct rapidhttp_response_writer *, struct rapidhttp_request *, void *);

struct rapidhttp_loop *rapidhttp_loop_new();
void rapidhttp_loop_free(struct rapidhttp_loop *loop);
void rapidhttp_loop_run(struct rapidhttp_loop *loop);
void rapidhttp_loop_quit(struct rapidhttp_loop *loop);

struct rapidhttp_server *rapidhttp_server_new(struct rapidhttp_loop *loop, const char *host, uint16_t port);
void rapidhttp_server_free(struct rapidhttp_server *server);
void rapidhttp_server_listen(struct rapidhttp_server *server);
void rapidhttp_server_listen_tls(struct rapidhttp_server *server, const char *cert, const char *key);
void rapidhttp_server_handle(struct rapidhttp_server *server, rapidhttp_handle_func handle_func, void *user_data);

struct rapidhttp_request *rapidhttp_request_new();
struct rapidhttp_request *rapidhttp_request_free();

template<class Type>
class type
{
protected:
    std::shared_ptr<Type> _value;
};

#ifdef RAPIDHTTP_EXPOSE_INTERFACE

#include <event2/http.h>
struct rapidhttp_loop
{
    struct event_base *base;
};
struct rapidhttp_server
{
    struct evhttp *http;
    char *host;
    uint16_t port;
    rapidhttp_handle_func *handler_func;
    void *user_data;
};
struct rapidhttp_request
{

};

template<class Type>
class accessor : public type<Type>
{
public:
    std::shared_ptr<Type>& get()
    {
        return _value;
    }
};

#endif

#endif