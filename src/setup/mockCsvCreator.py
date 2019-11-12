import random
import string

f = open("mockCsv.csv", "w+")

for i in range(1,121):
	firstName = ''.join(random.choice(string.ascii_uppercase) for _ in range(3))
	middleName = ''.join(random.choice(string.ascii_uppercase) for _ in range(3))
	lastName = ''.join(random.choice(string.ascii_uppercase) for _ in range(3))
	
	internalLine = ""
	for j in range(6):
		randomInt = random.randint(1,120)
		if randomInt == i:
			if randomInt == 120:
				randomInt -= 1
			else:
				randomInt += 1

		internalLine += ", " + str(randomInt)
		
	line = firstName + "," + middleName + "," + lastName + "," + str(i) + str(internalLine) + "\n"
		
	f.write(line)
	
