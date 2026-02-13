// File Name: q92035/CustomerTransactionStreams.java
package q92035;

import java.util.*;
import java.util.stream.*;

class Transaction {
    String customerId;
    Integer amount;
    String status;

    public Transaction(String customerId, Integer amount, String status) {
        this.customerId = customerId;
        this.amount = amount;
        this.status = status;
    }

    public String getCustomerId() {
        return customerId;
    }

    public Integer getAmount() {
        return amount;
    }

    public String getStatus() {
        return status;
    }
}

public class CustomerTransactionStreams {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Transaction> transactions = new ArrayList<>();

        // Read all transactions into ArrayList
        for (int i = 0; i < n; i++) {
            String cid = sc.next();
            Integer amount = sc.nextInt(); // Wrapper class usage
            String status = sc.next();
            transactions.add(new Transaction(cid, amount, status));
        }

        // Group transactions by customerId using TreeMap for ascending order
        Map<String, List<Transaction>> grouped = transactions.stream()
                .collect(Collectors.groupingBy(Transaction::getCustomerId, TreeMap::new, Collectors.toList()));

        // Process each customer
        grouped.forEach((customerId, transList) -> {
            // Total transaction amount (autoboxing used here)
            Integer totalAmount = transList.stream()
                    .collect(Collectors.summingInt(Transaction::getAmount));

            // Count successful transactions
            long successCount = transList.stream()
                    .filter(t -> t.getStatus().equals("SUCCESS"))
                    .count();

            // Count failed transactions
            long failedCount = transList.stream()
                    .filter(t -> t.getStatus().equals("FAILED"))
                    .count();

            // Print result in required format
            System.out.println(customerId + " " + totalAmount + " " + successCount + " " + failedCount);
        });
    }
}