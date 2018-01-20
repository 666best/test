#coding=utf-8

import requests
from bs4 import BeautifulSoup
import os

Path='D:/python/mm/jpg/'

header = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/50.0.2661.102 UBrowser/6.1.2107.204 Safari/537.36'}
for H_page in range(1,10):
    url = 'http://www.zbjuran.com/mei/mingxing/list_15_'+str(H_page)+'.html'
    html = requests.get(url,headers = header)
    soup = BeautifulSoup(html.text,'html.parser')
    all_b = soup.find_all('b')

    #找到每一大页的图片链接
    print('开始爬第'+str(H_page)+'大页')
    for b in all_b:
        if(b.find('a')!=None):
            print(b.find('a')['href'])
            url_pic='http://www.zbjuran.com'+b.find('a')['href']
            html_pic=requests.get(url_pic,headers = header)
            soup_new = BeautifulSoup(html_pic.text,'html.parser')
            all_title = soup_new.find('h2').text
            all_page=soup_new.find_all('a',href=True)
            print(all_title)
            Path_=Path+all_title+'/'
            if(os.path.exists(Path_)):
                
                print('目录已存在：跳过')
                continue
            else:
                os.makedirs(Path_)
                print('目录已创建')    
                os.chdir(Path_)            
             #找到最大页

            page_max=0
            for page in all_page:
                if str(b.find('a')['href'][-9:-5])in str(page['href']):
                    page_max=page_max+1

            
            for page_new in range(1,page_max+1):
                url_page_new = 'http://www.zbjuran.com'+b.find('a')['href'][:-5]+'_'+str(page_new)+'.html'
                html_page_new = requests.get(url_page_new,headers = header)
                soup_page_new = BeautifulSoup(html_page_new.text,'html.parser')
                all_b_page_new = soup_page_new.find_all('img',src=True)
                for b_page_new in all_b_page_new[0:1]:
                    b_page_new_url=b_page_new['src']
                page_new_url='http://www.zbjuran.com'+b_page_new_url
                print(page_new_url)
                html_page_new = requests.get(page_new_url,headers = header)
                add_f=page_new_url.split('.')[-1]
                print(add_f)
                name_f=str(page_new)+'.'+add_f
                f = open(name_f,'wb')
                f.write(html_page_new.content)
                f.close()   
                print('完成')    














