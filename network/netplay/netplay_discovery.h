/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2016-2017 - Gregor Richards
 *
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __RARCH_NETPLAY_DISCOVERY_H
#define __RARCH_NETPLAY_DISCOVERY_H

#include <net/net_compat.h>
#include <net/net_ifinfo.h>
#include <retro_miscellaneous.h>

#define NETPLAY_HOST_STR_LEN 32
#define NETPLAY_HOST_LONGSTR_LEN 256

struct netplay_host
{
   struct sockaddr addr;
   socklen_t addrlen;
   int  content_crc;
   int  port;
   char address[NETPLAY_HOST_STR_LEN];
   char nick[NETPLAY_HOST_STR_LEN];
   char frontend[NETPLAY_HOST_STR_LEN];
   char core[NETPLAY_HOST_STR_LEN];
   char core_version[NETPLAY_HOST_STR_LEN];
   char retroarch_version[NETPLAY_HOST_STR_LEN];
   char content[NETPLAY_HOST_LONGSTR_LEN];
   char subsystem_name[NETPLAY_HOST_LONGSTR_LEN];
};

struct netplay_host_list
{
   struct netplay_host *hosts;
   size_t size;
};

/* Keep these in order, they coincide with a server-side enum and must match. */
enum netplay_host_method
{
   NETPLAY_HOST_METHOD_UNKNOWN = 0,
   NETPLAY_HOST_METHOD_MANUAL,
   NETPLAY_HOST_METHOD_UPNP,
   NETPLAY_HOST_METHOD_MITM
};

#ifdef HAVE_NETPLAYDISCOVERY
enum rarch_netplay_discovery_ctl_state
{
    RARCH_NETPLAY_DISCOVERY_CTL_NONE = 0,
    RARCH_NETPLAY_DISCOVERY_CTL_LAN_SEND_QUERY,
    RARCH_NETPLAY_DISCOVERY_CTL_LAN_GET_RESPONSES,
    RARCH_NETPLAY_DISCOVERY_CTL_LAN_CLEAR_RESPONSES
};

/** Initialize Netplay discovery */
bool init_netplay_discovery(void);

/** Deinitialize and free Netplay discovery */
void deinit_netplay_discovery(void);

/** Discovery control */
bool netplay_discovery_driver_ctl(enum rarch_netplay_discovery_ctl_state state, void *data);
#endif

#endif
