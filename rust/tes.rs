use std::io;

fn main(){
	print!("Hello World!");
	let mut guess = String::new();
	io::stdin().read_line(&mut guess);
	println!("{}",guess);
}