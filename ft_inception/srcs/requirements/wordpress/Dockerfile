FROM debian:buster

ARG WP_VERSION
ARG WP_SHA1
ARG DB_NAME
ARG DB_USER
ARG DB_PASSWORD
ARG DB_HOST

WORKDIR /var/www/html

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y wget php7.3-fpm php7.3-mysql

RUN wget "https://wordpress.org/wordpress-${WP_VERSION}.tar.gz"; 
        #echo "$WORDPRESS_SHA1 *wordpress.tar.gz" | sha1sum -c -; \
RUN tar -xzf wordpress-${WP_VERSION}.tar.gz -C /var/www/html/; \
        rm wordpress-${WP_VERSION}.tar.gz; \
        chown -R www-data:www-data /var/www/html; \
	mv ./wordpress/wp-config-sample.php ./wordpress/wp-config.php
RUN ls -ltr /var/www/html/wordpress

#COPY ./conf/wp-config.php /var/www/html/wordpress/wp-config.php
COPY ./conf/php.conf /etc/php/8.1/fpm/pool.d/www.conf

RUN mkdir -p /run/php/ && touch /run/php/php7.3-fpm.pid

RUN sed -i "s|database_name_here|${DB_NAME}|g" wordpress/wp-config.php && \
    sed -i "s|username_here|${DB_USER}|g" wordpress/wp-config.php &&\
    sed -i "s|password_here|${DB_PASSWORD}|g" wordpress/wp-config.php &&\
    sed -i "s|localhost|${DB_HOST}|g" wordpress/wp-config.php;

EXPOSE 9000

ENTRYPOINT [ "/usr/sbin/php-fpm7.3", "-F" ]
