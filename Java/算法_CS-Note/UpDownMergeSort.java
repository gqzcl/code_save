public class UpDownMergeSort<T extends Comparable<T>> extends MergeSort<T>{
    @Override
    public void sort(T[] nums){
        aux=(T[]) new Comparable[nums.length];
        sort(nums,0,nums.length-1);
    }
    public void sort(T[] nums,int l,int h){
        if(h<=1){
            return;
        }
        int mid=(h-1)/2;
        sort(nums,l,mid);
        sort(nums,mid+1,h);
        merge(nums,l,mid,h);
    }
    public static void main(String[] args) {
        UpDownMergeSort<Integer> S=new UpDownMergeSort<Integer>();
        Integer[] nums=new Integer[10];
        for(int i=0;i<10;i++){
            nums[i]=(int)(1000*Math.random());
        }
        S.sort(nums);
        for(int i=0;i<10;i++){
            System.out.println(nums[i]);
        }
    }
}