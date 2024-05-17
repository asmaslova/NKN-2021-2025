public class Educated {
    public static void main(String[] args) {
        AI start = new AI(new float [] {0,1,1,1,-200});
        AI best = start;
        int res = result(start);
        while (res < 1000000){
            for(int i = 0; i < 400; i++) {
                AI children = new AI(start, 20f);
                int child_res = result(children);
                if (child_res > res){
                    best = children;
                    res = child_res;
                }
            }
            start = best;
            start.output();
            System.out.println(res);


        }


    }
    static int result (AI ai){
        int res = 0;
        for (int i = 0; i < 10; i++)
            res += new Simulator().run(ai);
        return  res/10;
    }

}
