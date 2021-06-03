#!/usr/bin/python3
""" recursive function that queries the Reddit API """
import requests
import sys


def count_words(subreddit, word_list, kw_count={}, next_page=None, reap_kw={}):
    """ all hot posts by keyword """
    headers = {"User-Agent": "Juan-Bogota"}

    if next_page:
        subRhot = requests.get('https://reddit.com/r/' + subreddit +
                               '/hot.json?after=' + next_page,
                               headers=headers)
    else:
        subRhot = requests.get('https://reddit.com/r/' + subreddit +
                               '/hot.json', headers=headers)

    if subRhot.status_code == 404:
        return

    if kw_count == {}:
        for word in word_list:
            kw_count[word] = 0
            reap_kw[word] = word_list.count(word)

    subRhot_dict = subRhot.json()
    subRhot_data = subRhot_dict['data']
    next_page = subRhot_data['after']
    subRhot_posts = subRhot_data['children']

    for post in subRhot_posts:
        post_data = post['data']
        post_title = post_data['title']
        title_words = post_title.split()
        for w in title_words:
            for key in kw_count:
                if w.lower() == key.lower():
                    kw_count[key] += 1

    if next_page:
        count_words(subreddit, word_list, kw_count, next_page, reap_kw)

    else:
        for key, value in reap_kw.items():
            if value > 1:
                kw_count[key] *= value

        sorted_abc = sorted(kw_count.items(), key=lambda x: x[0])
        sorted_res = sorted(sorted_abc, key=lambda x: (-x[1], x[0]))
        for res in sorted_res:
            if res[1] > 0:
                print('{}: {}'.format(res[0], res[1]))
