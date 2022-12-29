if [ ! -f "/etc/vsftpd.kk" ]; then

	mkdir -p /var/run/vsftpd/empty

        adduser $FTP_USER --disabled-password
        echo "$FTP_USER:$FTP_PASS" | /usr/sbin/chpasswd &> /dev/null
        chown -R $FTP_USER:$FTP_USER /var/www/html

        echo $FTP_USER | tee -a /etc/vsftpd.userlist &> /dev/null

        touch /etc/vsftpd.kk
fi
/usr/sbin/vsftpd
