class A{
    public A(){
        System.out.println("Super class Constructor A");
    }
}
class B extends A{
    public B(){
        System.out.println("Sub-class constructor B");
    }
}
class constructorSequencingInJava{
    public static void main(String args[]){
        new B();
    }
}
/*
Output:
Super class Constructor A
Sub-class constructor B
*/
