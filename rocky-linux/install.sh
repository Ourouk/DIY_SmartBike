
#Check if user run this script as root
if [ $UID != 0 ]; then
    echo "Please run this script with sudo:"
    sudo "$0" "$@"
    exit 1
fi

#Add repo to use docker
dnf config-manager --add-repo=https://download.docker.com/linux/centos/docker-ce.repo
#Update the system
dnf update -y
dnf install -y docker-ce
dnf upgrade -y


groupadd docker
usermod -aG docker $USER

systemctl enable docker.service
systemctl enable containerd.service

firewall-cmd --permanent --new-service=nodejs_app
firewall-cmd --permanent --service=nodejs_app --set-description="Node.js Application"
firewall-cmd --permanent --service=nodejs_app --add-port=1880/tcp
firewall-cmd --permanent --add-service=nodejs_app

firewall-cmd --permanent --new-service=mosquitto
firewall-cmd --permanent --service=mosquitto --set-description="Mosquitto MQTT"
firewall-cmd --permanent --service=mosquitto --add-port=8883/tcp
firewall-cmd --permanent --add-service=mosquitto

firewall-cmd --permanent --new-service=mongodb
firewall-cmd --permanent --service=mongodb --set-description="MongoDB Service"
firewall-cmd --permanent --service=mongodb --add-port=27017/tcp
firewall-cmd --permanent --add-service=mongodb

firewall-cmd --reload


#TODO: Maybe add a VPN service to encrypt all trafic could help ?


echo "A reboot is necessary !"s
echo "Do you want to reboot the computer? (y/n)"
read answer
if [ "$answer" != "${answer#[Yy]}" ] ;then
    echo "The computer will reboot in 5 seconds. Press Ctrl+C to cancel."
    sleep 5
    sudo reboot
else
    echo "Reboot cancelled."
fi
