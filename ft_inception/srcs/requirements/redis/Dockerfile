FROM debian:buster

RUN apt update
RUN apt install -y redis

COPY tools/redis_startup.sh ./
CMD chmod +x ./redis_startup.sh

CMD sh ./redis_startup.sh

