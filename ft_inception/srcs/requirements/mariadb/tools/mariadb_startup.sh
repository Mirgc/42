echo "Creating WP DB"
if [ ! -f /var/lib/mysql/mariadb.kk ]; then
	service mysql start
    	until mysqladmin ping; do
		sleep 2
	done
	mysql -u root -e "CREATE DATABASE IF NOT EXISTS $DB_NAME;"
	mysql -u root -e "CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_PASS';"
	mysql -u root -e "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%';"
	mysql -u root -e "FLUSH PRIVILEGES;"
	mysql -u root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASS';FLUSH PRIVILEGES;"

	sed -i "s|bind-address|#bind-address|g" /etc/mysql/mariadb.conf.d/50-server.cnf
	cat /etc/mysql/mariadb.conf.d/50-server.cnf |grep "bind-add"

	touch /var/lib/mysql/mariadb.kk
else
	echo "Wordpress database already exits"
fi

killall mysqld
#mysqld_safe is the recommended way to start a mysqld server on Unix
/usr/bin/mysqld_safe
