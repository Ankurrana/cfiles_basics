class Employee{
	String name;

	Employee(String n){
		this.name = name;
	}

	public static void main(){
		System.out.print("Hello");
	}
	
}


class Developer extends Employee{
	String speciality,language;
	Developer(String n,String s,String l){
		super(n);
		speciality = s;
		language = l;	
	}

	public void whois(){
		System.out.println("Hi, i am "+ name+". My Specialize in "+language);
	}
}


class hel{
	public static void main(String aa[]){
		Developer ankur = new Developer("Ankur rana","Algorithmatic Programming","C ,C++ and Java");
		ankur.whois();

	}
}