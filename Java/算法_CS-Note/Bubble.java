public class Bubble<T extends Comparable<T>> extends Sort<T>{
    @Override
    public void sort(T[] nums){
        int N=nums.length;
        boolean hasSorted=false;
        for(int i=N-1;i>0&&!hasSorted;i--){
            hasSorted=true;
            for(int j=0;j<i;j++){
                if(less(nums[j+1],nums[j])){
                    hasSorted=false;
                    swap(nums,j,j+1);
                }
            }
        }
    }
    public static void main(String[] args) {
        Bubble<Integer> S=new Bubble<Integer>();
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
