echo "Creating Adminer Configuration"
cd /var/www/html
if [ ! -f adminer.kk ]; then

	wget https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1-mysql.php
	mv adminer-4.8.1-mysql.php index.php
	service nginx start
	touch adminer.kk
else
	echo "Adminer config already done"
fi

php-fpm7.3 --nodaemonize
