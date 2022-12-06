FROM debian:buster

ARG DB_NAME
ARG DB_USER
ARG DB_PASSWORD
ARG DB_ROOT_PASSWORD

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y mariadb-server


#COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY mariadb_startup.sh .

RUN sh mariadb_startup.sh && rm -f mariadb_startup.sh

EXPOSE 3306

ENTRYPOINT ["mysqld"]
