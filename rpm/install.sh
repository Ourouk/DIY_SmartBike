dnf -y update
dnf -y install docker
#Is used to store Database
docker pull postgres
#Subscribe to mqtt Events
docker pull eclipse-mosquitto
#Is Subscribed to Mosquitto server, and push data to the database.
docker pull truecharts/node-red