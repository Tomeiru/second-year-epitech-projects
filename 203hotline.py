#!/usr/bin/env python3

import sys
import math
import time

def calcBinomial(n, k, p):
    ret = math.comb(n, k) * (p ** k) * ((1 - p) ** (n - k))
    return ret

def printOverloadAndTime(overload, compTime):
    print("Overload: {:.1f}%".format(overload))
    print("Computation time: {:.2f} ms".format(compTime))

def printInLoop(k, value):
    if (k + 1) % 5 == 0 or k == 50:
        print(str(k) + " -> " + "{:.3f}".format(value))
    elif (k < 10):
        print(str(k) + " -> " + "{:.3f}".format(value), end="      ")
    else:
        print(str(k) + " -> " + "{:.3f}".format(value), end="     ")

def hotlineBinomialDistr(p):
    print("Binomial distribution:")
    start = time.time()
    overload = 0
    for k in range(51):
        value = calcBinomial(3500, k, p)
        printInLoop(k, value)
        if k > 25:
            overload += value
    compTime = time.time() - start
    printOverloadAndTime(overload * 100, compTime * 1000)

def calcPoisson(k, λ):
    ret = ((λ ** k) / math.factorial(k)) * (math.exp(-λ))
    return ret

def hotlinePoissonDistr(p):
    print("Poisson distribution:")
    start = time.time()
    λ = 3500 * p
    overload = 0
    for k in range(51):
        value = calcPoisson(k, λ)
        printInLoop(k, value)
        if k > 25:
            overload += value
    compTime = time.time() - start
    printOverloadAndTime(overload * 100, compTime * 1000)

def hotlineDistr(av):
    duration = int(av[0])
    if duration < 0:
        raise
    p = duration / (8 * 3600)
    hotlineBinomialDistr(p)
    print()
    hotlinePoissonDistr(p)

def printComb(n, k, comb):
    print(str(k) + "-combinations of a set of size " + str(n) + ":\n" + str(comb))

def hotlineComb(av):
    n = int (av[0])
    k = int (av[1])
    if n < 0 or k < 0 or n < k:
        raise
    printComb(n, k, math.comb(n, k))

def usage():
    print("USAGE\n    ./203hotline [n k | d]\n\nDESCRIPTION\n    n      n value for the computation of C(n, k)\n    k      k value for the computation of C(n, k)\n    d      average duration of calls (in seconds)")
    return 0

def main(av):
    try:
        ac = len(av)
        if ac == 1 and av[0] == "-h":
            return (usage())
        if ac == 1:
            return (hotlineDistr(av))
        if ac == 2:
            return (hotlineComb(av))
        return 84
    except:
        return 84

if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))