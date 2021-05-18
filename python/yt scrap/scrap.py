import time
import json
from bs4 import BeautifulSoup
import re
import requests
import csv
import fileinput


url = "https://www.youtube.com/channel/UChCtkJpcNatfFcV5_-OVJ5A/videos"
result = requests.get(url)
result2 = BeautifulSoup(result.text, 'html.parser')

aa = result2.findAll('script')
a = aa[32]
a = a.contents
rere = a[0].replace("var ytInitialData = ", "")

with open('output.json', 'w') as outfile:
    json.dump(rere, outfile)

with fileinput.FileInput(output.json, inplace=True, backup='.bak') as file:
    for line in file:
        print(line.replace("\/"", "/""), end='')








