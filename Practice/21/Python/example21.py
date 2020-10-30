


def bmi(weight: float, height: float):
	height = height / 100
	bmitog = weight / height**2
	return bmitog

def print_bmi(bmi: float):
	if (bmi < 18.5) :
		print("Underweight")
	
	elif (bmi >= 18.5 and bmi < 25):
		print("Normal")
	
	elif (bmi >= 25 and bmi < 30) :
		print("Overweight")
	
	elif (bmi > 30) :
		print("Obesity")
	
weight,height = map(str, input().split())
print_bmi(bmi(float(weight), float(height)))