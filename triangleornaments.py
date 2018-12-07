import sys
import math


def CalculateAngle(A, B, C):
    cosc = (A * A + B * B - C * C) / (2.0 * A * B)
    return math.acos(cosc)


def CalculateWidth(A, B, C):
    c = CalculateAngle(A, B, C)

    pA = (0.0, A)
    pB = (B * math.sin(c), B * math.cos(c))
    pC = (0.0, 0.0)

    centroidX = (pA[0] + pB[0] + pC[0]) / 3.0
    centroidY = (pA[1] + pB[1] + pC[1]) / 3.0

    cdist = math.hypot(centroidX, centroidY)
    rotationAngle = math.acos(centroidY / cdist)

    alength = A * math.sin(rotationAngle)
    blength = B * math.sin(c - rotationAngle)

    return alength + blength


lines = [line for line in sys.stdin]

ans = 0.0

for i in range(1, int(lines[0]) + 1):
    (A, B, C) = map(float, lines[i].split())
    ans += CalculateWidth(A, B, C)

print '%.15f' % ans

			