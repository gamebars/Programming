def print_factorization(n: int) -> None:
   ans = [] 
   i = 2
   while (i * i < n): 
      if (n % i == 0):
         ans += [[i, 0]]; 
         while n % i == 0:
            n //= i 
            ans[len(ans)-1][1] += 1
      i += 1
   if n > 1: 
      ans += [[n, 1]] 
      
   sorted(ans, key=lambda pair: pair[0])
   
   i = 0
   for divider, count in ans:
      spec_char = '' if( i == 0 )else '*'; i += 1
      if count > 1:
         print(f'{spec_char}{divider}^{count}', end='')
      else:
         print(f'{spec_char}{divider}', end='')


n = int(input("Введите число: ")) 
print_factorization(n)