import sys

n = -1
runners = []

for line in sys.stdin:
    if n == -1:
        n = int(line)
        continue

    (name, st, se) = line.split(' ')
    runners.append((float(se), float(st), name))

runners = sorted(runners)

minn = 1000
team = []

for i in range(n):
    a = -1
    b = -1
    c = -1

    for j in range(n):
        if a == -1 and j != i:
            a = j

        if b == -1 and j != i and j != a:
            b = j

        if c == -1 and j != i and j != a and j != b:
            c = j
            break

    candidate = runners[i][1] + runners[a][0] + runners[b][0] \
        + runners[c][0]

    if candidate < minn:
        minn = candidate
        team = [runners[i][2], runners[a][2], runners[b][2],
                runners[c][2]]

print '{:.10f}'.format(minn)

for runner in team:
    print runner