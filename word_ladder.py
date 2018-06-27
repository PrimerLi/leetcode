class Vertex:
    def __init__(self, word, color, parent):
        self.word = word
        self.color = color
        self.parent = parent
    def __str__(self):
        return self.word

class Solution(object):
    def to_dictionary(self, word_list):
        D = dict()
        for i in range(len(word_list)):
            D[word_list[i]] = []
        def is_adj(word_1, word_2):
            if (len(word_1) != len(word_2)):
                return False
            counter = 0
            for i in range(len(word_1)):
                if (word_1[i] != word_2[i]):
                    counter += 1
            return counter == 1
        for i in range(len(word_list)):
            for j in range(len(word_list)):
                if (is_adj(word_list[i], word_list[j])):
                    if (not word_list[i] in D[word_list[j]]):
                        D[word_list[j]].append(word_list[i])
                    if (not word_list[j] in D[word_list[i]]):
                        D[word_list[i]].append(word_list[j])
        keys = D.keys()
        for key in keys:
            print key, "->", ",".join(D[key])
        return D
    
    def to_graph(self, word_list):
        print "Creating the dictionary ... "
        D = self.to_dictionary(word_list)
        print "Dictionary created. "
        graph = dict()
        keys = D.keys()
        for key in keys:
            graph[key] = map(lambda word: Vertex(word, "white", None), D[key])
        return graph
    
    def find_path(self, start, target, word_list):
        word_list.insert(0, start)
        print "Creating the graph ... "
        graph = self.to_graph(word_list)
        print "Graph created. "
        Q = []
        Q.append(Vertex(start, "white", None))
        while(len(Q) != 0):
            u = Q.pop(0)
            u.color = "black"
            adj = graph[u.word]
            for v in adj:
                if (v.color == "white"):
                    v.color = "grey"
                    v.parent = u
                    Q.append(v)
                    if (v.word == target):
                        iterator = v
                        result = []
                        while(iterator != None):
                            result.append(iterator.word)
                            print iterator
                            iterator = iterator.parent
                        return list(reversed(result))
        return []
    
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        path = self.find_path(beginWord, endWord, wordList)
        print "->".join(path)
        return len(path)

def read_words(inputFileName):
    import os
    assert(os.path.exists(inputFileName))
    ifile = open(inputFileName, "r")
    string = ifile.readline()
    string = string.strip("[").strip("]").replace('"', "")
    result = string.split(",")
    ifile.close()
    return result
       
def main():
    import sys
    if (len(sys.argv) != 2):
        print "inputFileName = sys.argv[1]. "
        return -1

    inputFileName = sys.argv[1]
    solution = Solution()
    start = "sand"
    target  = "acne"
    word_list = read_words(inputFileName)
    print solution.ladderLength(start, target, word_list)

main()
