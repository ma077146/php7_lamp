# Initial Setup

##ASSUMPTIONS:
1.  You have already installed Docker Toolbox for Windows.
2.  You have either used Kitmatic or Docker Quick Start Terminal to create a Docker VM
3.  You know how to ask questions if question 1 or 2 have you befuddled.
4.  In your Windows/System32/drivers/etc/hosts file, you already have the below entries:

    192.168.99.100 taq.local
    
    192.168.99.100 i9.local
    
    192.168.99.100 wfm.local

5.  If you don't have the above, make it so!

You can set this new dev environment up in any directory.  I placed it in the same directory as the old
php_dev_envs.

If this is your first attempt at setting up a PHP7 dev environment, C:/Users/<your-name>/docker is a good place!

The contents of the httpd/apache directory will be same regardless of the developer.

The contents of enterprises/svs, enterprises/selectech, and mysql/data will differ if you already have an
existing local environment set up.  We'll change these below.  They are included in the .gitignore file,
so any changes you make locally won't be added back to the repository.

### Clone the PHP7 dev envs repo
Go (cd) to the directory where you want the new PHP7 dev envs.
1. Type 'git clone git@github.com:ma077146/php7_lamp.git' and hit enter.
2. Create a directory called "repos" in the httpd directory.
3. Copy your old TAQ, I9, and WFM repos into the httpd/repos directory.
   NOTE: since these each have their own repository, they are excluded from this repository.
4. Copy your enterprises/svs data into the httpd/enterprises/svs directory.
5. Copy your enterprises/selectech data into the httpd/enterprises/selectech directory.
6. Create a  directory called "data" in the mysql directory.
7. Copy your mysql/data files (directories only, no files!) into the mysql/data directory.

TASK:

    [a] cd into the httpd/enterprises directory
    [b] chmod -R 777 svs
    [c] chmod -R 777 selectech
    
ANOTHER NOTE: If you don't have an existing dev environment, ask another developer to help you for this part.

### Build the new dev envs
If you don't already, you're going to learn to love docker compose and Dockerfile.  You literally have one thing to do for the build.  Ready?
1. In a terminal, cd into your php7_lamp directory.
2. Type 'docker-compose up -d' and hit enter.
3. This will take awhile, perhaps, you should get a favorite beverage, return a phone call, etc.

When this is done, you'll see something very similar to the below, and you'll be back at the command prompt:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Successfully built blah-blah-blah
Successfully tagged php7-server:ubuntu-18.04
Creating php7lamp_mysql_1 ... done
Creating php7lamp_httpd_1 ... done

mapruitt@MP-PF0X255B-LT MINGW64 ~/docker/php7_lamp (master)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


# Database updates
### Update MySQL
We need to do a mysql_upgrade to get to MySQL 5.7.23, and we'll need to change the 
database address from localhost to 192.168.99.100.

In any docker container, "localhost" refers to anything inside that container.  
Since our MySQL database is in another docker container, we need to reference if
by it's ip address and port.

Find the Kitematic application which was installed with Docker Toolbox, and open in.

NOTE: If the steps below don't work, try the next set of 6 steps first.

1. From Kitmatic, click mysql container in left column.
2. Click "Exec" button.
3. Type "mysql_upgrade --force -u root -p" and hit enter.
4. Type "password" for password.

## Change DB address from localhost to 192.168.99.100
1. While still in the terminal, type 'mysql -u root -p;' and hit enter.
2. Type 'password' and hit enter.
3. Type 'UPDATE selectech_central.enterprise SET system_db_address = '192.168.99.100';' and hit enter.
4. Type 'UPDATE svs_central.enterprise SET system_db_address = '192.168.99.100';' and hit enter.
5. Type 'UPDATE clrstar_system.client SET database_address = '192.168.99.100';' and hit enter.
6. Type 'UPDATE svs_erc_system.client SET database_address = '192.168.99.100';' and hit enter.

Use MySQL Workbench or other tool of your choice to reach your data at 192.168.99.100, port = 3306, user = root, and password = password.

It would be a good idea to make a backup of all of your databases, including mysql, sooner rather than later.

At this point, you should have a fully functional local dev environment.  Point your browser to https://taq.local
or https://i9.local and see if you can log in.

#IT WOULD REALLY BE WORTH YOUR TIME TO READ THIS NEXT PART!

To stop your setup, you can go to the php7_lamp directory and type 'docker-compose stop' and hit enter.
To start it, go to the same place and type 'docker-compose start'.
To restart, go to the same place and type 'docker-compose restart'.

Unless you're very comfortable with Docker and docker compose, don't run any additional commands.

The correct way to store database data on your local host is in a docker volume.  If you don't know what that is, it's ok, just know it's part of the docker virtual machine on your host (laptop) where data is persistently stored.

Here is what you need to know.
- the docker volume mysql_data was created for your setup.
- while the data will persist on your local, it's your responsibility to periodically back it up.

## Before you get busy doing something else.....
Make a dumpfile of your current databases.  This will be for your client related databases; don't worry about
the MySQL database.  It's part of the docker container, and easy enough to get back if it gets messed up.

I use MySQL Workbench, so I used the mysqldump tool included.

Set up a data export (Choose "Export to Self-Contained File", check "Create Dump in a single Transaction", and
"Include Create Schema").

Click "Start Export" and watch for your results.  If you get no errors, you're good.  If you get errors (missing tables, etc.) fix them.  Repeat this process until you have no errors and can successfully make a mysqldump for your client data.

Usually, this is saved into User/<username>/Documents/dumps with whatever name you gave it.  Find it, zip it, and move the zipped file to php7_lamp/mysql/dumps. The .zip file will save your precious disk space (you're welcome). Delete the original file.

You can use this file to restore your client data if you ever have to rebuild your containers.  Unzip the .zip file and import it using your database tool.

## For Pro's Only!
Backup your database directories to your local hard drive.

From your favorite terminal (with the docker containers up and running, of course):

[1] docker ps -a

[2] copy the container ID for the mysql database container

[3] in a terminal type 'docker cp <containerID>:/var/lib/mysql/ c:/Users/your-name/my_directory/' and hit enter.

The individual database directories, including mysql and performance schema will be copied to your local drive
from the docker volume.

You can replace the contents of /mysql/data with these directories, and if you rebuild your containers, you'll start with current data!

## Install PHP7 and Composer on Windows 10
At the time of this writing, it's June 6, 2018. It's time for you to do this.

Here is a link to a really good article about how to do it right.
https://www.jeffgeerling.com/blog/2018/installing-php-7-and-composer-on-windows-10