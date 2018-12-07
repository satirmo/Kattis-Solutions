import sys

n = -1
m = -1

scores = [(0, 0)] * 100005
st = set()

for line in sys.stdin:
    if n == -1:
        (n, m) = map(int, line.split(' '))
        continue

    (idx, penalty) = map(int, line.split(' '))
    scores[idx] = (scores[idx][0] + 1, scores[idx][1] - penalty)

    if idx == 1:
        keep = [i for i in st if scores[i] > scores[1]]
        st = set(keep)
    elif scores[idx] > scores[1]:

        st.add(idx)

    print len(st) + 1

			