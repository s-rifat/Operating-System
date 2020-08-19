
package producerconsumer;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import static producerconsumer.A.n;
class Producer extends Thread {
    Scanner input = new Scanner(System.in);
    @Override
    public void run() {
        try {
            produce();
        } catch (InterruptedException ex) {
            Logger.getLogger(Producer.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    public void produce() throws InterruptedException {
        int data = 0;
        while (true) {
            synchronized (A.q) {
                while (A.q.size() == n) {
                    A.q.wait();
                }        
                System.out.println("Data to insert in the Buffer");
                System.out.print("Data: ");
                data = input.nextInt();
                A.q.add(data);
                System.out.println("Data " + data + " is inserted in the buffer");
                System.out.println("Full Space: " + (A.q.size()));             
                A.q.notify();
                Thread.sleep(1000);
            }
        }
    }
}