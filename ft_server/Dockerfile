FROM debian:buster

RUN apt-get -y update
RUN apt-get -y install \
	nginx \
	openssl \
	vim \
	wget \
	php7.3-fpm \
	php-fpm \
	mariadb-server \
	php-mysql

ENV AUTOINDEX 1

COPY srcs/run.sh /
COPY srcs/default /tmp
COPY srcs/phpinfo.php /tmp
COPY srcs/config.inc.php /tmp
COPY srcs/wp-config-sample.php /tmp

EXPOSE 80 443

CMD bash run.sh
