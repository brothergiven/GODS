from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from webdriver_manager.chrome import ChromeDriverManager
from bs4 import BeautifulSoup
import time
import random

options = webdriver.ChromeOptions()
options.add_argument("--headless")
driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=options)

all_problems_second = []
all_problems_third = []

def grade2_load_random_problem(page_num):
    url = f"https://school.programmers.co.kr/learn/challenges?order=recent&page={page_num}&levels=2%2C1&languages=java%2Ccpp%2Cpython3"
    
    driver.get(url)
    
    WebDriverWait(driver, 10).until(
        EC.presence_of_element_located((By.CSS_SELECTOR, "td.title > div > a"))
    )
    
    html = driver.page_source
    soup = BeautifulSoup(html, 'html.parser')

    problems = soup.select("td.title > div > a")
    levels = soup.select("td.level")
    
    for problem, level in zip(problems, levels):
        title = problem.text.strip()
        link = problem['href']
        level_text = level.text.strip()
        all_problems_second.append({
            "title": title,
            "link": f"https://school.programmers.co.kr{link}",
            "level": level_text
        })


def grade3_load_random_problem(page_num):
    url = f"https://school.programmers.co.kr/learn/challenges?order=recent&page={page_num}&levels=2%2C3%2C4&languages=java%2Ccpp%2Cpython3"
    
    driver.get(url)
    
    WebDriverWait(driver, 10).until(
        EC.presence_of_element_located((By.CSS_SELECTOR, "td.title > div > a"))
    )
    
    html = driver.page_source
    soup = BeautifulSoup(html, 'html.parser')

    problems = soup.select("td.title > div > a")
    levels = soup.select("td.level")
    
    for problem, level in zip(problems, levels):
        title = problem.text.strip()
        link = problem['href']
        level_text = level.text.strip()
        all_problems_third.append({
            "title": title,
            "link": f"https://school.programmers.co.kr{link}",
            "level": level_text
        })


for i in range(1, 12):
    grade2_load_random_problem(i)
    grade3_load_random_problem(i)

if all_problems_second:
    random_problem1 = random.choice(all_problems_second)
    random_problem2 = random.choice(all_problems_second)
    print("2학년 문제")
    print(f"랜덤으로 선택된 문제: {random_problem1['title']}")
    print(f"문제 링크: {random_problem1['link']}")
    print(f"난이도: {random_problem1['level']}\n")
    
    print(f"랜덤으로 선택된 문제: {random_problem2['title']}")
    print(f"문제 링크: {random_problem2['link']}")
    print(f"난이도: {random_problem2['level']}\n")
    print("**************************************************\n")
else:
    print("문제를 찾을 수 없습니다.")

if all_problems_third:
    random_problem = random.choice(all_problems_third)
    print("3학년 문제")
    print(f"랜덤으로 선택된 문제: {random_problem['title']}")
    print(f"문제 링크: {random_problem['link']}")
    print(f"난이도: {random_problem['level']}")
else:
    print("문제를 찾을 수 없습니다.")

driver.quit()
