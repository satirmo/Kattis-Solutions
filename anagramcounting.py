import sys

lines = [line.replace('\n', '') for line in sys.stdin.readlines()]

fact = [1]

for i in range(105):
    num = (i + 1) * fact[i]
    fact.append(num)

for line in lines:
    freq = [0 for i in range(1005)]

    for c in line:
        freq[ord(c)] += 1

    ans = fact[len(line)]

    for cnt in freq:
        ans /= fact[cnt]

    print ans