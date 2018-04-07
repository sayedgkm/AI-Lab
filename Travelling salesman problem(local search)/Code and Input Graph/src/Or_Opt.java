/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;



public class Or_Opt {
    
    /**
	 * improves the route by repeatedly applying the first better Or-opt move
	 * @param individual
	 * @param period
	 * @param vehicle
	 * @return false if cost is not decreased
 	 */
	public static Route apply(Route rt)
	{
            int n = rt.n;
            for(int chain_size= 3;chain_size>=1;chain_size--) {
                for(int i = 0;i+chain_size-1<n;i++) {
                    Route tmp;
                    List<Integer> list;
                    list = rt.route.subList(i, i+chain_size);
                    Route tmpRoute = new Route(rt);
                    int tot = chain_size;
                    while(tot>0){ tmpRoute.route.remove(i);tot--;}
                    tmpRoute.n= tmpRoute.route.size();
                    for(int j= 0;j<tmpRoute.route.size();j++) {
                        Route newRoute = new Route(tmpRoute);
                        newRoute.route.addAll(j, list);
                        newRoute.n = newRoute.route.size();
                        newRoute.updateCost();
                        if(newRoute.getCost()<rt.getCost()) return newRoute;
                    }
                    
                }
            }
            return rt;
	}
	
    
}
