import math
def pattern1(n):
    for i in range(1, n+1):
        for j in range(1, n+1):
            print("*", end="\t")
        print("\n")    
def pattern2(n):
    for i in range(1, n+1):
        for j in range(1, i+1):
            print("*", end=" ")
        print("\n")    
def pattern3(n):
    for i in range(1, n+1):
        for j in range(1, i+1):
            print(j, end=" ")
        print("\n") 
def pattern4(n):
    for i in range(1, n+1):
        for j in range(i):
            print(i, end=" ")
        print("\n") 
def pattern5(n):
    for i in range(n, 0, -1):
        for j in range(i):
            print("*", end=" ")
        print()
def pattern6(n):
    for i in range(n, 0, -1):
        for j in range(1, i+1):
            print(j, end=" ")
        print()
def pattern7(n):
    for i in range(1, n+1):
        for j in range(n-i):
            print(" ", end="")
        for j in range(2*i-1):
            print("*", end="")
        print()
def pattern7_1(rows):
    for i in range(1, rows + 1):
        print(" " * (rows - i) + "*" * (2 * i - 1))
def pattern8(n):
    for i in range(n, 0, -1):
        for j in range(n-i):
            print(" ", end="")
        for j in range(2*i-1):
            print("*", end="")
        print()
def pattern9(n):
    pattern7(n)
    pattern8(n)
def pattern10(n):
    for i in range(1, 2*n):
        stars = i
        if i > n:
            stars= 2*n-i
        for j in range(1, stars+1):
            print("*", end="")
        print()
def pattern10_1(n):
    for i in range(1, 2*n):
        stars = i if i <= n else 2*n - i
        print("*" * stars)
def pattern11(n):
    for i in range(n):
        if i%2==0:
            start=1
        else:
            start=0
        for j in range(i+1):
            print(start, end="")
            start= 1-start
        print()
def pattern12(n):
    for i in range(1, n+1):
        for j in range(1, i+1):
            print(j, end="")
        for j in range(2*(n-i)):
            print(" ", end="")
        digit= i
        for j in range(i):
            print(digit, end="")
            digit-=1
        print()
def pattern13(n):
    num=1
    for i in range(n):
        for j in range(0, i+1):
            print(num, end=" ")
            num+=1
        print()
def pattern_diff(n):
    k= math.ceil(n/2)
    for i in range(1):
        for j in range(n-1):
            print(" ", end="")
        for j in range(n+2):
            print("e", end="")
        print()
    for i in range(n-1):
        for j in range(n-1):
            print(" ", end="")
        for j in range(0, 1):
            print("e", end="")
        for j in range(n):
            print(" ", end="")
        for j in range(0, 1):
            print("e", end="")
        print()
    for i in range(k, 0, -1):
        for j in range(k-i):
            print(" ", end="")
        for j in range(2*i-1):
            print("*", end="")
        print()
def pattern14(n):
    for i in range(1, n+1):
        for j in range(i):
            print(chr(65+j), end="")
        print()
def pattern14_1(n):
    for i in range(1, n+1):
        print("".join(chr(65+j) for j in range(i))) # chr(65+j) for j in range(i)) -> form a list of characters then, join() merge them in one string
def pattern15(n):
    for i in range(n, 0, -1):
        print("".join(chr(65+j) for j in range(i)))
def pattern15_1(n):
    temp=[]
    for i in range(n, 0, -1):
        for j in range(i):
            temp.append(chr(65+j))
        print("".join(temp))
        temp.clear()
def pattern16(n):
    for i in range(n):
        print("".join(chr(65+i) for j in range(0, i+1)))
def pattern17(n):
    for i in range(1, n+1):
        for j in range(n-i):
            print(" ", end="")
        val= i
        for j in range(2*i-1):
            if j >= i:
                val= val-1
                print(val, end="")
            else:
                print(j+1, end="")
        print()
def pattern17_1(n):
    for i in range(1, n+1):
        for j in range(n-i):
            print(" ", end="")
        val= 65+i-1
        for j in range(2*i-1):
            if chr(65+j) >= chr(65+i):
                val= val-1
                print(chr(val), end="")
            else:
                print(chr(65+j), end="")
        print()     
def pattern18(n):
    for i in range(1, n+1):
        for j in range(i):
            print(chr(65+n-i+j), end="")
        print()
def pattern19(n):
    spaces1= 0
    for i in range(n, 0, -1):
        print("*" * i + " " * spaces1 + "*" * i)
        spaces1+=2

    spaces2= 2*n-2
    for i in range(1, n+1):
        print("*" * i + " " * spaces2 + "*" * i)
        spaces2-=2
def pattern20(n):
    spaces2= 2*n-2
    for i in range(1, 2*n):
        stars= i
        if i > n:
            stars= 2*n-i
            if i == n+1:
                spaces2= 2
        print("*" * stars + " " * spaces2 + "*" * stars)
        if i<=n:
            spaces2-=2
        else:
            spaces2+=2
def pattern21(n):
    for i in range(n):
        for j in range(n):
            if i==0 or i==n-1 or j==0 or j==n-1:
                print("*", end="")
            else:
                print(" ", end="")
        print()
def pattern22(n):
    for i in range(2*n-1):
        for j in range(2*n-1):
            top= i
            left= j
            right= 2*n-2-j
            bottom= 2*n-2-i
            print(n-min(left, right, top, bottom), end="")
        print()
def fibonacci_pattern(n):
    # Generate fibonacci numbers up to n
    fib = [1, 1]
    for i in range(2, n):
        fib.append(fib[i-1] + fib[i-2])
    
    # Print pattern
    for i in range(n):
        spaces = n - i - 1
        print(" " * spaces + "*" * fib[i] + " " + "*" * fib[i])
def fibonacci_pattern1(n):
    # Generate fibonacci numbers
    fib = [1, 1]
    for i in range(2, n):
        fib.append(fib[i-1] + fib[i-2])
    
    # First row: common *
    print(" " * (n-1) + "*")
    
    # Remaining rows
    for i in range(1, n):
        spaces = n - i - 1
        left = "*" * fib[i]
        right = "*" * fib[i]
        print(" " * spaces + left + " " + right)


































































        




if __name__ == "__main__":
    N = int(input("Enter a no: "))    
    pattern_diff(N)
 

