from collections import Counter


def find_min(pairs):
    minimum = min(pairs, key=lambda i:i[1])
    pairs.remove(minimum)
    return minimum

def print_list(pairs, key, string, left=None):
    if len(key) == 1 and left == True:
        print key, string
    elif len(key) == 1 and left == False:
        print key, string
    else:
        left, right = pairs[key]
        print_list(pairs, left[0], string+'0', left=True)
        print_list(pairs, right[0], string+'1', left=False)

def huffman(string):
    count_dict = Counter(string)
    pairs = []
    for key, value in count_dict.items():
        pairs.append((key, value))

    final = {}
    _new = None
    for _ in xrange(len(pairs)-1):
        x = find_min(pairs)
        y = find_min(pairs)

        _new = (x[0]+y[0], x[1]+y[1])

        pairs.append(_new)
        final[_new[0]] = [x, y]
    print_list(final, _new[0], '')

if __name__ == '__main__':
    string = 'AAAAAAAAAAABBCD'
    huffman(string)
