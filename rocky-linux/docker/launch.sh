#!/bin/bash

# Specify the name of the service you want to run
SERVICE_NAME="omgwtfssl"

# Specify the path to the file you want to check
FILE_PATH="ca-key.pem"

if [ "$EUID" -ne 0 ]; then
    echo "Please run this script with sudo:"
    sudo "$0" "$@"
    exit 1
fi

# Check if the file exists
if [ -f "$FILE_PATH" ]; then
    echo "File exists. Starting the service..."
    docker-compose up -d "$SERVICE_NAME"
    
    # Wait for the service to finish launching
    docker-compose logs -f "$SERVICE_NAME"
    
    echo "Service has finished launching."

    echo "Fixing read/write permission error"

    chmod 777 -R  certs/
else
    echo "File does not exist. Skipping the service start."
fi

docker compose up -d mosquitto mongodb nodered


