number = int(input())
i = 0
kupuri = []
for i in range(number):
    kupura = input()
    if kupura.startswith('a') and kupura.endswith('55661'):
        kupuri.append(kupura)

if len(kupuri) == 0:
    print(-1)
else:
    print(' '.join(kupuri))
