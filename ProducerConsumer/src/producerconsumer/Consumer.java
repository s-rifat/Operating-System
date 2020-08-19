
package producerconsumer;
import java.util.logging.Level;
import java.util.logging.Logger;
class Consumer extends Thread {
    @Override
    public void run() {
        try {
            consume();
        } catch (InterruptedException ex) {
            Logger.getLogger(Consumer.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    public void consume() throws InterruptedException {
        do {
            synchronized (A.q) {
                while (A.q.isEmpty()) {
                    A.q.wait();
                }
                int data = A.q.remove();
                System.out.println("Data " + data + " is consumed from the buffer");
                System.out.println("Empty Space: " + (A.n - A.q.size()));
                A.q.notify();
                Thread.sleep(1000);
            }
        } while (true);
    }
}