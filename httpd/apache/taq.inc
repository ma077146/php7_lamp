DocumentRoot "/var/www/Yellow-PreHire/enterprise/clearstar-qa"
ServerName taq.local
ServerAdmin webmaster@ercdataplus.com
ErrorLog /var/log/apache2/taq-errors
CustomLog /var/log/apache2/taq-combined combined

<Directory "/var/www/Yellow-PreHire">
    Options None
    Order allow,deny
    Allow from All
</Directory>

<DirectoryMatch "/var/www/Yellow-PreHire/enterprise/*/client/*">
    DirectoryIndex index.php index.html index.htm index.shtml
</DirectoryMatch>

<FilesMatch "\.inc">
    Order allow,deny
    Deny from all
</FilesMatch>

Alias /accio "/var/www/Yellow-PreHire/accio"
Alias /admin "/var/www/Yellow-PreHire/admin"
Alias /branding "/var/www/Yellow-PreHire/enterprise/clearstar-qa/branding"
Alias /classes "/var/www/Yellow-PreHire/classes"
Alias /clients "/var/www/Yellow-PreHire/enterprise/clearstar-qa/clients"
Alias /fpdf "/var/www/Yellow-PreHire/fpf"
Alias /frame_work "/var/www/Yellow-PreHire/frame_work"
Alias /images "/var/www/Yellow-PreHire/images"
Alias /include "/var/www/Yellow-PreHire/include"
Alias /jobseeker "/var/www/Yellow-PreHire/jobseeker"
Alias /js_scripts "/var/www/Yellow-PreHire/js_scripts"
Alias /media "/var/www/Yellow-PreHire/media"
Alias /pdf_forms "/var/www/Yellow-PreHire/pdf_forms"
Alias /reports "/var/www/Yellow-PreHire/reports"
Alias /recruiter "/var/www/Yellow-PreHire/recruiter"
Alias /sso "/var/www/Yellow-PreHire/sso"
Alias /st-editor "/var/www/Yellow-PreHire/st-editor"
Alias /st-editor-3 "/var/www/Yellow-PreHire/st-editor-3"
Alias /sterling "/var/www/Yellow-PreHire/sterling"
Alias /style "/var/www/Yellow-PreHire/style"
Alias /system_admin "/var/www/Yellow-PreHire/system_admin"
Alias /tazworks "/var/www/Yellow-PreHire/tazworks"
Alias /theme "/var/www/Yellow-PreHire/theme/business-admin"

