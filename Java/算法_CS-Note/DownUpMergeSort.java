public class DownUpMergeSort<T extends Comparable<T>> extends MergeSort<T>{
    @Override
    public void sort(T[] nums){
        int N=nums.length+1;
        aux=(T[]) new Comparable[N];
        for(int sz=1;sz<N&&sz+sz<N;sz+=sz){
            for(int lo=0;lo<N-sz&&lo+sz+sz<N;lo+=sz+sz){
                merge(nums,lo,lo+sz-1,Math.min(lo+sz+sz-1,N-1));
            }
        }
    }
    public static void main(String[] args) {
        DownUpMergeSort<Integer> S=new DownUpMergeSort<Integer>();
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