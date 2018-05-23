import java.lang.*;

class A implements Runnable{
	private int a;
	public A(int b){
		a = b;
	}
	public void run() {
        print();
    }
	public void print(){
		System.out.println("wew");
		System.out.println("waw");
		System.out.println(a++);
		System.out.println("wiw");
	}
}

public class tes{
	public static void main(String[] args){
		A a = new A(1);
		Thread t = new Thread(a);
		Thread s = new Thread(a);
		t.start();
		s.start();
		try{
		t.join();
		s.join();
		}
		catch(Exception e){
			
		}
	}
}