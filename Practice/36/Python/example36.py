import math
import copy

from enum import IntEnum, auto
class coord_systems(IntEnum):
	Cartesian = auto() # 1
	Polar = auto() # 2
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

	def __eq__(self, rhs): #
		if abs(self.x - rhs.x)<self.deviation and abs(self.y - rhs.y)<self.deviation:
			return 1
		else:
			return 0
	def __ne__(self, rhs): #	
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

with open('data.txt') as fin:
    original = [Point(p) for p in fin.readline().split(', ')]
  
simulacrum = copy.deepcopy(original)
for p in simulacrum:
    print(p, end='')
    p.set_x(p.get_x() + 10)
    p.set_phi(p.get_phi() + 180*math.pi/180)
    p.set_y(-p.get_y())
    p.set_x(-p.get_x() - 10)
    print(p)
  
print('\nIt works!\n' if simulacrum == original else '\nIt not works!\n')