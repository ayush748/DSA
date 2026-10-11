import java.util.Arrays;
class solution{
    public static int sortArr(int[] arr){
        Arrays.sort(arr);
        return arr[arr.length-1];
    }
}
public class Main{
    public static void main(String[] args){
        int[] arr1={1,2,3,4,6,7};
        System.out.println(solution.sortArr(arr1));
    }
}
