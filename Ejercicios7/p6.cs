public class p6 {
    public static void Main() {
        int a = foo() + bar();
    }

    static int foo() {
        System.Console.WriteLine("Esto va primero");
        return 0;
    }

    static int bar() {
        System.Console.WriteLine("Esto va segundo");
        return 0;
    }
}
