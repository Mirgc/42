if [ ! -f "/etc/redis.kk" ]; then

	sed -i "s|bind 127.0.0.1|#bind 127.0.0.1|g" /etc/redis/redis.conf
	sed -i "s|# maxmemory <bytes>|maxmemory 128mb|g" /etc/redis/redis.conf

        touch /etc/redis.kk
fi

redis-server --protected-mode no

