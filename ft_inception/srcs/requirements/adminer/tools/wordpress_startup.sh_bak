echo "Creating WP Configuration"
cd /var/www/html
if [ ! -d /var/www/html/wordpress ]; then
	curl -o wordpress.tar.gz "https://wordpress.org/wordpress-$WP_VERSION.tar.gz"
	tar -xzf wordpress.tar.gz
        cp ./wordpress/wp-config-sample.php ./wp-config.php
        rm -rf wordpress.tar.gz wordpress
        chown -R www-data:www-data /var/www/html
	
	sed -i "s|database_name_here|$DB_NAME|g" wp-config.php && \
	sed -i "s|username_here|$DB_USER|g" wp-config.php &&\
	sed -i "s|password_here|$DB_PASS|g" wp-config.php &&\
	sed -i "s|localhost|$DB_HOST|g" wp-config.php;

	curl -o /usr/local/bin/wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x /usr/local/bin/wp
	echo "Installing Wordpress"
	wp core download --allow-root
	wp core install --allow-root --url="$DOMAIN_NAME" --title="FT_INCEPTION" --admin_user="$WP_ADMIN" --admin_password="$WP_ADMIN_PASS" --admin_email="$WP_EMAIL"
	wp user create $WP_USER $WP_EMAIL --user_pass=$WP_PASS --role="administrator"
	wp media regenerate -y
else
	echo "Wordpress config already done"
fi

echo "Wordpress ready!"

php-fpm7.3 --nodaemonize
