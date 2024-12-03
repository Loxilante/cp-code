
def numberise(e):
    if '0' <= e and e <= '9':
        return ord(e)-ord('0')
    if 'A' <= e and e <= 'Z':
        return 10+ord(e)-ord('A')
    return 36+ord(e)-ord('a')

def charise(e):
    if (e < 10):
        return chr(ord('0')+e)
    if (e < 36):
        return chr(ord('A')+e-10)
    return chr(ord('a')+e-36)

a, b, c = map(str, input().split())
a = int(a)
b = int(b)

sum = 0
mul = 1
for ch in c[::-1]:
    sum += numberise(ch)*mul
    mul *= a

s = ""
while sum != 0:
    rem = sum%b
    sum = (sum-rem)//b
    s += charise(rem)

if (len(s) == 0):
    print(0)
else:
    print(s[::-1])
