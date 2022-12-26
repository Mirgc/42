if [ ! -f "/etc/vsftpd.kk" ]; then

        touch /etc/vsftpd.kk

        adduser $FTP_USER --disabled-password
        echo "$FTP_USER:$FTP_PASS" | /usr/sbin/chpasswd &> /dev/null
        chown -R $FTP_USER:$FTP_USER /var/www/html

        echo $FTP_USER | tee -a /etc/vsftpd.userlist &> /dev/null

fi

/usr/sbin/vsftpd #/etc/vsftpd.conf

