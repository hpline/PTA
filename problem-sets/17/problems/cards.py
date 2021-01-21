
a=[]
for e in ['S', 'H', 'C', 'D']:
    for i in range(1,14):
        a.append('"'+e+str(i)+'"')
a.append('"J1"')
a.append('"J2"')
for e in a:
    print(e,end=', ')