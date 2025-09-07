
from twilio.rest import Client
import sys

account_sid = 'AC52e2472f1b1830145b605e282df273bd'
auth_token = '75941ca964686bd0e2d5bf2a45ba652e'
client = Client(account_sid, auth_token)
def main(arg) : 
    message = client.messages.create(
    from_='+15737794711',
    body='your bike is being stolen '+ arg ,
    to='+32476776075'
    )

    print(message.sid)

if __name__ == "__main__":
   main(sys.argv[1])

