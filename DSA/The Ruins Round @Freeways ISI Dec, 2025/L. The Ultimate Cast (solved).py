a=int(input())
b=int(input())
c=int(input())
if a==b==c==1:
    print(3)
elif (a==b==1):
    print(2*c)
elif (b==c==1):
    print(2*a)
elif (a==1 and b!=1 and c!=1):
    print((a+b)*c)
elif (a!=1 and b!=1 and c==1):
    print(a*(b+c))
elif (a!=1 and b==1 and c!=1):
    print((min(a,c)+1)*max(a,c))
elif(a==1 and b!=1 and c==1):
    print(b+2)
else :
    print(a*b*c)
