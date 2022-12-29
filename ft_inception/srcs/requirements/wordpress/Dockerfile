FROM debian:buster

WORKDIR /var/www/html

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y curl php7.3-fpm php7.3-mysql

COPY ./conf/php.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY ./conf/wp-config.php /var/www/html

#STATIC WEBSITE
COPY ./conf/index.html /var/www

RUN mkdir -p /run/php/ && touch /run/php/php7.3-fpm.pid

COPY tools/wordpress_startup.sh ./
CMD chmod -x wordpress_startup.sh

EXPOSE 9000

CMD sh ./wordpress_startup.sh
