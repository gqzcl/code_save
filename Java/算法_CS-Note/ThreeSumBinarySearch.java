import java.util.Scanner;
import java.util.Arrays;

public class ThreeSumBinarySearch{
    public int search(int[] nums,int target){
        int l=0,h=nums.length-1;
        while(l<=h){
            int m=(l+h)/2;
            if(target==nums[m]){
                return m;
            }else if(target>nums[m]){
                l=m+1;
            }else{
                h=m-1;
            }
        }
        return -1;
    }
    public int count(int[] nums){
        Arrays.sort(nums);
        int N=nums.length;
        
        int cnt=0;
        for(int i=0;i<N-1;i++){
            for(int j=i+1;j<N;j++){
                int target=-nums[i]-nums[j];
                    int index=search(nums,target);
                    if(index>j){                    
                        cnt++;
                    }
                }
            }
        return cnt;
    }
    public static void main(String[] args) {
        int length;
        Scanner sc=new Scanner(System.in);
        length=sc.nextInt();
        int[] nums=new int[length];
        ThreeSumBinarySearch ss=new ThreeSumBinarySearch();
        for(int i=0;i<length;i++){
            nums[i]=sc.nextInt();
        }
        System.out.println(ss.count(nums));
    }
}