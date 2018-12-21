import os
import requests
import json
import config


def getData(cookies):
    headers = {
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
        'Accept-Encoding': 'gzip, deflate',
        'Accept-Language': 'en-US,en;q=0.5',
        'Connection': 'close',
        'Host': 'leetcode.com',
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:64.0) Gecko/20100101 Firefox/64.0',
        'Referer': 'https://leetcode.com/problemset/algorithms/',
        'X-Requested-With': 'XMLHttpRequest',
    }
    url = "https://leetcode.com/api/problems/algorithms/"
    r = requests.get(url=url, headers=headers, cookies=cookies)
    hjson = json.loads(r.text)
    return hjson


pData = getData(config.cookies)

num_solved = pData['num_solved']
easy_solved = pData['ac_easy']
medium_solved = pData['ac_medium']
hard_solved = pData['ac_hard']
problems_solved = []
problems_stats = []
readme_dir = 'F:/Practice/myleetcode/README.md'
template = """# Stay Hungry, Stay Foolish
My own leetcode solutions.
TODO:
1. update 1-two-sum.c using hash table.
2. update 28-implement-strstr.c using KMP and Boyer-Moore algorithm.
3. update 5-longest-palindromic-substring.c using manacher algorithm.

Completion statistic:<br>
- Total : %d<br>
    - Easy : %d<br>
    - Medium : %d<br>
    - Hard : %d<br>

-----------------------
## LeetCode Solution Table
| ID | Title | Difficulty | Acceptance Rate | C |
|:---:|:---:|:---:|:---:|:---:|
"""

table_template = """|%03d|[%s](https://leetcode.com/problems/%s/description/) |%s|%s|[C](https://github.com/A11riseforme/myleetcode/blob/master/src/%d-%s.c)|
"""

for i in pData['stat_status_pairs']:
    if i['status'] == 'ac':
        problems_solved.append(i)

for i in problems_solved[::-1]:
    problems_stats.append(str(i['stat']['question_id']) + ':' + i['stat']['question__title'] + ':' + str(
        i['difficulty']['level']).replace('1', 'easy').replace('2', 'medium').replace('3', 'hard') + ':' + str(
        i['stat']['total_acs'] / i['stat']['total_submitted'])[0:5] + ':' + i['stat']['question__title_slug'])


with open(readme_dir, "r+") as f:
    f.truncate()
    f.write(template % (num_solved, easy_solved, medium_solved, hard_solved))


for i in problems_stats:
    with open(readme_dir, "a+") as f:
        tmp = i.split(':')
        f.write(table_template % (int(tmp[0]), tmp[1], tmp[4], tmp[2], tmp[3], (int(tmp[0])), tmp[4]))


os.chdir("F:/Practice/myleetcode/")
os.system('dir')
os.system("git commit README.md -m \"update README.md\" && git push")