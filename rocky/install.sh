#Add repo to use docker
dnf config-manager --add-repo=https://download.docker.com/linux/centos/docker-ce.repo
dnf install -y docker-ce
systemctl enable docker
systemctl start docker
#Update the system
dnf update -y
#Create folder to use dockers
mkdir opt/mango/
mkdir opt/mosquitto/
mkdir opt/node-red-data/
#Fix for node-red read error
chown 1000 /opt/node-red-data/

