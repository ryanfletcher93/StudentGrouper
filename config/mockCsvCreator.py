import random
import string

f = open("mockCsv10Student.csv", "w+")

numStudents = 15

for i in range(1,numStudents + 1):
	firstName = ''.join(random.choice(string.ascii_uppercase) for _ in range(3))
	middleName = ''.join(random.choice(string.ascii_uppercase) for _ in range(3))
	lastName = ''.join(random.choice(string.ascii_uppercase) for _ in range(3))
	
	internalLine = ""
	for j in range(6):
		randomInt = random.randint(1,numStudents)
		if randomInt == i:
			if randomInt == numStudents:
				randomInt -= 1
			else:
				randomInt += 1

		internalLine += ", " + str(randomInt)
		
	line = str(i) + ", " + firstName + "," + middleName + "," + lastName + str(internalLine) + "\n"
		
	f.write(line)
	
