a = "4567"
b = "9876"

def mul(a,b):
	if len(a)==1 and len(b)==1:
		return int(a)*int(b)
	else:
		x = a[0:len(a)/2]
		y = a[len(a)/2:]
		z = b[0:len(a)/2]
		zz = b[len(a)/2:]
		first = mul(str(y),str(zz))
		last = mul(str(x),str(z))*10**len(a)
		middle = mul(str(x+y),str(z+zz))
		return first+last+middle

mul(a,b)
		
		


