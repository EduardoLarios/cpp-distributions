'''

    Copyright 2019 © Ramón Romero @ramonromeroqro
    A01700318 for ITESM
    Python - Von Newman - Random Integer Generator
    V050220191400


    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.


'''
import math
def randn(sliced, first, it, s):
	r=int(sliced)**2
	sliced=str(r)
	mid=len(sliced)//2
	it=it+1
	sliced=sliced[mid-2:mid+2]
	if float(sliced)==float(0) or float(sliced)==float(first) or sliced in s:
		print("iterations->\t"+ str(it))
		#x = lambda a: -1*(math.log(1-a))/(1) #-ln(1-Ri)/lambda(1)
		#print(x(it))
		return sliced
	
	else:
		s.add(sliced)
		print(sliced)
		return randn(sliced, first, it, s) 	
		


if __name__ == "__main__":

    num=float(input())
    a=set()
    randn(num, num, 0, a)
    
