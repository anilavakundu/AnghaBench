#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_4__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ngx_uint_t ;
typedef  scalar_t__ ngx_int_t ;
struct TYPE_5__ {int active; size_t index; int /*<<< orphan*/  log; TYPE_2__* data; } ;
typedef  TYPE_1__ ngx_event_t ;
struct TYPE_6__ {int /*<<< orphan*/  fd; TYPE_1__* read; TYPE_1__* write; } ;
typedef  TYPE_2__ ngx_connection_t ;
struct TYPE_7__ {short events; scalar_t__ revents; int /*<<< orphan*/  fd; } ;

/* Variables and functions */
 size_t NGX_INVALID_INDEX ; 
 int /*<<< orphan*/  NGX_LOG_ALERT ; 
 int /*<<< orphan*/  NGX_LOG_DEBUG_EVENT ; 
 scalar_t__ NGX_OK ; 
 scalar_t__ NGX_READ_EVENT ; 
 scalar_t__ POLLIN ; 
 scalar_t__ POLLOUT ; 
 TYPE_4__* event_list ; 
 size_t nevents ; 
 int /*<<< orphan*/  ngx_log_debug1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,size_t) ; 
 int /*<<< orphan*/  ngx_log_debug2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  ngx_log_error (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static ngx_int_t
ngx_poll_add_event(ngx_event_t *ev, ngx_int_t event, ngx_uint_t flags)
{
    ngx_event_t       *e;
    ngx_connection_t  *c;

    c = ev->data;

    ev->active = 1;

    if (ev->index != NGX_INVALID_INDEX) {
        ngx_log_error(NGX_LOG_ALERT, ev->log, 0,
                      "poll event fd:%d ev:%i is already set", c->fd, event);
        return NGX_OK;
    }

    if (event == NGX_READ_EVENT) {
        e = c->write;
#if (NGX_READ_EVENT != POLLIN)
        event = POLLIN;
#endif

    } else {
        e = c->read;
#if (NGX_WRITE_EVENT != POLLOUT)
        event = POLLOUT;
#endif
    }

    ngx_log_debug2(NGX_LOG_DEBUG_EVENT, ev->log, 0,
                   "poll add event: fd:%d ev:%i", c->fd, event);

    if (e == NULL || e->index == NGX_INVALID_INDEX) {
        event_list[nevents].fd = c->fd;
        event_list[nevents].events = (short) event;
        event_list[nevents].revents = 0;

        ev->index = nevents;
        nevents++;

    } else {
        ngx_log_debug1(NGX_LOG_DEBUG_EVENT, ev->log, 0,
                       "poll add index: %i", e->index);

        event_list[e->index].events |= (short) event;
        ev->index = e->index;
    }

    return NGX_OK;
}