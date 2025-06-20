import requests
from html.parser import HTMLParser
import time
import threading

meet = False
l = set()
url = 'http://221.2.86.180:9009'

class Test(HTMLParser):
    def handle_starttag(self, tag, attrs):
        global meet
        if tag == 'a' and ('class', 'text-primary') in attrs:
            meet = True
    def handle_data(self, data):
        global meet
        if meet and len(data) > 1 and data[0] != '距':
            l.add(data)
    def handle_endtag(self, tag):
        global meet
        meet = False
        pass


def add():
    # print(i, len(l))
    print(f"begin")
    p.feed(requests.get(url).text)
    print(f"end")


if __name__ == "__main__":

    p = Test()
    for i in range(1000):
        newt = threading.Thread(target=add)
        newt.start()
        newt.join()
        # print(i)
        # time.sleep(0.1)

    open('名言.txt', 'w').write("list:\n")
    for t in l:
        open('名言.txt', 'a').write(t+"\n")
        
    # open('名言.txt', 'w').write(str(l))

