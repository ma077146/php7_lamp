

# Database updates
-- Update MySQL
1. From Kitmatic, click mysql container in left column
2. Click "Exec" button
3. Type "mysql_upgrade --force -u root -p" and hit enter
4. Type "password" for password

-- Change DB address from localhost to 192.168.99.100
1. While still in the terminal, type 'mysql -u root -p;' and hit enter
2. Type 'password' and hit enter
3. Type 'UPDATE selectech_central.enterprise SET system_db_address = '192.168.99.100';' and hit enter
4. Type 'UPDATE svs_central.enterprise SET system_db_address = '192.168.99.100';' and hit enter
5. Type 'UPDATE clrstar_system.client SET database_address = '192.168.99.100';' and hit enter
6. Type 'UPDATE svs_erc_system.client SET database_address = '192.168.99.100';' and hit enter