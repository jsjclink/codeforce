from sympy import primerange

limit = 10000000

primes = list(primerange(1, limit))[:400000]
print(primes)
# cumulative_sum = []
# cur_sum =0
# for p in primes:
#     cur_sum += p
#     cumulative_sum.append(cur_sum)
# print(cumulative_sum)