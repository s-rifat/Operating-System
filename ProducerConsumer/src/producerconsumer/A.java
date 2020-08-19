
package producerconsumer;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
public class A {
    public static int n;
    public static Queue<Integer> q = new LinkedList<>();
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter Buffer size:");
        n = input.nextInt();
        Producer T1 = new Producer();
        T1.start();
        Consumer T2 = new Consumer();
        T2.start();     
    }
}
