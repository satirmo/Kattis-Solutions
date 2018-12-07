import sys
from sets import Set


def CheckMiddle(snum, val):
    for c in snum:
        if c != val:
            return False

    return True


def IsCreeper(num):
    snum = str(num)

    if len(snum) < 8:
        return False

    # print "checking", num, snum[ 0 : 4 ], snum[ -4 : ]

    if snum[0:4] == '1233' and snum[-4:] == '4444' \
        and CheckMiddle(snum[4:-4], '3'):
        return True

    if snum[0:4] == '5566' and snum[-4:] == '7777' \
        and CheckMiddle(snum[4:-4], '6'):
        return True

    return False


def UpdateNum(num):
    snum = str(num)[::-1]
    nnum = int(snum)

    tnum = num + nnum
    snum = ''.join(sorted(str(tnum)))

    return int(snum)


def GetVerdict(m, num):
    nums = Set([])

    for i in range(1, m + 1):

        # print i, len( nums ), num

        if IsCreeper(num):
            return ('C', i)
        elif num in nums:

            return ('R', i)

        if i == m:
            break

        nums.add(num)
        num = UpdateNum(num)

    return (num, )


lines = [line.replace('\n', '') for line in sys.stdin]

n = int(lines[0])

for test in range(1, n + 1):
    (t, m, num) = map(int, lines[test].split())

    result = GetVerdict(m, num)

    # print result

    if len(result) == 1:
        print '%d %d' % (t, result[0])
    else:

        print '%d %s %d' % (t, result[0], result[1])

			