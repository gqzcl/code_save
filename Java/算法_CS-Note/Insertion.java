public class Insertion<T extends Comparable<T>> extends Sort<T>{
    @Override
    public void sort(T[] nums){
        int N=nums.length;
        for(int i=1;i<N;i++){
            for(int j=i;j>0&&less(nums[j],nums[j-1]);j--){
                swap(nums,j,j-1);
            }
        }
    }
    public static void main(String[] args) {
        Insertion<Integer> S=new Insertion<Integer>();
        Integer[] nums=new Integer[1000];
        for(int i=0;i<1000;i++){
            nums[i]=(int)(1000*Math.random());
        }
        S.sort(nums);
        for(int i=0;i<1000;i++){
            System.out.println(nums[i]);
        }
    }
}