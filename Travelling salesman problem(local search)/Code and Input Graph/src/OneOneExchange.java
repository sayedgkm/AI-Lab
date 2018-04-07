
import java.util.Collections;
import java.util.Random;


public class OneOneExchange {
    
    private static Random random = new Random(System.currentTimeMillis());
	public static Route apply(Route rt) 
	{
		Route route = new Route (rt);
                int n = route.n;
                Random rand = new Random();
                int  r1 = rand.nextInt(n);
                int r2=r1;
                while(r2==r1){
                    r2 = rand.nextInt(n);
                }
                Collections.swap(route.route , r1, r2);
		route.updateCost();
		return route;
	}
    
}
