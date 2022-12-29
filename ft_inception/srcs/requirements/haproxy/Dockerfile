FROM debian:buster

RUN     apt-get update && apt-get upgrade
RUN	apt-get install -y haproxy

RUN	mkdir /run/haproxy/
COPY	./conf/haproxy.cfg /etc/haproxy/haproxy.cfg

EXPOSE 80

CMD ["haproxy", "-f", "/etc/haproxy/haproxy.cfg"]
