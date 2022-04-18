import random
import os

length = 500
repeats = 15
numbers = list(range(1, length + 1))

os.system("make")

for i in range(repeats):
	numbers = [random.randint(-2147483648, 2147483647) for _ in range(length)]
	#numbers = [random.randint(-1000, 1000) for _ in range(length)]
	# random.shuffle(numbers)
	
	args = " ".join([str(x) for x in numbers])
	wcl = " | wc -l"
	os.system("./push_swap " + args + wcl)
	os.system("ARG=\"" + args + "\"; ./push_swap $ARG | ./checker_Mac $ARG")