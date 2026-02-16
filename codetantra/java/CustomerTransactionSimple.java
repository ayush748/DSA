import java.util.*;

class Transaction {
    String customerId;
    Integer amount;
    String status;

    public Transaction(String customerId, Integer amount, String status) {
        this.customerId = customerId;
        this.amount = amount;
        this.status = status;
    }
}

public class CustomerTransactionSimple {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Store all transactions in ArrayList
        List<Transaction> transactions = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String cid = sc.next();
            Integer amount = sc.nextInt(); // Wrapper class usage
            String status = sc.next();
            transactions.add(new Transaction(cid, amount, status));
        }

        // Use TreeMap to keep customerIds sorted automatically
        TreeMap<String, Integer> totalAmount = new TreeMap<>();
        TreeMap<String, Integer> successCount = new TreeMap<>();
        TreeMap<String, Integer> failedCount = new TreeMap<>();

        // Process transactions using simple loop
        for (Transaction t : transactions) {
            String cid = t.customerId;

            // Total amount
            totalAmount.put(cid, totalAmount.getOrDefault(cid, 0) + t.amount);

            // Count success and failed transactions
            if (t.status.equals("SUCCESS")) {
                successCount.put(cid, successCount.getOrDefault(cid, 0) + 1);
            } else {
                failedCount.put(cid, failedCount.getOrDefault(cid, 0) + 1);
            }
        }

        // Print result in ascending order of customerId
        for (String cid : totalAmount.keySet()) {
            System.out.println(cid + " " + totalAmount.get(cid) + " " +
                    successCount.getOrDefault(cid, 0) + " " +
                    failedCount.getOrDefault(cid, 0));
        }
    }
}