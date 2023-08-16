#!/usr/bin/expect -f

set prompt "#"
spawn sudo bluetoothctl
sleep 1
expect -re $prompt
send "discoverable on\r"
sleep 1
expect "Changing discoverable on succeeded"     
sleep 1 
send "agent NoInputNoOutput\r"
sleep 2
expect "Agent registered"
send "default-agent\r"
expect -re $prompt
sleep 3

# Boucle pour répondre automatiquement à toutes les demandes de confirmation de code
while {1} {
    expect {
        -re ".*Confirm passkey.*" {
            send "yes\r"
        }
        -re ".*Authorize service.*" {
            send "yes\r"
        }

    }
}

interact
expect eof