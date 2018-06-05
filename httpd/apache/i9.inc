DocumentRoot "/var/www/ERC-Selectech-I9/enterprise/erc"
ErrorLog /var/log/apache2/i9-errors
CustomLog /var/log/apache2/i9-combined combined
ServerName i9.local
ServerAdmin joe.tippetts@peoplestrategy.com

<Directory "/var/www/ERC-Selectech-I9">
    Options All
    Order allow,deny
    Allow from All
</Directory>
    
<FilesMatch "\.inc">
    Order allow,deny
    Deny from all
</FilesMatch>

Alias /admin "/var/www/ERC-Selectech-I9/admin"
Alias /brent "/var/www/ERC-Selectech-I9/brent"
Alias /employee "/var/www/ERC-Selectech-I9/employee"
Alias /images "/var/www/ERC-Selectech-I9/images"
Alias /integration "/var/www/ERC-Selectech-I9/integration"
Alias /js_scripts "/var/www/ERC-Selectech-I9/js_scripts"
Alias /media "/var/www/ERC-Selectech-I9/media"
Alias /style "/var/www/ERC-Selectech-I9/style"
Alias /theme "/var/www/ERC-Selectech-I9/theme/business-admin/non-ajax"

