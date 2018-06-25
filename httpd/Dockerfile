FROM ubuntu:18.04

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update && apt-get install -yq \
    apt-utils \
    bash-completion \
    curl \
    # Install git
    git \
    # Install apache
    apache2 \
    # Install php 7.2
    libapache2-mod-php7.2 \
    php7.2-cli \
    php7.2-json \
    php7.2-curl \
    php7.2-fpm \
    php7.2-gd \
    php7.2-ldap \
    php7.2-memcache \
    php7.2-pspell \
    php7.2-snmp snmp \
    php7.2-mbstring \
    php7.2-mysql \
    php7.2-soap \
    php7.2-sqlite3 \
    php7.2-xml php7.2-xmlrpc php7.2-xdebug \
    libapache2-mod-php \
    php7.2-cli \
    php7.2-zip \
    php7.2-intl \
    php-imagick \
    # Install tools
    nano \
    vim \
    wget \
    net-tools lsof make \
    graphicsmagick \
    imagemagick \
    ghostscript \
    mysql-client \
    iputils-ping \
    nodejs \
    npm \
    zip unzip \
    locales \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Install composer
RUN curl -sS https://getcomposer.org/installer | php -- --install-dir=/usr/local/bin --filename=composer

# Make some directories we need and copy files
RUN mkdir -p /var/lock/apache2 /var/run/apache2
RUN mkdir /etc/ssl/dev
COPY php/php7.ini /etc/php/7.2/apache2/php.ini
COPY apache/ /etc/apache2/sites-available/

# SSL certificates
COPY ssl/* /etc/ssl/dev/
# Library files
COPY lib/pear /usr/share/pear
#Ubuntu 18.04 can also look for these files in /usr/share/php
RUN ln -s /usr/share/pear/* /usr/share/php/
COPY lib/Smarty-2.6.31 /usr/local/lib/php/Smarty-2.6.31
COPY lib/php_pdflib.so /usr/lib/php/20170718/
COPY lib/libpdf_php.ini /etc/php/7.2/apache2/conf.d/

# Ensure there is a symlink to libjpeg.so.8 under /usr/lib (it's in the x86_64-linux-gnu folder.
RUN ln -s /usr/lib/x86_64-linux-gnu/libjpeg.so.8 /usr/lib/libjpeg.so.8

# Set locales
RUN locale-gen en_US.UTF-8 en_GB.UTF-8

RUN a2enmod rewrite expires

# Update the PHP.ini file, enable <? ?> tags and quieten logging.
RUN sed -i "s/short_open_tag = Off/short_open_tag = On/" /etc/php/7.2/apache2/php.ini
RUN sed -i "s/error_reporting = .*$/error_reporting = E_ERROR | E_WARNING | E_PARSE/" /etc/php/7.2/apache2/php.ini
RUN sed -ie 's/memory_limit\ =\ 128M/memory_limit\ =\ 2G/g' /etc/php/7.2/apache2/php.ini
RUN sed -ie 's/\;date\.timezone\ =/date\.timezone\ =\ America\/New_York/g' /etc/php/7.2/apache2/php.ini
RUN sed -ie 's/upload_max_filesize\ =\ 2M/upload_max_filesize\ =\ 200M/g' /etc/php/7.2/apache2/php.ini
RUN sed -ie 's/post_max_size\ =\ 8M/post_max_size\ =\ 200M/g' /etc/php/7.2/apache2/php.ini

RUN a2dissite 000-default && \
    a2ensite i9.conf && \
    a2ensite taq.conf && \
    a2ensite wfm.conf && \
    a2enmod ssl && \
    a2enmod rewrite && \
    mkdir /var/cache/htmlpurifier && \
    chown www-data:www-data /var/cache/htmlpurifier

# Manually set up the apache environment variables
ENV APACHE_RUN_USER www-data
ENV APACHE_RUN_GROUP www-data
ENV APACHE_LOG_DIR /var/log/apache2
ENV APACHE_LOCK_DIR /var/lock/apache2
ENV APACHE_PID_FILE /var/run/apache2.pid

# Set the ServerName
RUN echo "ServerName PSY-PHP7-Dev-Env" >> /etc/apache2/apache2.conf

EXPOSE 80 443 9000

# WORKDIR /var/www/html

CMD ["apache2ctl", "-D", "FOREGROUND"]