import math

# 1. count digits
def countDigits_brut(n): # O(log10N + 1)
    cnt = 0
    while n > 0:
        cnt += 1
        n //= 10
    return cnt
def countDigits_opti(n): # O(1)
    cnt = int(math.log10(n)+1)
    return cnt

# 2. reverse no.
def reverseNo(n): # O(log10N + 1)
    rn= 0
    while(n>0):
        ld= n%10
        rn= (rn*10)+ld
        n= n//10
    return rn

# 3. palindrome no.
def palindromeNo(n): # O(log10N + 1)
    rev = reverseNo(n)
    if n == rev:
        return "no. is palindrome"
    else:
        return "no. is not palindrome"

# 4. armstrong no.
def armstrongNo(n): # O(log10N + 1)
    size= len(str(n))
    sum=0
    dup=n
    while(n>0):
        ld=n%10
        sum+=ld**size
        n//=10
    if dup==sum:
        return True
    else:
        return False
        
# 5. prime no.
def primeNo(n): # O(N)
    cnt=0
    for i in range(1, n+1):
        if n%i == 0:
            cnt+=1
    if cnt == 2:
        return True
    else:
        return False






















if __name__ == "__main__":
    N = int(input("Enter a no: "))    
    print("N:", N)
    Output = primeNo(N)
    print("Output:", Output)
