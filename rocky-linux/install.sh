
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
sudo usermod -aG docker $USER

sudo systemctl enable docker.service
sudo systemctl enable containerd.service

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

#Maybe add a VPN service to encrypt all trafic could help ?

