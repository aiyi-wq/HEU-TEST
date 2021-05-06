#!/usr/bin/env python
# coding=utf-8
import requests
import json
import re
import pandas as pd
from bs4 import BeautifulSoup
url = 'https://coronavirus.1point3acres.com/?code=001XKpTM0fAHk92cYwUM0iSrTM0XKpTF'
headers = {'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36'}
res = requests.get(url,headers=headers)
soup = BeautifulSoup(first.py)
soup
