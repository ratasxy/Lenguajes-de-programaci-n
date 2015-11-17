public class Ejercicio2 {

    public static void main(String[] args) {
        
	int sum1, sum2;

	JSNumber i = new JSNumber(10);
	JSNumber j = new JSNumber(10); 
 
 	sum1 = (i.number/2) + fun(i);
	sum2 = fun(j) + (j.number/2);       
        System.out.println("Sum1: " + sum1);
	System.out.println("Sum2: " + sum2);
    }

    public static int fun(JSNumber k)
    {
	k.number += 4;
	return 3 * k.number - 1;
    }

}

class JSNumber
{
	public int number;

	public JSNumber(int n)
	{
		number = n;
	}
}
