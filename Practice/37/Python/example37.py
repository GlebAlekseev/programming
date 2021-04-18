import math
from enum import IntEnum, auto
class coord_systems(IntEnum):
	Cartesian = auto() # 1
	Polar = auto() # 2

def equal(a, b, e=1E-10):
	if -e < a - b < e: return True
	else: return False

class Point:
	def __init__(self,a1=0,a2=0,coord_system=coord_systems.Cartesian):
		self.deviation = pow(10,-10)
		if type(a1) == str:
			xy = a1.replace('(','').replace(')','').split(',')
			self.x = float(xy[0])
			self.y = float(xy[1])
			self.r = math.hypot(float(xy[0]),float(xy[1]))
			self.phi = math.atan2(float(xy[1]),float(xy[0]))
		else:
			if coord_system == coord_systems.Cartesian: # Если Декартова
				self.x = a1 
				self.y = a2
				self.r = math.hypot(self.x,self.y)
				self.phi = math.atan2(self.y,self.x)
			else: # Если Полярная
				self.r = a1
				self.phi = a2
				self.x = self.r * math.cos(self.phi)
				self.y = self.r * math.sin(self.phi)

	def CartesianToPolar(self):
		self.r = math.hypot(self.x,self.y)
		self.phi = math.atan2(self.y,self.x)

	def PolarToCartesian(self):
		self.x = self.r * math.cos(self.phi)
		self.y = self.r * math.sin(self.phi)

	def __eq__(self, rhs):
		if abs(self.x - rhs.x)<self.deviation and abs(self.y - rhs.y)<self.deviation:
			return 1
		else:
			return 0
	def __ne__(self, rhs): 
		if abs(self.x - rhs.x)<self.deviation and abs(self.y - rhs.y)<self.deviation:
			return 0
		else:
			return 1

	def __str__(self):
		return "(" + str(self.x) + "," + str(self.y) + ")"
	def __repr__(self):
		return "(" + str(self.x) + "," + str(self.y) + ")"
	def get_x(self):
		return self.x
	def get_y(self):
		return self.y

	def get_r(self):
		return self.r
	def get_phi(self):
		return self.phi


	def set_x(self,x):
		self.x = x
		self.CartesianToPolar()

	def set_y(self,y):
		self.y = y
		self.CartesianToPolar()


	def set_r(self,r):
		self.r = r
		self.PolarToCartesian()
	def set_phi(self,phi):
		self.phi = phi
		self.PolarToCartesian()

class Vector:
	def __init__(self,begin=None,end=None):
		if type(begin) != Point and type(end) != Point:
			self.begin = Point(0,0)
			self.end = Point(1,0)
		elif type(begin) == Point and type(end) != Point:
			self.begin = Point(0.0)
			self.end = begin
		else:
			self.begin = begin
			self.end = end
		self.deviation = pow(10,-10)
		self.phi = math.atan2(self.end.get_y() - self.begin.get_y(),self.end.get_x() - self.begin.get_x())
	def __eq__(self, rhs):
		return (self.end.get_x() - self.begin.get_x()) - (rhs.end.get_x() - rhs.begin.get_x()) < self.deviation and (self.end.get_y() - self.begin.get_y()) - (rhs.end.get_y() - rhs.begin.get_y()) < self.deviation
	
	def __neg__(self): 
		return Vector(self.end,self.begin)


	def __add__(self, rhs): 
		return Vector(self.begin,Point(self.end.get_x() + rhs.end.get_x() - rhs.begin.get_x(),self.end.get_y() + rhs.end.get_y() - rhs.begin.get_y()))

	def __sub__(self, rhs):
		return Vector(self.begin,Point(self.end.get_x() - rhs.end.get_x() - rhs.begin.get_x(), self.end.get_y() - rhs.end.get_y() - rhs.begin.get_y()))
	def length(self):
		return math.hypot(self.end.x - self.begin.x, self.end.y - self.begin.y)

	def __mul__(self, rhs):
		if type(rhs) == Vector and type(self) == Vector:
			return	self.length() * rhs.length() * math.cos(self.phi-rhs.phi)
		else:
			return Vector(self.begin,Point(self.begin.get_x() + (self.end.get_x() - self.begin.get_x())*rhs, self.begin.get_y() + (self.end.get_y() - self.begin.get_y()) * rhs))

a = Vector(Point(1, 2))
b = Vector(Point(-2, 0), Point(-1, 2))
if a == b and b == a: print('Equality test passed')
else: print('Equality test failed')
na  = Vector(Point(-1, -2))
ox  = Vector(Point( 1,  0))
nox = Vector(Point(-1,  0))
oy  = Vector(Point( 0,  1))
noy = Vector(Point( 0, -1))
if a == -na and na == -a and -ox == nox and -oy == noy: print('Invert test passed')
else: print('Invert test failed')

if ox + oy + oy == a and -ox == -a + oy + oy: print('Summation test passed')
else: print('Summation test failed')
  
if -ox + oy == oy - ox and -oy + ox == ox - oy: print('Subtraction test passed')
else: print('Subtraction test failed')
  
if (ox * 3 == ox + ox + ox and
    oy * 3 == oy + oy + oy and
    ox * (-3) == -ox - ox - ox and
    oy * (-3) == -oy - oy - oy): print('Multiplication by number test passed')
else: print('Multiplication by number test failed')
  
if (equal(ox.length(), 1) and
    equal(oy.length(), 1) and
    equal((ox * 3 + oy * 4).length(), 5)): print('Length test passed')
else: print('Length test failed')
  
if (equal(ox*ox, ox.length()**2) and
    equal(oy*oy, oy.length()**2) and
    equal((ox*3 + oy*4)*(ox*3 + oy*4), (ox*3 + oy*4).length()**2)): print('Multiplication by Vector test passed')
else: print('Multiplication by Vector test failed')