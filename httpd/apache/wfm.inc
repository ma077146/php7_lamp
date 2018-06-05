DocumentRoot /var/www/Yellow-TimeandLabor/www
ServerName wfm.local
ServerAdmin german.gonzalez@peoplestrategy.com

ErrorLog /var/log/apache2/wfm-errors
CustomLog /var/log/apache2/wfm-combined combined

<Directory /var/www/Yellow-TimeandLabor/www>
	Options Indexes FollowSymLinks MultiViews
	AllowOverride All
	DirectoryIndex index.php
	#Require all granted
</Directory>

