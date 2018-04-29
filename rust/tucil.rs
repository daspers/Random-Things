/*// Assignment Operator and Copy Constructor
#[derive (Clone, Copy)]
struct Class {
	field1 : Type1,
	field2 : Type2,
}

impl Class{
	// Constructor
	pub fn new(field1in : Type1, field2in : Type2) -> Self {
		Class(field1 : field1in, field2 : field2in)
	}
}

// Destructor
impl Drop for Class{
	fn drop(&mut Self){
		// Destroying field
	}
}

// Inheritance
trait Function {
	fn testfunc(& Self);
	...
}

struct Parent {
	...
}

impl Function for Parent{
	fn testfunc(& Self){
		// do something
	}
	...
}

struct Child {
	parent: Parent,
	...
}

impl Function for Child{
	fn testfunc(& Self){
		Self.parent.testfunc();	// call parent method
		// do something
	}
	...
}*/

trait PointFunction{
	fn getX(&self) -> f64;
	fn getY(&self) -> f64;
	fn to_origin(&mut self);
	fn print(&self);
	fn setX(&mut self, x : f64);
	fn setY(&mut self, y : f64);
}

#[derive (Clone, Copy)]
struct Point2D {
	x : f64,
	y : f64
}

impl Point2D{
	fn new(x : f64, y : f64) -> Self{
		Point2D{x : x, y : y}
	}
	fn distance_to(&self, other : &Point2D) -> f64 {
		let dx = self.x - other.x;
		let dy = self.y - other.y;
		dx*dx - dy*dy
	}
}

impl PointFunction for Point2D {
	fn getX(&self) -> f64 {
		self.x
	}
	fn getY(&self) -> f64 {
		self.y
	}
	fn to_origin(&mut self) {
		self.x = 0.0;
		self.y = 0.0;
	}
	fn print(&self){
		println!("x : {:?}", self.x);
		println!("y : {:?}", self.y);
	}
	fn setX(&mut self, x : f64){
		self.x = x;
	}
	fn setY(&mut self, y : f64){
		self.y = y;
	}
}

#[derive (Clone, Copy)]
struct Point3D {
	parent : Point2D,
	z : f64
}

impl Point3D{
	fn new(x : f64, y : f64, z : f64) -> Self{
		Point3D{parent : Point2D::new(x, y), z : z}
	}
	fn getZ(&self) -> f64 {
		self.z
	}
	fn distance_to(&self, other : &Point3D) -> f64 {
		let dx = self.parent.getX() - other.parent.getX();
		let dy = self.parent.getY() - other.parent.getY();
		let dz = self.z - other.z;
		dx*dx + dy*dy + dz*dz
	}
	fn setZ(&mut self, z : f64){
		self.z = z;
	}
}

impl PointFunction for Point3D {
	fn getX(&self) -> f64 {
		self.parent.getX()
	}
	fn getY(&self) -> f64 {
		self.parent.getY()
	}
	fn to_origin(&mut self) {
		self.parent.to_origin();
		self.z = 0.0;
	}
	fn print(&self){
		self.parent.print();
		println!("z : {:?}", self.z);
	}
	fn setX(&mut self, x : f64){
		self.parent.setX(x);
	}
	fn setY(&mut self, y : f64){
		self.parent.setY(y);
	}
}

fn main(){
	let mut a = Point3D::new(2.0, 3.0, 4.5);
	
}