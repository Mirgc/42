FROM debian:buster

RUN apt update
RUN apt install -y vsftpd

COPY conf/vsftpd.conf /etc/vsftpd.conf
COPY tools/ftp_startup.sh ./
CMD chmod +x ./ftp_startup.sh

EXPOSE 21
EXPOSE 21100

CMD sh ./ftp_startup.sh

