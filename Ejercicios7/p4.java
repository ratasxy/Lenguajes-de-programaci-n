import java.util.*

public class p4 {
    public static void main(String[] args) {
        int a = foo() + bar();
    }

    static int foo() {
        System.out.println("Esto va primero");
        return 0;
    }

    static int bar() {
        System.out.println("Esto va segundo");
        return 0;
    }
}
