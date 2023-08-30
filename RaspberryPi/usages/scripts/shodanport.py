import requests

def shodan_query (api_key):
    url = f'https://api.shodan.io/shodan/ports?key={api_key}'
    response = requests.get(url)
    return response.json()

if __name__ == "__main__":
    api_key = 'dGiMWqNzMVj9fS7DelAl37cZK3fzjYC6'
    shodan_data = shodan_query( api_key)
    print("Shodan port scan :")
    print(shodan_data)