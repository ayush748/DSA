package linear;

import java.util.*;
class solution{
    public static int sortArr(int[] arr){
        Arrays.sort(arr);
        return arr[arr.length-1];
    }
}
public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println(solution.sortArr(arr));
        sc.close();
    }
}
