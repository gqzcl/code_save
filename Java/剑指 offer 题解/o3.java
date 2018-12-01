import java.util.Scanner;

public class o3{
    public boolean duplicate(int[] nums,int length,int[] duplication){
        if(nums==null||length<=0)
            return false;
        for(int i=0;i<length;i++){
            while(nums[i]!=i){
                if(nums[i]==nums[nums[i]]){
                    duplication[0]=nums[i];
                    return true;
                }
                swap(nums,i,nums[i]);
            }
        }
        return false;
    }
    private void swap(int[] nums,int i,int j){
        int t=nums[i];
        nums[i]=nums[j];
        nums[j]=t;
    }
    public static void main(String[] args){
        int length;
        o3 o3=new o3();
        Scanner sc=new Scanner(System.in);
        length=sc.nextInt();
        int[] nums=new int[length];
        int[] answer=new int[1];
        for(int i=0;i<length;i++){
            nums[i]=sc.nextInt();
        }
        if(o3.duplicate(nums,length,answer))
            System.out.println(answer[0]);
        else
            System.out.println("fit");
    }
}