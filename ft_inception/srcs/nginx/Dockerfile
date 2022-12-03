FROM debian:bullseye-slim

RUN     apt-get update && apt-get upgrade
RUN	apt-get install -y nginx openssl

RUN	mkdir -p /etc/ssl/nginx
RUN	openssl req -x509 -nodes -days 365 -subj "CN=migarcia.42.fr" -addext "subjectAltName=DNS:migarcia.42.fr" -newkey rsa:2048 -keyout /etc/ssl/nginx/migarcia.key -out /etc/ssl/nignx/migarcia.crt;
RUN	rm -f /etc/nginx/conf.d/default.conf
COPY	conf/nginx.conf /etc/nginx/conf.d/nginx.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
