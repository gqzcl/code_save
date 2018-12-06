public class Shell<T extends Comparable<T>> extends Sort<T>{
    @Override
    public void sort(T[] nums){
        int N=nums.length;
        int h=1;
        while(h<N/3){
            h=3*h+1;
        }
        while(h>=1){
            for(int i=h;i<N;i++){
                for(int j=i;j>=h&&less(nums[j],nums[j-h]);j-=h){
                    swap(nums,j,j-h);
                }
            }
            h=h/3;
        }
    }
    public static void main(String[] args) {
        Shell<Integer> S=new Shell<Integer>();
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