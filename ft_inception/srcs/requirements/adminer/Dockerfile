FROM debian:buster

RUN     apt-get update && apt-get upgrade
RUN	apt-get install -y wget nginx php7.3 php7.3-fpm php7.3-mysqli

RUN mkdir -p /run/php/ && touch /run/php/php7.3-fpm.pid

COPY ./conf/default.conf /etc/nginx/conf.d/
COPY ./conf/php.conf /etc/php/7.3/fpm/pool.d/www.conf

COPY ./tools/adminer_startup.sh ./
CMD chmod -x adminer_startup.sh

EXPOSE 8080

CMD sh ./adminer_startup.sh
