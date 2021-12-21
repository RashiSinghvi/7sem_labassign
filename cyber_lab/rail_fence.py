def encryp(text,key):
	#build empty matrix
	rail = [['\n' for i in range(len(text))] for j in range(key)]

	dir_down=False
	row,col=0,0

	#fill matrix with text
	for i in range(len(text)):

		if( row == 0 or row == key-1):
			dir_down = not dir_down

		rail[row][col] = text[i]
		col += 1

		if dir_down:
			row +=1
		else:
			row -= 1

	#make list and get cipher text(read horizontally)
	result=[]
	for i in range(key):
		for j in range(len(text)):
			if(rail[i][j] != '\n'):
				result.append(rail[i][j])

	return("".join(result))


def decryp(cipher,key):
	#build empty matrix
	rail = [['\n' for i in range(len(cipher))] for j in range(key)]

	dir_down=None
	row,col=0,0

	#marks places with *
	for i in range(len(cipher)):
		if row==0:
			dir_down= True
		if row == key-1:
			dir_down= False

		rail[row][col] = '*'
		col +=1

		if dir_down:
			row +=1
		else:
			row -=1
	#fill places with cipher text
	index=0
	for i in range(key):
		for j in range(len(cipher)):
			if(rail[i][j]== "*" and index < len(cipher)):
				rail[i][j] = cipher[index]
				index +=1

	#read result matrix in zig zag manner
	result =[]
	dir_down= None
	row,col=0,0
	for i in range(len(cipher)):
		if row == 0:
			dir_down= True
		if row == key-1:
			dir_down = False

		if(rail[row][col] != "*"):
			result.append(rail[row][col])
			col +=1

		if dir_down:
			row += 1
		else:
			row -= 1

	return("".join(result))

text= input("enter your text: ")
key = int(input("enter key: "))
cipher  = encryp(text,key)
print("Cipher Text: ",cipher)
pt = decryp(cipher,key)
print("After Decryption")
print("Plain Text: ",pt)
