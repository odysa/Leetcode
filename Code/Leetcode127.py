from collections import defaultdict


class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        if endWord not in wordList or not beginWord:
            return 0
        if not wordList or not endWord:
            return 0
        Word_len = len(beginWord)
        combo = defaultdict(list)
        for word in wordList:
            for i in range(Word_len):
                combo[word[:i]+'!'+word[i+1:]].append(word)
        Queue = [(beginWord, 1)]
        visited = {beginWord: True}
        while Queue:
            word, level = Queue.pop(0)
            for i in range(Word_len):
                tmp = word[:i]+'!'+word[i+1:]
                for w in combo[tmp]:
                    if w == endWord:
                        return level+1
                    if w not in visited:
                        Queue.append((w, level+1))
                        visited[w] = True
                combo[tmp] = []
        return 0
