FROM debian:buster

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y mariadb-server


COPY tools/mariadb_startup.sh ./
CMD chmod +x ./mariadb_startup.sh

EXPOSE 3306

CMD sh ./mariadb_startup.sh
