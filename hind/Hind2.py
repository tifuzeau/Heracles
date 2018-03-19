#!/usr/bin/python 

import sys
import time
import requests
import json


RED   = "\033[1;31m"
BLUE  = "\033[1;34m"
GREEN = "\033[0;32m"
RESET = "\033[0;0m"

def print_usage():
    print sys.argv[0] + " : clien_id clien_secret path_file"
    print "for clien_id and clien_secret -1 to use deflaut"

def get_token(CLIENT_ID, CLIENT_SECRET):
    URL_API = "https://api.intra.42.fr";
    ACCESS_TOKEN_URL = "https://api.intra.42.fr/oauth/token"

    payload = {
        "grant_type" : "client_credentials",
        "client_id"  : CLIENT_ID,
        "client_secret" : CLIENT_SECRET
    }
    token = requests.post(ACCESS_TOKEN_URL, payload);
    return (token);

def get_list(path_file):
    out = []
    try:
        fd = open(path_file, "r")
    except IOError:
        print "Erreur! File not exist"
        sys.exit()
    line = fd.readlines()
    out.append(line);
    fd.close()
    return (out);


def print_info(to_print):
    test = sorted(to_print)
    print RED + "red:" + RESET + " for user not found or error"
    print BLUE + "blue:" + RESET + " for user find but not in school now"
    print GREEN + "green:" + RESET + "user find en in school"
    print "not color: user find but is not in 101 student zone"
    for user in test:
        if user['statu'][0] == "z":
            print "\n\t" + GREEN + user['user'] + RESET
        elif user['statu'][0] == "N":
            print "\n\t" + BLUE + user['user'] + RESET
        elif user['statu'][0] == "E":
            print "\n\t" + RED + user['user'] + RESET
        else:
            print "\n\t" + user['user']
        print user['statu']

if len(sys.argv) < 4:
    print_usage();
    sys.exit();

lst_user = get_list(sys.argv[3]);

if sys.argv[1] == "-1" :
    clien_id = "22db69e1b81963a5196c669540e072fec62f7269f3c71a9b0ee36e6b0f4898c3";
else :
    clien_id = sys.argv[1];
if sys.argv[2] == "-1":
    clien_secret = "c6af2954032d1e581f92d2f7d32a85d7d5644aa60b990e536c16816d1b6352b4";
else:
    clien_secret = sys.argv[2];

while True:
    token = get_token(clien_id, clien_secret)
    if token.status_code == 200 :
        break
    elif token.status_code == 500:
        continue 
    else :
        print "Error code:"
        print token.status_code
        sys.exit()
token = token.json();
payload_token ={ 'access_token' : token['access_token']}

to_print = []
for user in lst_user[0] :
    user = user.strip()
    url_request = "https://api.intra.42.fr/v2/users/" + user + "/locations";
    time.sleep(0.7);
    rep = requests.get(url_request, payload_token)
    if  rep.status_code == 200 :
        if rep.json()[0]['end_at']:
            statu = "Not in school"
        else :
            statu = rep.json()[0]['host']
    else :
            statu = "Error " + str(rep.status_code)
    to_print.append({
            'user' : user,
            'statu' : statu
            })
print_info(to_print)
