FROM debian:buster

ARG	DOMAIN_NAME

RUN     apt-get update && apt-get upgrade
RUN	apt-get install -y nginx openssl

RUN	mkdir -p /etc/ssl/nginx
RUN	ls -l /etc/ssl
RUN	openssl req -x509 -nodes -days 365 \
	-subj "/C=ES/ST=Bizkaia/L=Urduliz/O=42/CN=${DOMAIN_NAME}" \
	-newkey rsa:2048 -keyout /etc/ssl/nginx/migarcia.key -out /etc/ssl/nginx/migarcia.crt

RUN	rm -f /etc/nginx/sites-available/default.conf /etc/nginx/sites-enabled/default
COPY	conf/nginx.conf /etc/nginx/sites-available/nginx.conf
RUN	ln -s /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled/nginx.conf

EXPOSE 8443

CMD ["nginx", "-g", "daemon off;"]
