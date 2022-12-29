
all: files
	@docker-compose -f srcs/docker-compose.yml up -d

files:
	@if [ ! -d /home/migarcia/data/db ]; then \
		mkdir -p /home/migarcia/data/db; \
	fi
	@if [ ! -d /home/migarcia/data/wp ]; then \
		mkdir -p /home/migarcia/data/wp; \
	fi
	@if [ ! -d /home/migarcia/data/ssl ]; then \
		mkdir -p /home/migarcia/data/ssl; \
	fi
	@if ! grep -q "migarcia.42.fr" /etc/hosts; then \
		echo "127.0.0.1 migarcia.42.fr" >> /etc/hosts; \
	fi

build: files
	@docker-compose -f srcs/docker-compose.yml up -d --build

down:
	@docker-compose -f srcs/docker-compose.yml down

stop:
	@docker-compose -f srcs/docker-compose.yml stop

start:
	@docker-compose -f srcs/docker-compose.yml start

ps:
	@docker-compose -f srcs/docker-compose.yml ps

fclean: down
	@docker rmi -f $$(docker images -qa);\
	docker volume rm $$(docker volume ls -q);\
	docker system prune -a --force
	@sudo rm -Rf /home/migarcia/data/db
	@sudo rm -Rf /home/migarcia/data/wp

re:	fclean	all
.PHONY : all build down ps fclean re
