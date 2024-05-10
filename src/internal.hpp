#ifndef RAPIDHTTP_INTERNAL_HPP
#define RAPIDHTTP_INTERNAL_HPP

#include "interface.hpp"

#ifndef RAPIDHTTP_EXPOSE_INTERFACE

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
    std::shared_ptr<evhttp_request> request;
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

template<class Type>
class modifier : public type<Type>
{

};

#endif


#endif