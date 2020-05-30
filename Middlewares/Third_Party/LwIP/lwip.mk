LWIP_INC = -I$(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/include
LWIP_INC+= -I$(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/system

LWIP_SRC = $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/api/api_lib.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/api/api_msg.c\
           $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/api/err.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/api/netbuf.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/api/netdb.c\
           $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/api/netifapi.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/api/sockets.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/api/tcpip.c\
           $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/ipv4/autoip.c\
           $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/ipv4/dhcp.c\
           $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/ipv4/etharp.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/ipv4/icmp.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/ipv4/igmp.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/ipv4/ip4_addr.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/ipv4/ip4_frag.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/ipv4/ip4.c\
           $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/def.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/dns.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/inet_chksum.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/init.c\
           $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/ip.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/mem.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/memp.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/netif.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/pbuf.c\
           $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/raw.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/stats.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/sys.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/tcp.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/tcp_in.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/tcp_out.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/timeouts.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/core/udp.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/netif/ethernet.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/apps/mqtt/mqtt.c\
		   $(STM32_SDK_DIR)/Middlewares/Third_Party/LwIP/src/apps/tftp/tftp_server.c
