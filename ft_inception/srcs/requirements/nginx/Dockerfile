FROM debian:buster

RUN     apt-get update && apt-get upgrade
RUN	apt-get install -y nginx openssl

RUN	mkdir -p /etc/ssl/nginx
RUN	openssl req -x509 -nodes -days 365 \
	-subj "/C=ES/ST=Bizkaia/L=Urduliz/O=42/CN=migarcia.42.fr" \
	-newkey rsa:2048 -keyout /etc/ssl/nginx/migarcia.key -out /etc/ssl/nginx/migarcia.crt

RUN	rm -f /etc/nginx/sites-available/default.conf /etc/nginx/sites-enabled/default
COPY	./conf/default.conf /etc/nginx/conf.d/nginx.conf


EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
