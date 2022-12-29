FROM debian:buster

RUN     apt-get update && apt-get upgrade
RUN	apt-get install -y apache2 

#COPY	./conf/index.html /etc/nginx/conf.d/nginx.conf
WORKDIR /etc/apache2
RUN sed -i "s|80|8081|g" ports.conf
RUN sed -i "s|80|8081|g" sites-enabled/000-default.conf
RUN sed -i "s|#ServerName www.example.com|ServerName migarcia.42.fr|g" sites-enabled/000-default.conf
COPY conf/index.html /var/www/html/

EXPOSE 8081

CMD ["apachectl", "-D", "FOREGROUND"]
