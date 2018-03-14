#ifndef Cube_H
#define Cube_H
class Cube{
		private:
				double x,y,z;
		public:
				Cube();
				~Cube();
				void set_cube(int,int,int);
				friend double operator/(const Cube&,const Cube&);
				bool operator!=(const Cube&);
};
#endif
